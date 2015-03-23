#ifndef MoveUntilToteView_H
#define MoveUntilToteView_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"

class MoveUntilToteView: public Command
{
public:
	MoveUntilToteView();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
