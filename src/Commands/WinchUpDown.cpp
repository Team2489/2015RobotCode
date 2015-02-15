#include "WinchUpDown.h"
#include "../Robot.h"
#include "../Subsystems/Winch.h"

WinchUpDown::WinchUpDown(bool isUp, double timeout)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::winch);
	m_isUp = isUp;
	m_timeout = timeout;
}

// Called just before this Command runs the first time
void WinchUpDown::Initialize()
{
	if (m_timeout) {
		SetTimeout(m_timeout);
	}
}

// Called repeatedly when this Command is scheduled to run
void WinchUpDown::Execute()
{
	if(m_isUp) {
		Robot::winch->MoveUp();
	} else {
		Robot::winch->MoveDown();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool WinchUpDown::IsFinished()
{
	if(m_timeout) {
		return IsTimedOut();
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void WinchUpDown::End()
{
	Robot::winch->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchUpDown::Interrupted()
{
	Robot::winch->Stop();
}
