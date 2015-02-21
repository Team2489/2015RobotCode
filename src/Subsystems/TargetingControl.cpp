#include "TargetingControl.h"
#include "../RobotMap.h"

TargetingControl::TargetingControl() : Subsystem("TargetingControl") {
	printf(__FUNCTION__);
	m_vc = new VisionClient();
	m_vc->Start();
}

void TargetingControl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
double TargetingControl::GetDistance() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	double d = 0;
	int dstate = 0;
	m_vc->GetState(&d, &dstate);
	return d;
}

TargetingControl::~TargetingControl() {
	if(m_vc) {delete(m_vc);}
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
