#ifndef WinchStay_H
#define WinchStay_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"

class WinchStay: public Command
{
public:
	WinchStay();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
