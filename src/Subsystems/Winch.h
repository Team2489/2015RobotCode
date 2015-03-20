#ifndef Winch_H
#define Winch_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Winch: public Subsystem
{
public:
	Talon *m_winchTalon;
	Encoder *m_encoder;
	PIDController *m_totesHighPID;
	PIDController *m_balancePID;
	Winch();
	void MoveUp(float speed);
	void MoveDown(float speed);
	void Stop();
	void InitDefaultCommand();
};

#endif
