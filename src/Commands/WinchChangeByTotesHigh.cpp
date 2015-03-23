#include "WinchChangeByTotesHigh.h"

WinchChangeByTotesHigh::WinchChangeByTotesHigh(int toteHeight)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::winch);
	m_totesHigh = toteHeight;
}

// Called just before this Command runs the first time
void WinchChangeByTotesHigh::Initialize()
{
	Robot::winch->m_totesHighPID->Enable();
	Robot::winch->m_totesHighPID->SetSetpoint(Robot::winch->m_encoder->PIDGet() + m_totesHigh);
}

// Called repeatedly when this Command is scheduled to run
void WinchChangeByTotesHigh::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WinchChangeByTotesHigh::IsFinished()
{
	return Robot::winch->m_totesHighPID->OnTarget();
}

// Called once after isFinished returns true
void WinchChangeByTotesHigh::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchChangeByTotesHigh::Interrupted()
{

}
