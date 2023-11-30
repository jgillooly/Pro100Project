#pragma once
#pragma once
#include "Core/Math/Vector3.h"
#include "Core/Vector2.h"
namespace antares {
	class Matrix33
	{
	public:
		vec3 rows[3];
		// [row][column]
		// rows[0] = vec3{ 0, 0, 0 }
		// rows[1] = vec3{ 0, 0, 0 }
		// rows[2] = vec3{ 0, 0, 0 }

		Matrix33() = default;
		Matrix33(const vec3& row1, const vec3& row2, const vec3& row3) {
			rows[0] = row1;
			rows[1] = row2;
			rows[2] = row3;
		}

		vec3  operator [] (size_t index) const { return rows[index]; }
		vec3& operator [] (size_t index) { return rows[index]; }

		vec2 operator * (const vec2& v);
		Matrix33 operator * (const Matrix33& mx);

		static Matrix33 CreateTranslation(const vec2& translation);
		static Matrix33 CreateScale(const vec2& scale);
		static Matrix33 CreateScale(float scale);
		static Matrix33 CreateRotation(float radians);

		static Matrix33 CreateIdentity();

		vec2 GetTranslation() const;
		float GetRotation() const;
		vec2 GetScale() const;
	};

	inline vec2 Matrix33::GetTranslation() const {
		return { rows[0][2], rows[1][2] };
	}

	inline float Matrix33::GetRotation() const {
		return std::atan2(rows[1][0], rows[0][0]);
	}

	inline vec2 Matrix33::GetScale() const {
		vec2 x = { rows[0][0], rows[0][1] };
		vec2 y = { rows[1][0], rows[1][1] };
		return { x.Length(), y.Length() };
	}

	inline vec2 Matrix33::operator*(const vec2& v) {

		// | a b x |   | x |
		// | d e y | * | y |
		// | g h i |   | 1 |

		vec2 result;
		result.x = rows[0][0] * v.x + rows[0][1] * v.y + rows[0][2];
		result.y = rows[1][0] * v.x + rows[1][1] * v.y + rows[1][2];

		return result;
	}

	inline Matrix33 Matrix33::operator*(const Matrix33& mx) {
		Matrix33 result;
		// | a b c |   | j k l |
		// | d e f | * | m n o |
		// | g h i |   | p q r |

		result[0][0] = rows[0][0] * mx[0][0] + rows[0][1] * mx[1][0] + rows[0][2] * mx[2][0]; // a*j + b*m + c*p
		result[0][1] = rows[0][0] * mx[0][1] + rows[0][1] * mx[1][1] + rows[0][2] * mx[2][1]; // a*k + b*n + c*q
		result[0][2] = rows[0][0] * mx[0][2] + rows[0][1] * mx[1][2] + rows[0][2] * mx[2][2]; // a*l + b*o + c*r

		result[1][0] = rows[1][0] * mx[0][0] + rows[1][1] * mx[1][0] + rows[1][2] * mx[2][0]; // d*j + e*m + f*p
		result[1][1] = rows[1][0] * mx[0][1] + rows[1][1] * mx[1][1] + rows[1][2] * mx[2][1]; // d*k + e*n + f*q
		result[1][2] = rows[1][0] * mx[0][2] + rows[1][1] * mx[1][2] + rows[1][2] * mx[2][2]; // d*l + e*o + f*r

		result[2][0] = rows[2][0] * mx[0][0] + rows[2][1] * mx[1][0] + rows[2][2] * mx[2][0]; // g*j + h*m + i*p
		result[2][1] = rows[2][0] * mx[0][1] + rows[2][1] * mx[1][1] + rows[2][2] * mx[2][1]; // g*k + h*n + i*q
		result[2][2] = rows[2][0] * mx[0][2] + rows[2][1] * mx[1][2] + rows[2][2] * mx[2][2]; // g*l + h*o + i*r

		return result;
	}

	inline Matrix33 Matrix33::CreateIdentity() {
		return {
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 0, 0, 1 }
		};
	}

	inline Matrix33 Matrix33::CreateTranslation(const vec2& translation) {
		// | s 0 0 |
		// | 0 s 0 |
		// | 0 0 1 |

		Matrix33 mx = CreateIdentity();
		mx[0][2] = translation.x;
		mx[1][2] = translation.y;

		return mx;
	}

	inline Matrix33 Matrix33::CreateScale(const vec2& scale) {
		// | sx 0 0 |
		// | 0 sy 0 |
		// | 0  0 1 |
		Matrix33 mx = CreateIdentity();
		mx[0][0] = scale.x;
		mx[1][1] = scale.y;

		return mx;
	}

	inline Matrix33 Matrix33::CreateScale(float scale) {
		// | s 0 0 |
		// | 0 s 0 |
		// | 0 0 1 |
		Matrix33 mx = CreateIdentity();
		mx[0][0] = scale;
		mx[1][1] = scale;

		return mx;
	}

	inline Matrix33 Matrix33::CreateRotation(float radians) {
		Matrix33 mx = CreateIdentity();
		float c = cos(radians);
		float s = sin(radians);

		mx[0][0] = c; mx[0][1] = -s;
		mx[1][0] = s; mx[1][1] =  c;

		return mx;
	}



	using mat3 = Matrix33;
}