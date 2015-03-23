#include "MoveSideways.h"

MoveSideways::MoveSideways(double rate, double timeout, bool isLeft)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::chassis);
	m_timeout = timeout;
	m_rate = rate;
	m_isLeft = isLeft;
}

// Called just before this Command runs the first time
void MoveSideways::Initialize()
{
	if(m_timeout) {
		SetTimeout(m_timeout);
	}
	Robot::chassis->m_frontLeftMotorPID->Enable();
	Robot::chassis->m_frontRightMotorPID->Enable();
	Robot::chassis->m_backRightMotorPID->Enable();
	Robot::chassis->m_backLeftMotorPID->Enable();

	if(!m_isLeft) {
		Robot::chassis->m_frontLeftMotorPID->SetSetpoint(m_rate);
		Robot::chassis->m_backLeftMotorPID->SetSetpoint(-m_rate);
		Robot::chassis->m_frontRightMotorPID->SetSetpoint(m_rate);
		Robot::chassis->m_backRightMotorPID->SetSetpoint(-m_rate);
	} else {
		Robot::chassis->m_frontLeftMotorPID->SetSetpoint(-m_rate);
		Robot::chassis->m_backLeftMotorPID->SetSetpoint(m_rate);
		Robot::chassis->m_frontRightMotorPID->SetSetpoint(-m_rate);
		Robot::chassis->m_backRightMotorPID->SetSetpoint(m_rate);
	}
}

// Called repeatedly when this Command is scheduled to run
void MoveSideways::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool MoveSideways::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void MoveSideways::End()
{
	Robot::chassis->m_frontLeftMotorPID->Disable();
	Robot::chassis->m_frontRightMotorPID->Disable();
	Robot::chassis->m_backRightMotorPID->Disable();
	Robot::chassis->m_backLeftMotorPID->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveSideways::Interrupted()
{
	End();
}
