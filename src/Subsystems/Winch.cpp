#include "Winch.h"
#include "../RobotMap.h"

Winch::Winch() :
		Subsystem("Winch")
{
	m_winchTalon = RobotMap::winchtalon;
	m_encoder = RobotMap::winchEncoder;
	m_encoder->Reset();
	m_totesHighPID = RobotMap::winchEncoderPID;
}

void Winch::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Winch::MoveUp(float speed)
{
	m_winchTalon->Set(-speed);
}

void Winch::MoveDown(float speed)
{
	m_winchTalon->Set(speed);
}

void Winch::Stop()
{
	m_winchTalon->Set(0.0);
}
