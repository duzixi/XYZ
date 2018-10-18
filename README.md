# XYZ

## ZXDataFile

三维空间数据存储文件数据转换。

## Vector3

三维空间常用类模板C++实现。

Share some Class templates using in 3D space implented by C++.


在借鉴Darkziyu的Mathd项目(https://github.com/Darkziyu/Mathd ) 基础上，
对Unity类的再实现按照C++的需求部分扩展为了类模板。

Implent Unity Classes to C++ Class Templates based work on Darkziyu(https://github.com/Darkziyu/Mathd).

由于主要应用于PCL项目，
坐标系进行了调整，调换了Y轴与Z轴。

Since the code is basicly used with PCL project,
Y axis and Z axis are swaped.

		/* 本类采用坐标系如下：
		y
		^
		|
		|   俯视图        z轴垂直屏幕朝上
		|
		o-----------> x
		*/


目前只实现了Vector3类模板。

Now only Vector3 Class Templates are implented.


# Vector3<T>
  
## 构造函数

* Vector3(T _x, T _y)
* Vector3(T _x, T _y, T _z)

## 类成员变量

* back = Vector3<T>(0, -1, 0);
* down = Vector3<T>(0, 0, -1);
* forward = Vector3<T>(0, 1, 0);
* fwd = Vector3<T>(0, 1, 0);
* left = Vector3<T>(-1, 0, 0);
* one = Vector3<T>(1, 1, 1);
* right = Vector3<T>(1, 0, 0);
* up = Vector3<T>(0, 0, 1);
* zero = Vector3<T>(0, 0, 0);

## 类方法
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

## 成员方法
		// 单位化（不改变向量本身）
		Vector3<T> normalized();
		// 缩放
		void Scale(Vector3<T> scale);
		// 设置
		void Set(T _x, T _y, T _z);
		// 返回字符串
		string ToString();

## 运算符重载
		// 比较是否相等
		bool operator==(const Vector3<T> &rhs) const;
		// 比较是否不相等
		bool operator!=(const Vector3<T> &rhs) const;
    
    （以下为类外定义）
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
