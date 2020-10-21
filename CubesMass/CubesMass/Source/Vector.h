#pragma once

struct Vector2
{
	//Gonna be a long what just simple vector math stuff with some friends if your familiar with that

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
		return this->Add(vec);
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
















};