#ifndef CenterOnTote_H
#define CenterOnTote_H

#include "../Robot.h"
#include "WPILib.h"
#include <iostream>

class CenterOnTote: public Command
{
public:
	CenterOnTote();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool anyMotion();
	bool m_isFinished;
};

#endif
