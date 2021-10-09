#include "VMath.h"

using namespace MATH;

/// Return a normalized Vec3
Vector2 VMath::normalize(const Vector2& a) {
	float magnitude;
	magnitude = float(sqrt(a.x * a.x + a.y * a.y));
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
	if (magnitude < VERY_SMALL) {
		std::string errorMsg = __FILE__ + __LINE__;
		throw errorMsg.append(": Divide by nearly zero! ");
	}
#endif
	return Vector2(a.x / magnitude, a.y / magnitude);
}


float VMath::distance(Vector2 a, Vector2 b) {
	Vector2 r = a - b;
	return(mag(r));
}
