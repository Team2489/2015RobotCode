#ifndef WinchUpDown_H
#define WinchUpDown_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class WinchUpDown: public Command
{
private:
	bool m_isUp;
	double m_timeout;
	double m_power;
public:
	WinchUpDown(bool isUp, double timeout, double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
