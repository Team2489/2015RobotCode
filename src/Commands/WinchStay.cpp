#include "WinchStay.h"

WinchStay::WinchStay()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::winch);
}

// Called just before this Command runs the first time
void WinchStay::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WinchStay::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WinchStay::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WinchStay::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchStay::Interrupted()
{

}
