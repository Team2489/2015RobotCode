#ifndef WinchTotesHigh_H
#define WinchTotesHigh_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class WinchTotesHigh: public Command
{
private:
	int m_totesHigh;
public:
	WinchTotesHigh(int totesHigh);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
