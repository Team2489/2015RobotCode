// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"


//Do not commit it defined, for testbot only
#define TESTERBOT 0

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

#define CHASSISGYROANALOGINPUT 0
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static Talon* winchtalon;
	static SpeedController* chassisFrontLeftMotor;
	static SpeedController* chassisFrontRightMotor;
	static SpeedController* chassisBackLeftMotor;
	static SpeedController* chassisBackRightMotor;
	static Gyro* chassisGyro;
	static BuiltInAccelerometer* navigationalAccelerometer;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static void init();
};
#endif
