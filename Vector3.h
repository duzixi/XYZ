//
//  Vector3.h
//  XYZ
//  三维空间常用类模板C++实现。封装了三维空间向量的常用成员与方法。
//
//  Created by 杜子兮(duzixi[at]gmail[dot]com) on 18-4-7.
//  Copyright (c) 2018年 www.duzixi.com All rights reserved.
//

#pragma once

using namespace std;

namespace XYZ {

	template <class T>
	class Vector3
	{
	public:
		T x;
		T y;
		T z;
		// 构造函数 ==============================
		Vector3();
		Vector3(T _x, T _y);
		Vector3(T _x, T _y, T _z);
		// 析构函数
		~Vector3();

		// 属性====================================
		// 常用向量
		/* 本类采用坐标系如下：
		y
		^
		|
		|   俯视图        z轴垂直屏幕朝上
		|
		o-----------> x
		*/
		// (0, -1, 0)
		static Vector3<T> back;
		// (0, 0, -1)
		static Vector3<T> down;
		// (0, 1, 0)
		static Vector3<T> forward;
		// (0, 1, 0)
		static Vector3<T> fwd;
		// (-1, 0, 0)
		static Vector3<T> left;
		// (1, 1, 1)
		static Vector3<T> one;
		// (1, 0, 0)
		static Vector3<T> right;
		// (0, 0, 1)
		static Vector3<T> up;
		// (0, 0, 0)
		static Vector3<T> zero;

		// 模的平方
		T sqrMagnitude;

		// 模
		T magnitude;

		// 类方法 ===============================

		// 点乘
		static T Dot(Vector3<T> lhs, Vector3<T> rhs);
		// 叉乘
		static Vector3<T> Cross(Vector3<T> lhs, Vector3<T> rhs);
		// 距离
		static T Distance(Vector3<T> a, Vector3<T> b);
		// 单位化
		static Vector3<T> Normalize(Vector3<T> value);

		// 夹角大小（角度）
		static T Angle(Vector3<T> from, Vector3<T> to);
		// 夹角大小（弧度）
		static T AngleBetween(Vector3<T> from, Vector3<T> to);

		// 最大值(X,Y,Z均取最大)
		static Vector3<T> Max(Vector3<T> lhs, Vector3<T> rhs);

		// 最小值(X,Y,Z均取最小)
		static Vector3<T> Min(Vector3<T> lhs, Vector3<T> rhs);

		// 向量投影
		static Vector3<T> Project(Vector3<T> vector, Vector3<T> onNormal);

		// 缩放
		static Vector3<T> Scale(Vector3<T> a, Vector3<T> b);

		// 成员方法 ==============================

		// 单位化（不改变向量本身）
		Vector3<T> normalized();

		// 缩放
		void Scale(Vector3<T> scale);

		// 设置
		void Set(T _x, T _y, T _z);

		// 返回字符串
		string ToString();


		// 运算符重载 ==========================

		// 比较是否相等
		bool operator==(const Vector3<T> &rhs) const;
		// 比较是否不相等
		bool operator!=(const Vector3<T> &rhs) const;

	};

	// 运算符重载

	template <class T>
	Vector3<T> operator+(const Vector3<T> &a, const Vector3<T> &b);

	template <class T>
	Vector3<T> operator-(const Vector3<T> &a, const Vector3<T> &b);

	template <class T>
	Vector3<T> operator*(const T d, const Vector3<T> &a);

	template <class T>
	Vector3<T> operator* (const Vector3<T> &a, const T d);

	template <class T>
	Vector3<T> operator/ (const Vector3<T> &a, const T d);

}