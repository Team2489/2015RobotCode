/*
 * RotatePIDOutput.h
 *
 *  Created on: Mar 13, 2015
 *      Author: vigneshv
 */

#ifndef SRC_ROTATEPIDOUTPUT_H_
#define SRC_ROTATEPIDOUTPUT_H_

#include "WPILib.h"
#include <iostream>



class RotatePIDOutput : public PIDOutput{
private:
	RobotDrive *m_robotDrive;
public:
	RotatePIDOutput(RobotDrive *r);
	virtual void PIDWrite(float output);
	virtual ~RotatePIDOutput();
};

#endif /* SRC_ROTATEPIDOUTPUT_H_ */
