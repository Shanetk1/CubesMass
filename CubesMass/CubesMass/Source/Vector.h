#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

#ifndef DEGREES_TO_RADIANS
#define DEGREES_TO_RADIANS (M_PI / 180.0f)
#endif	

#ifndef RADIANS_TO_DEGREES
#define RADIANS_TO_DEGREES (180.0f / M_PI)
#endif
struct Vector2
{
	float x, y = 0.f;

	Vector2() { x = y = 0.f; };
	Vector2(float x_, float y_) { x = x_; y = y_; };
	Vector2(float val) { x = y = val; };

	Vector2& Add(const Vector2& vec) 
	{
		this->x += vec.x;
		this->y += vec.y;
		return *this;

	}
	Vector2& Subtract(const Vector2& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		return *this;
	};
	Vector2& Multiply(const Vector2& vec)
	{
		this->x *= vec.x;
		this->y *= vec.y;
		return *this;
	}
	Vector2& Divide(const Vector2& vec)
	{
		this->x /= vec.x;
		this->y /= vec.y;
		return *this;
	}

	inline friend Vector2& operator+(Vector2 &v1, const Vector2 &v2)
	{
		return v1.Add(v2);
	}
	inline friend Vector2& operator-(Vector2& v1, const Vector2& v2)
	{
		return v1.Subtract(v2);
	}
	inline friend Vector2& operator/(Vector2& v1, const Vector2& v2)
	{
		return v1.Divide(v2);
	}
	inline friend Vector2& operator*(Vector2& v1, const Vector2& v2)
	{
		return v1.Multiply(v2);
	}

	inline Vector2& operator +=(const Vector2& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		return *this;




		//return this->Add(vec);
	}
	inline Vector2& operator -=(const Vector2& vec)
	{
		return this->Subtract(vec);
	}
	inline Vector2& operator /=(const Vector2& vec)
	{
		return this->Divide(vec);
	}
	inline Vector2& operator *=(const Vector2& vec)
	{
		return this->Multiply(vec);
	}
	inline Vector2 operator * (const float scalar)
	{
		return Vector2(x * scalar, y * scalar);
	}
















};