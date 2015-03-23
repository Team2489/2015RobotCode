#include "TurnDegrees.h"

TurnDegrees::TurnDegrees(float degrees)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::chassis);
	Robot::chassis->m_gyro->SetPIDSourceParameter(Gyro::kAngle);
	m_degrees = degrees;
	m_rotateOput = new RotatePIDOutput(Robot::chassis->drive);
	m_turnPID = new PIDController(AUTO_P_TURN,AUTO_I_TURN,AUTO_D_TURN,Robot::chassis->m_gyro, m_rotateOput);
}

// Called just before this Command runs the first time
void TurnDegrees::Initialize()
{
	Robot::chassis->m_gyro->Reset();
	m_turnPID->SetPID(AUTO_P_TURN,AUTO_I_TURN,AUTO_D_TURN);
 	m_turnPID->Enable();
 	m_turnPID->SetPercentTolerance(0.8);
	m_turnPID->SetOutputRange(-0.75,0.75);
	m_turnPID->SetInputRange(-1000,1000);
	m_turnPID->SetSetpoint(m_degrees);
}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool TurnDegrees::IsFinished()
{
	return m_turnPID->OnTarget();
}

// Called once after isFinished returns true
void TurnDegrees::End()
{
	m_turnPID->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnDegrees::Interrupted()
{
	End();
}

TurnDegrees::~TurnDegrees() {
	if(m_turnPID) {delete(m_turnPID);}
	if(m_rotateOput) {delete(m_rotateOput);}
}

