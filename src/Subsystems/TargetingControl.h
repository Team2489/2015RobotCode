#ifndef TargetingControl_H
#define TargetingControl_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include"../VisionClient.h"

class TargetingControl: public Subsystem
{
private:
	VisionClient* m_vc;
	// everything possible under private except
	// for methods that implement subsystem capabilities
public:
	TargetingControl();
	void InitDefaultCommand();
	virtual ~TargetingControl();
	double GetDistance();
};

#endif
