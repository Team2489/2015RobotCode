#include "MoveForward.h"

MoveForward::MoveForward(double distance)
{
	// Use Requires() here to declare subsystem dependencies

	Requires(Robot::chassis);
	Robot::chassis->m_backRightEncoder->Reset();
	Robot::chassis->m_backRightEncoder->SetPIDSourceParameter(Encoder::kDistance);
	Robot::chassis->m_backRightEncoder->SetDistancePerPulse(1.0);
	Robot::chassis->m_backRightEncoder->Reset();
	m_distance = distance;
	m_straightOput = new MoveStraightPIDOutput(Robot::chassis->drive);
	m_straightPID = new PIDController(AUTO_P_DISTANCE, AUTO_I_DISTANCE, AUTO_D_DISTANCE, Robot::chassis->m_backRightEncoder, m_straightOput);
}

// Called just before this Command runs the first time
void MoveForward::Initialize()
{
	m_straightPID->SetOutputRange(-0.75,0.75);
	m_straightPID->SetPercentTolerance(0.5);
	m_straightPID->SetInputRange(-10000,10000);
	m_straightPID->Enable();
	m_straightPID->SetSetpoint(m_distance*AUTO_PULSES_PER_INCH);
}

// Called repeatedly when this Command is scheduled to run
void MoveForward::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool MoveForward::IsFinished()
{
	return m_straightPID->OnTarget();
}

// Called once after isFinished returns true
void MoveForward::End()
{
	m_straightPID->Disable();
	Robot::chassis->m_backRightEncoder->SetPIDSourceParameter(Encoder::kRate);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveForward::Interrupted()
{
	End();
}

MoveForward::~MoveForward()
{
	if(m_straightPID) {delete(m_straightPID);}
	if(m_straightOput) {delete(m_straightOput);}
}
