/*
 * RotatePIDOutput.cpp
 *
 *  Created on: Mar 13, 2015
 *      Author: vigneshv
 */

#include <RotatePIDOutput.h>

RotatePIDOutput::RotatePIDOutput(RobotDrive *r) {
	m_robotDrive = r;
}

RotatePIDOutput::~RotatePIDOutput() {
}

void RotatePIDOutput::PIDWrite(float output) {
	m_robotDrive->MecanumDrive_Cartesian(0, 0, output);
}
