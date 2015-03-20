#include "AutonomousGroup.h"
#include <Commands/WinchTotesHigh.h>
#include <Commands/TurnDegrees.h>
#include <Commands/MoveForward.h>
#include <Commands/MoveUntilToteView.h>
#include <Commands/MoveSideways.h>

// Three tote autonomous
AutonomousGroup::AutonomousGroup()
{
	AddSequential(new WinchTotesHigh(1));
	AddSequential(new TurnDegrees(-40));
	AddSequential(new MoveForward(-18.5));
	AddSequential(new TurnDegrees(40));
	AddSequential(new MoveUntilToteView());
	AddSequential(new WinchTotesHigh(0));
	AddSequential(new WinchTotesHigh(1));
	AddSequential(new TurnDegrees(-40));
	AddSequential(new MoveForward(-18.5));
	AddSequential(new TurnDegrees(40));
	AddSequential(new MoveUntilToteView());
	AddSequential(new WinchTotesHigh(0));
	AddSequential(new WinchTotesHigh(1));
	AddSequential(new MoveSideways(1000, 5, true));

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
