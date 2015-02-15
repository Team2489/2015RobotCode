#ifndef Winch_H
#define Winch_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Winch: public Subsystem
{
private:
	Talon *m_winchTalon;
public:
	Winch();
	void MoveUp();
	void MoveDown();
	void Stop();
	void InitDefaultCommand();
};

#endif
