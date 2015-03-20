#ifndef WinchTotesHigh_H
#define WinchTotesHigh_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class WinchTotesHigh: public Command
{
private:
	double m_totesHigh;
public:
	WinchTotesHigh(double totesHigh);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
