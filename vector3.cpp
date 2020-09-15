#include <iostream>
#include <cmath>
using namespace std;

struct Vector3 {
	double x;
	double y;
	double z;

	// 加算
	auto operator + (Vector3 vec) {
		Vector3 vec_new;
		vec_new.x = x + vec.x;
		vec_new.y = y + vec.y;
		vec_new.z = z + vec.z;
		return vec_new;
	}
	// 減算
	auto operator - (Vector3 vec) {
		Vector3 vec_new;
		vec_new.x = x - vec.x;
		vec_new.y = y - vec.y;
		vec_new.z = z - vec.z;
		return vec_new;
	}

	// ベクトルの長さ
	double length() {
		return sqrt(x*2 + y*2 + z*2);
	}
	// 内積(ドット積)
	double dot(Vector3 vec) {
		return x * vec.x + y * vec.y + z * vec.z;
	}
	// 外積(クロス積)
	auto cross(Vector3 vec) {
		Vector3 vec_new;
		vec_new.x = y * vec.z - z * vec.y;
		vec_new.y = z * vec.x - x * vec.z;
		vec_new.z = x * vec.y - y * vec.x;
		return vec_new;
	}
	// ベクトルを表示する
	void show() {
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}
};

int main() {
	Vector3 a = {1,2,3};
	Vector3 b = {10, 0, 1};

	cout << a.length() << endl;
	cout << a.dot(b) << endl;

	a.cross(b).show();
	(a + b).show();
	(a - b).show();

	return 0;
}
