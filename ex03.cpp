#include <iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}

	friend ostream& operator<<(ostream& os, Vector& v)
	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}
	friend istream& operator>>(istream& is, Vector& v)
	{
		is >> v.x >> v.y >> v.z;
		return is;
	}
};

int main()
{
	Vector v0{ 1,2,3 };
	cout << v0 << endl; //cout.operator<<(v) -> operator<<(cout.v)
    // operator<<(cout,v)<<endl; -> endl, cout ¸â¹öÇÔ¼ö cout.endl

	Vector v1;
	cin >> v1; //operator>>(cin,v)
	cout << v1 << endl;
}