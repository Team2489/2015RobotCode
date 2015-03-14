#ifndef DriverStationLEDControl_H
#define DriverStationLEDControl_H

#include "WPILib.h"
#include "../Robot.h"

class DriverStationLEDControl: public Command {

public:
	DriverStationLEDControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
