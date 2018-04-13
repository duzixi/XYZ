#include "stdafx.h"
#include "Vector3.h"

#ifndef _VECTOR3_CPP__
#define _VECTOR3_CPP__

namespace XYZ {

	template <class T>
	Vector3<T>::Vector3()
	{
	}

	template <class T>
	Vector3<T>::~Vector3()
	{
	}

	template <class T>
	Vector3<T>::Vector3(T _x, T _y)
	{
		x = _x;
		y = _y;
		z = 0;
		sqrMagnitude = x * x + y * y + z * z;
		magnitude = sqrt(sqrMagnitude);
	}

	template <class T>
	Vector3<T>::Vector3(T _x, T _y, T _z)
	{
		x = _x;
		y = _y;
		z = _z;
		sqrMagnitude = x * x + y * y + z * z;
		magnitude = sqrt(sqrMagnitude);
	}

	// (0, -1, 0)
	template <class T>
	Vector3<T> Vector3<T>::back = Vector3<T>(0, -1, 0);

	// (0, 0, -1)
	template <class T>
	Vector3<T> Vector3<T>::down = Vector3<T>(0, 0, -1);

	// (0, 1, 0)
	template <class T>
	Vector3<T> Vector3<T>::forward = Vector3<T>(0, 1, 0);

	// (0, 1, 0)
	template <class T>
	Vector3<T> Vector3<T>::fwd = Vector3<T>(0, 1, 0);

	// (-1, 0, 0)
	template <class T>
	Vector3<T> Vector3<T>::left = Vector3<T>(-1, 0, 0);

	// (1, 1, 1)
	template <class T>
	Vector3<T> Vector3<T>::one = Vector3<T>(1, 1, 1);

	// (1, 0, 0)
	template <class T>
	Vector3<T> Vector3<T>::right = Vector3<T>(1, 0, 0);

	// (0, 0, 1)
	template <class T>
	Vector3<T> Vector3<T>::up = Vector3<T>(0, 0, 1);

	// (0, 0, 0)
	template <class T>
	Vector3<T> Vector3<T>::zero = Vector3<T>(0, 0, 0);


	template <class T>
	T Vector3<T>::Dot(Vector3<T> lhs, Vector3<T> rhs) {
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	template <class T>
	Vector3<T> Vector3<T>::Cross(Vector3<T> lhs, Vector3<T> rhs) {
		double _x = lhs.y * rhs.z - rhs.y * lhs.z;
		double _y = lhs.z * rhs.x - rhs.z * lhs.x;
		double _z = lhs.x * rhs.y - rhs.x * lhs.y;
		return Vector3<T>(_x, _y, _z);
	}

	template <class T>
	T Vector3<T>::Distance(Vector3<T> a, Vector3<T> b) {
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
	}

	template <class T>
	Vector3<T> Vector3<T>::Normalize(Vector3<T> value) {
		if (value == zero)
		{
			return zero;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
		}
		else
		{
			Vector3<T> tempVec = Vector3<T>();
			tempVec.x = value.x / value.magnitude;
			tempVec.y = value.y / value.magnitude;
			tempVec.z = value.z / value.magnitude;
			return tempVec;
		}
	}

	template <class T>
	T Vector3<T>::Angle(Vector3<T> from, Vector3<T> to) {
		T cos = Dot(from.normalized(), to.normalized());
		if (cos < -1) {
			cos = -1;
		}
		if (cos > 1) {
			cos = 1;
		}
		return acos(cos) * (180 / M_PI);
	}

	template <class T>
	T Vector3<T>::AngleBetween(Vector3<T> from, Vector3<T> to) {
		T cos = Dot(from.normalized(), to.normalized());
		if (cos < -1) {
			cos = -1;
		}
		if (cos > 1) {
			cos = 1;
		}
		return acos(cos);
	}

	template <class T>
	Vector3<T> Vector3<T>::Max(Vector3<T> lhs, Vector3<T> rhs){
		Vector3<T> temp = Vector3<T>();
		temp.x = max(lhs.x, rhs.x);
		temp.y = max(lhs.y, rhs.y);
		temp.z = max(lhs.z, rhs.z);
		return temp;
	}

	template <class T>
	Vector3<T> Vector3<T>::Min(Vector3<T> lhs, Vector3<T> rhs) {
		Vector3<T> temp = Vector3<T>();
		temp.x = min(lhs.x, rhs.x);
		temp.y = min(lhs.y, rhs.y);
		temp.z = min(lhs.z, rhs.z);
		return temp;
	}

	template <class T>
	Vector3<T> Vector3<T>::Project(Vector3<T> vector, Vector3<T> onNormal) {
		if (vector == zero || onNormal == zero)
		{
			return zero;
		}
		return Dot(vector, onNormal) / (onNormal.magnitude() * onNormal.magnitude()) * onNormal;
	}

	template <class T>
	Vector3<T> Vector3<T>::Scale(Vector3<T> a, Vector3<T> b) {
		Vector3<T> temp = Vector3<T>();
		temp.x = a.x * b.x;
		temp.y = a.y * b.y;
		temp.z = a.z * b.z;
		return temp;
	}

	template <class T>
	Vector3<T> Vector3<T>::normalized() {
		return Normalize(Vector3<T>(x, y, z));
	}

	template <class T>
	void Vector3<T>::Scale(Vector3<T> scale) {
		x *= scale.x;
		y *= scale.y;
		z *= scale.z;
	}

	template <class T>
	void Vector3<T>::Set(T _x, T _y, T _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	template <class T>
	string Vector3<T>::ToString() {
		stringstream ss;
		ss << "(" << x << "," << y << "," << z << ")";
		return ss.str();
	}

	template <class T>
	bool Vector3<T>::operator==(const Vector3<T> &rhs) const {
		if (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template <class T>
	bool Vector3<T>::operator!=(const Vector3<T> &rhs) const {
		return !(this == rhs)
	}

	// 运算符重载并不是类成员 ----------------------------------------

	template <class T>
	Vector3<T> operator+(const Vector3<T> &a, const Vector3<T> &b) { 
		return Vector3<T>(a.x + b.x, a.y + b.y, a.z + b.z);
	}

	template <class T>
	Vector3<T> operator-(const Vector3<T> &a, const Vector3<T> &b) {
		return Vector3<T>(a.x - b.x, a.y - b.y, a.z - b.z);
	}

	template <class T>
	Vector3<T> operator*(const T d, const Vector3<T> &a) { 
		return Vector3<T>(a.x * d, a.y * d, a.z * d);
	}

	template <class T>
	Vector3<T> operator*(const Vector3<T> &a, const T d ) { 
		return Vector3<T>(a.x * d, a.y * d, a.z * d);
	}

	template <class T>
	Vector3<T> operator/(const Vector3<T> &a, const T d) {
		return Vector3<T>(a.x / d, a.y / d, a.z / d);
	}
}

#endif