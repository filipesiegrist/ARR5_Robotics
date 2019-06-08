#ifndef DEGREES_RADIANS_CONVERSIONS_H__
#define DEGREES_RADIANS_CONVERSIONS_H__

/*

	Created by David Brockman Smoliansky
	https://gist.github.com/dbrockman

	Github link:
	https://gist.github.com/dbrockman/4773781

	Using improvement suggested by Alexandr Graschenkov (https://gist.github.com/AlexandrGraschenkov)

*/

#include <math.h>

// Converts degrees to radians.
#define degreesToRadians(angleDegrees) ((angleDegrees) * M_PI / 180.0)

// Converts radians to degrees.
#define radiansToDegrees(angleRadians) ((angleRadians) * 180.0 / M_PI)

#endif

