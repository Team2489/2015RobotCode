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
	Robot::chassis->m_frontLeftMotorPID->Enable();
	Robot::chassis->m_frontRightMotorPID->Enable();
	Robot::chassis->m_backRightMotorPID->Enable();
	Robot::chassis->m_backLeftMotorPID->Enable();
}

// Called repeatedly when this Command is scheduled to run
void CenterOnTote::Execute()
{
	std::cout << "Distance: " << Robot::tc->GetDistance() << std::endl;
//	if(Robot::tc->GetDistance() < -10) {
//		Robot::chassis->MecanumDrive_Cartesian(.4,0,0);
//		if (Robot::tc->GetDistance() > -25) {
//			Robot::chassis->MecanumDrive_Cartesian(.3,0,0);
//		}
		Robot::chassis->m_frontLeftMotorPID->SetSetpoint(1000);
		Robot::chassis->m_backLeftMotorPID->SetSetpoint(-1000);
		Robot::chassis->m_frontRightMotorPID->SetSetpoint(1000);
		Robot::chassis->m_backRightMotorPID->SetSetpoint(-1000);

//		std::cout << "FL: " << Robot::chassis->m_frontLeftMotorPID->GetError() << std::endl;
//		std::cout << "FR: " << Robot::chassis->m_frontRightMotorPID->GetError() << std::endl;
//		std::cout << "BL: " << Robot::chassis->m_backLeftMotorPID->GetError() << std::endl;
//		std::cout << "BR: " << Robot::chassis->m_backRightMotorPID->GetError() << std::endl;
//
		std::cout << "FL: " << Robot::chassis->m_frontLeftEncoder->GetRate() << std::endl;
		std::cout << "FR: " << Robot::chassis->m_frontRightEncoder->GetRate() << std::endl;
		std::cout << "BL: " << Robot::chassis->m_backLeftEncoder->GetRate() << std::endl;
		std::cout << "BR: " << Robot::chassis->m_backRightEncoder->GetRate() << std::endl;

//	} else if (Robot::tc->GetDistance() > 10){
////		Robot::chassis->MecanumDrive_Cartesian(-.4,0,0);
////		if (Robot::tc->GetDistance() > -25) {
////			Robot::chassis->MecanumDrive_Cartesian(-.3,0,0);
////		}
//		Robot::chassis->m_frontLeftMotorPID->SetSetpoint(380);
//		Robot::chassis->m_backLeftMotorPID->SetSetpoint(-380);
//		Robot::chassis->m_frontRightMotorPID->SetSetpoint(-380);
//		Robot::chassis->m_backRightMotorPID->SetSetpoint(380);
//	} else {
////		Robot::chassis->MecanumDrive_Cartesian(0,0,0);
//		Robot::chassis->m_frontLeftMotorPID->SetSetpoint(0);
//		Robot::chassis->m_backLeftMotorPID->SetSetpoint(0);
//		Robot::chassis->m_frontRightMotorPID->SetSetpoint(0);
//		Robot::chassis->m_backRightMotorPID->SetSetpoint(0);
//
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool CenterOnTote::IsFinished()
{
	return anyMotion();
}

// Called once after isFinished returns true
void CenterOnTote::End()
{
	Robot::chassis->m_frontLeftMotorPID->Disable();
	Robot::chassis->m_frontRightMotorPID->Disable();
	Robot::chassis->m_backRightMotorPID->Disable();
	Robot::chassis->m_backLeftMotorPID->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CenterOnTote::Interrupted()
{
	End();
}

bool CenterOnTote::anyMotion() {
	Joystick *leftJoystick = Robot::oi->getm_rightJoystick();
	Joystick *rightJoystick = Robot::oi->getm_leftJoystick();

	return ((abs(leftJoystick->GetX()) > .1) || (abs(leftJoystick->GetY()) > .1) ||
			(abs(rightJoystick->GetX()) > .1) || (abs(rightJoystick->GetY()) > .1) || leftJoystick->GetRawButton(STOPALIGNBUTTON));
}
