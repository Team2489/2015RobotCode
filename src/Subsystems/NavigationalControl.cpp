#include "NavigationalControl.h"
#include "../RobotMap.h"


void NavigationalControl::MainLoop(void *ptr)
{
	NavigationalControl *c = (NavigationalControl *) ptr;
	c->Run();
}

void NavigationalControl::CalibrateLoop(void *ptr)
{
	NavigationalControl *c = (NavigationalControl *) ptr;
	c->CalibrateRun();
	c->ZeroVelocity();
}

void NavigationalControl::CalibrateRun()
{
	time_t startTime;
	time(&startTime);
	double baseAverage = 0;
	double samples = 0;
	while(time(0)-startTime < 2) {
		double currReading = m_accelerometer->GetX();
		if (abs(currReading) < 0.2) {
			baseAverage += currReading;
			samples++;
		}
//		std::cout << currReading << std::endl;
	}
	pthread_mutex_lock(&data_mutex);
	m_initialAccelerometerReading = baseAverage/samples;
	std::cout << m_initialAccelerometerReading << std::endl;
	pthread_mutex_unlock(&data_mutex);
}

void NavigationalControl::Run() {
	time(&m_prevTime);
	time_t currTime;
	while(true) {
		pthread_mutex_lock(&data_mutex);
		time(&currTime);
		m_xVelocity += (m_accelerometer->GetX()-m_initialAccelerometerReading)*difftime(currTime, m_prevTime);
		m_prevTime = currTime;
		pthread_mutex_unlock(&data_mutex);
//		std::cout << "X Velocity: " << m_xVelocity << "X accel: " << m_accelerometer->GetX()-m_initialAccelerometerReading << std::endl;
	}
}


NavigationalControl::NavigationalControl() :
		Subsystem("ExampleSubsystem")
{
	m_accelerometer = RobotMap::navigationalAccelerometer;
	m_xVelocity = 0;
	m_yVelocity = 0;
	m_initialAccelerometerReading = 0;
	pthread_mutex_init(&data_mutex, NULL);
	time(&m_prevTime);

	m_calibrateTask = new Task("2489Calibration", (FUNCPTR)CalibrateLoop);
	m_calibrateTask->Start((uint32_t)this);

	m_task = new Task("2489NavigationalControl", (FUNCPTR)MainLoop);
	m_task->Start((uint32_t)this);


}

void NavigationalControl::ZeroVelocity() {
	m_xVelocity=0;
}

void NavigationalControl::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

NavigationalControl::~NavigationalControl() {
	if(m_accelerometer) {delete(m_accelerometer);}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
