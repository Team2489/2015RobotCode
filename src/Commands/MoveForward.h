#ifndef MoveForward_H
#define MoveForward_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"

class MoveForward: public Command
{
private:
	MoveStraightPIDOutput *m_straightOput;
	PIDController *m_straightPID;
	double m_distance;

public:
	MoveForward(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	virtual ~MoveForward();
};

#endif
