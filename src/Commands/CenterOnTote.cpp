#include "CenterOnTote.h"
#include "../Robot.h"
#include "../Subsystems/Chassis.h"
#include "OI.h"

CenterOnTote::CenterOnTote()
{
	m_isFinished = false;
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::tc);
	Requires(Robot::chassis);
}

// Called just before this Command runs the first time
void CenterOnTote::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CenterOnTote::Execute()
{
	std::cout << "Distance: " << Robot::tc->GetDistance() << std::endl;
	if(Robot::tc->GetDistance() < -10) {
		Robot::chassis->MecanumDrive_Cartesian(.4,0,0);
		if (Robot::tc->GetDistance() > -25) {
			Robot::chassis->MecanumDrive_Cartesian(.3,0,0);
		}
	} else if (Robot::tc->GetDistance() > 10){
		Robot::chassis->MecanumDrive_Cartesian(-.4,0,0);
		if (Robot::tc->GetDistance() > -25) {
			Robot::chassis->MecanumDrive_Cartesian(-.3,0,0);
		}
	} else {
		Robot::chassis->MecanumDrive_Cartesian(0,0,0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CenterOnTote::IsFinished()
{
	return anyMotion();
}

// Called once after isFinished returns true
void CenterOnTote::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CenterOnTote::Interrupted()
{

}

bool CenterOnTote::anyMotion() {
	Joystick *leftJoystick = Robot::oi->getm_rightJoystick();
	Joystick *rightJoystick = Robot::oi->getm_leftJoystick();

	return ((abs(leftJoystick->GetX()) > .1) || (abs(leftJoystick->GetY()) > .1) ||
			(abs(rightJoystick->GetX()) > .1) || (abs(rightJoystick->GetY()) > .1) || leftJoystick->GetRawButton(STOP_ALIGN_BUTTON));
}
