#pragma once
#include <cmath>
#include <istream>
#include <sstream>

namespace antares {
	class Vector2 {
	public:
		float x, y;
	public:
		Vector2() : x{ 0 }, y{ 0 } {};
		Vector2(float v) : x{ v }, y{ v } {};
		Vector2(float x, float y) : x{ x }, y{ y } {};
		Vector2(int x, int y) : x{ (float)x }, y{ (float)y } {}

		float operator [] (size_t index) const { return (&x)[index]; }
		float& operator [] (size_t index) { return (&x)[index]; }

		Vector2 operator - () const { return { -x, -y }; }
		
		//Vector2 Add(Vector2 v) { return Vector2(x + v.x, y + v.y); }
		Vector2 operator + (const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
		Vector2 operator - (const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
		Vector2 operator / (const Vector2& v) const { return Vector2(x / v.x, y / v.y); }
		Vector2 operator * (const Vector2& v) const { return Vector2(x * v.x, y * v.y); }
		
		Vector2 operator + (const float s) const { return Vector2(x + s, y + s); }
		Vector2 operator - (const float s) const { return Vector2(x - s, y - s); }
		Vector2 operator / (const float s) const { return Vector2(x / s, y / s); }
		Vector2 operator * (const float s) const { return Vector2(x * s, y * s); }

		Vector2& operator += (const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v) { x -= v.x; y -= v.y; return *this; }
		Vector2& operator /= (const Vector2& v) { x /= v.x; y /= v.y; return *this; }
		Vector2& operator *= (const Vector2& v) { x *= v.x; y *= v.y; return *this; }

		float LengthSqr() const { return (x * x) + (y * y); }
		float Length() const { return std::sqrt(LengthSqr()); }

		float DistanceSqr(const Vector2& v) {
			return (*this - v).LengthSqr();
		}

		float Distance(const Vector2& v) {
			return (*this - v).Length();
		}

		Vector2 Normalized() const { return *this / Length(); }
		void Normalize() { *this /= Length(); }

		float Angle() const {
			return std::atan2f(y, x);
		}

		Vector2 Rotate(float radians) const;
	};

	inline std::ostream& operator<<(std::ostream& stream, const Vector2& v) {
		stream << v.x << " " << v.y;
		return stream;
	}

	inline Vector2 Vector2::Rotate(float radians) const {
		float _x = x * std::cos(radians) - y * std::sin(radians);
		float _y = x * std::sin(radians) + y * std::cos(radians);
		return { _x,_y };
	}

	inline std::istream& operator >> (std::istream& stream, Vector2& v) {
		std::string line;
		std::getline(stream, line);
		// { ##, ## }
		std::string xs = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
		v.x = std::stof(xs);

		std::string ys = line.substr(line.find(",") + 1, line.find("}") - (line.find(",") + 1));
		v.y = std::stof(ys);
		return stream;
	}
	using vec2 = Vector2;
}