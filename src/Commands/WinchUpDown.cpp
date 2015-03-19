#include "WinchUpDown.h"
#include "../Robot.h"
#include "../Subsystems/Winch.h"

WinchUpDown::WinchUpDown(bool isUp, double timeout, double power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::winch);
	m_isUp = isUp;
	m_timeout = timeout;
	m_power = power;
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
	int temp_power = m_power;

	if(m_isUp) {
		Robot::winch->MoveUp(temp_power);
	} else {
		Robot::winch->MoveDown(temp_power);
	}
	if (temp_power == 0) {
		temp_power = Robot::oi->GetElevatorPower();
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
