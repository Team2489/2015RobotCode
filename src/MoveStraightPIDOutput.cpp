/*
 * MoveStraightPIDOutput.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: vigneshv
 */

#include "MoveStraightPIDOutput.h"

MoveStraightPIDOutput::MoveStraightPIDOutput(RobotDrive* d) {
	m_robotDrive = d;
}

MoveStraightPIDOutput::~MoveStraightPIDOutput() {
}

void MoveStraightPIDOutput::PIDWrite(float output) {
	m_robotDrive->MecanumDrive_Cartesian(0, output, 0, 0);
}
