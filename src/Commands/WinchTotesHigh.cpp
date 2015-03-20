#include "WinchTotesHigh.h"

WinchTotesHigh::WinchTotesHigh(double totesHigh)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::winch);
	m_totesHigh = totesHigh;
}

// Called just before this Command runs the first time
void WinchTotesHigh::Initialize()
{
	Robot::winch->m_totesHighPID->SetOutputRange(-0.5,0.5);

	Robot::winch->m_totesHighPID->Enable();
	Robot::winch->m_totesHighPID->SetSetpoint(WINCH_PULSES_PER_TOTE*(-m_totesHigh));
}

// Called repeatedly when this Command is scheduled to run
void WinchTotesHigh::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WinchTotesHigh::IsFinished()
{
	return Robot::winch->m_totesHighPID->OnTarget();
}

// Called once after isFinished returns true
void WinchTotesHigh::End()
{
	Robot::winch->m_totesHighPID->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchTotesHigh::Interrupted()
{
	End();
}
