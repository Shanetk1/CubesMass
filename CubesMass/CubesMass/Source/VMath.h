#ifndef VMATH_H
#define VMATH_H
#include <cmath>
#include <iostream>

/// This is a library of Vec3 math routines. 
#include "Vector.h"


namespace MATH {

	class VMath {

	public:
		/// Calculate the dot product between Vec3s a & b 
		inline static float dot(const Vector2& a, const Vector2& b) {
			return(a.x * b.x + a.y * b.y);
		}


		inline static float mag(const Vector2& a) {
			return(sqrt(a.x * a.x + a.y * a.y));
		}


		////////////////////////////////////////////////////////////////////////		
		/// These are a little more complex so I won't bother to inline them
		////////////////////////////////////////////////////////////////////////




		/// Return a normalized Vec3
		static Vector2 normalize(const Vector2& a);


		/// Get the distance between two Vec3s 
		static float distance(Vector2 a,Vector2 b);


	};

}

#endif