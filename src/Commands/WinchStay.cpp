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
	float elevatorPower = Robot::oi->GetElevatorPowerGamepad();
	if (elevatorPower == 0) {
		Robot::winch->m_balancePID->Enable();
	} else {
		Robot::winch->m_balancePID->Disable();

		 if (elevatorPower <= 0) {
			 Robot::winch->MoveDown(0.7*elevatorPower);
		 }else {
			 Robot::winch->MoveUp(-0.5 *0.7 *elevatorPower);
		 }
	}
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
	Robot::winch->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchStay::Interrupted()
{
	End();
}
