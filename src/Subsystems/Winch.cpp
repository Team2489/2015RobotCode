#include "Winch.h"
#include "../RobotMap.h"

Winch::Winch() :
		Subsystem("Winch")
{
	m_winchTalon = RobotMap::winchtalon;
}

void Winch::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Winch::MoveUp()
{
	m_winchTalon->Set(1.0);
}

void Winch::MoveDown()
{
	m_winchTalon->Set(-1.0);
}

void Winch::Stop()
{
	m_winchTalon->Set(0.0);
}
