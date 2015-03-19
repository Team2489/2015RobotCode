#ifndef TurnDegrees_H
#define TurnDegrees_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"

class TurnDegrees: public Command
{
private:
	PIDController *m_turnPID;
	RotatePIDOutput *m_rotateOput;
	float m_degrees;
public:
	TurnDegrees(float degrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	virtual ~TurnDegrees();
};

#endif
