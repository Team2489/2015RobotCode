#include "TargetingControl.h"
#include "../RobotMap.h"

TargetingControl::TargetingControl() : Subsystem("TargetingControl") {
	printf(__FUNCTION__);
	vc = new VisionClient();
	vc->Start();
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
	double d;
	int dstate;
	vc->GetState(&d, &dstate);
	return d;
}

TargetingControl::~TargetingControl() {
	if(vc) {delete(vc);}
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
