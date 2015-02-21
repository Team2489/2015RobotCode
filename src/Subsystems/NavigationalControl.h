#ifndef NavigationalControl_H
#define NavigationalControl_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <iostream>
#include <time.h>

class NavigationalControl: public Subsystem
{
private:
	pthread_mutex_t data_mutex;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	BuiltInAccelerometer* m_accelerometer;
	Task* m_task;
	Task* m_calibrateTask;
	time_t m_prevTime;
	double m_xVelocity;
	double m_yVelocity;
	double m_initialAccelerometerReading;

	NavigationalControl();
	virtual ~NavigationalControl();
	void InitDefaultCommand();
	void ZeroVelocity();
	void Run();
	static void MainLoop(void *ptr);
	static void CalibrateLoop(void *ptr);
	void CalibrateRun();
};

#endif
