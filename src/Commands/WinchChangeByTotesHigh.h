#ifndef WinchChangeByTotesHigh_H
#define WinchChangeByTotesHigh_H

#include "Commands/Subsystem.h"
#include "../Robot.h"


class WinchChangeByTotesHigh: public Command
{
private:
	int m_totesHigh;
public:
	WinchChangeByTotesHigh(int toteHeight);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
