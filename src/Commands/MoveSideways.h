#ifndef MoveSideways_H
#define MoveSideways_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"

class MoveSideways: public Command
{
private:
	double m_timeout;
	double m_rate;
	bool m_isLeft;
public:
	MoveSideways(double rate, double timeout, bool isLeft);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
