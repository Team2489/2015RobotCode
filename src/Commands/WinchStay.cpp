#include "WinchStay.h"

WinchStay::WinchStay()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::winch);
}

// Called just before this Command runs the first time
void WinchStay::Initialize()
{
	Robot::winch->m_encoder->SetPIDSourceParameter(Encoder::kRate);
	Robot::winch->m_balancePID->Enable();
	Robot::winch->m_balancePID->SetSetpoint(0);
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
	Robot::winch->m_balancePID->Disable();
	Robot::winch->m_encoder->SetPIDSourceParameter(Encoder::kDistance);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchStay::Interrupted()
{
	End();
}
