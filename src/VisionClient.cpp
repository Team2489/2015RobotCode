#include "VisionClient.h"
#include "RobotMap.h"
#include <Timer.h>
#include <iostream>


static const unsigned int debug = 0;

using namespace std;

void VisionClient::MainLoop(void *ptr)
{
	if (debug) {
		cout << "VisionClient::MainLoop" << endl;
	}
	VisionClient *c = (VisionClient *) ptr;
	c->Run();
}

void VisionClient::Run(void)
{
	double d;
	int r;

	if (debug) {
		cout << "VisionClient::Run m_enabled = " << m_enabled << endl;
	}
	while (m_enabled)
	{
		// supposedly we are reading these values from network
		// insert real code here; note this code may block on
		// network operations
				directions direc;
		
		if (client->IsConnected()){
			if (debug) {
				cout << "Client is reading." << endl;
			}
			client->Send(TCPClient::PULL);
			client->Receive(&direc);
		}
		else {
			if (debug) {
				cout << "Client is connecting." << endl;
			}
			client->Connect();
			direc.status = -1;
		}
		
		r = direc.status;
	    d = direc.diterror;

	    UpdateState(r, d);
	    if (debug) {
	    	cout  << "Run r = " << r << endl;
	    	cout  << "Run d = " << d << endl;
	    }
		Wait(0.1);
	}
	if (debug) {
		cout << "VisionClient::Run Exiting" << endl;
	}
}

void VisionClient::Start(void)
{
	if (debug) {
		cout << "VisionClient::Start" << endl;
	}
	m_enabled = true;
	m_task->Start((UINT32)this);
}


void VisionClient::Stop(void)
{
	m_enabled = false;
}

VisionClient::VisionClient(void)
{
	if (debug) {
		cout << "VisionClient::VisionClient" << endl;
	}
	m_enabled = true;
	pthread_mutex_init(&data_mutex, NULL);
	m_task = new Task("2489VisionClient", (FUNCPTR)MainLoop);
	m_retval = 0;
	m_distance = 0;

	if(TESTERBOT) {
		client = new TCPClient("10.98.42.5");
	} else {
		client = new TCPClient("10.24.89.5");
	}

	cout << "VisionClient::VisionClient: m_enabled = " << m_enabled << endl;
}


void VisionClient::UpdateState(int r,  double d){
	if (debug) {
		cout << "VisionClient::UpdateState" << endl;
	}
	pthread_mutex_lock(&data_mutex);
	{
		// really quick - just update our state
		m_distance = d;
		m_retval = r;
	}
	pthread_mutex_unlock(&data_mutex);
}

int VisionClient::GetState( double *d, int *dstate)
{
	if (debug) {
		cout << "VisionClient::GetState" << endl;
	}
	int ret;
	pthread_mutex_lock(&data_mutex);
	{
		// really quick - just get our state
		*d = m_distance;
		ret = m_retval;
	}
	pthread_mutex_unlock(&data_mutex);
	if (debug) {
		cout  << "getstate *d = " << *d << endl;
		cout  << "getstate ret = " << ret << endl;
	}
	return ret;
}


VisionClient::~VisionClient()
{
	m_task->Stop();
	m_task = NULL;
}
