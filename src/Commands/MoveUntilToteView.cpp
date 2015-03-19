#include "MoveUntilToteView.h"

MoveUntilToteView::MoveUntilToteView()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::chassis);
}

// Called just before this Command runs the first time
void MoveUntilToteView::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveUntilToteView::Execute()
{
	Robot::chassis->MecanumDrive_Cartesian(0, 0.5, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveUntilToteView::IsFinished()
{
	return !Robot::chassis->m_leftProximitySensor;
}

// Called once after isFinished returns true
void MoveUntilToteView::End()
{
	Robot::chassis->MecanumDrive_Cartesian(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveUntilToteView::Interrupted()
{

}
