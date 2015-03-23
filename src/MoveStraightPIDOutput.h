/*
 * MoveStraightPIDOutput.h
 *
 *  Created on: Mar 14, 2015
 *      Author: vigneshv
 */

#ifndef MOVESTRAIGHTPIDOUTPUT_H_
#define MOVESTRAIGHTPIDOUTPUT_H_

#include "WPILib.h"

class MoveStraightPIDOutput: public PIDOutput {
private:
	RobotDrive* m_robotDrive;
public:
	MoveStraightPIDOutput(RobotDrive* d);
	virtual ~MoveStraightPIDOutput();
	virtual void PIDWrite(float output);
};

#endif /* MOVESTRAIGHTPIDOUTPUT_H_ */
