#include <iostream>
#include <cmath>
using namespace std;

struct Vector3 {
	double x;
	double y;
	double z;

	double length() {
		return sqrt(x*2 + y*2 + z*2);
	}
	double dot(Vector3 vec) {
		return x * vec.x + y * vec.y + z * vec.z;
	}
	
	auto product(Vector3 vec) {
		Vector3 vec_new;
		vec_new.x = y * vec.z - z * vec.y;
		vec_new.y = z * vec.x - x * vec.z;
		vec_new.z = x * vec.y - y * vec.x;
		return vec_new;
	}
	
};

int main() {
	Vector3 a = {1,2,3};
	Vector3 b = {10, 0, 1};

	cout << a.length() << endl;
	cout << a.dot(b) << endl;

	return 0;
}
