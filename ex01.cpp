#include <iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}
	
	Vector operator+() //���׿����� +, v8
	{
		return Vector{ +x,+y,+z };
	}
	Vector operator-() //���׿����� -, v3
	{
		return Vector{ -x,-y,-z };
	}
	Vector operator+(Vector v) //���׿����� +, v2
	{
		return Vector{ x + v.x,y + v.y,z + v.z };
	}
	Vector operator-(Vector v) //���׿����� -, v9
	{
		return Vector{ x - v.x,y - v.y,z - v.z };
	}
	float operator*(const Vector& v)const //���׿����� *, v4
	{
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}
	Vector operator*(float n)const //���׿����� *, v5
	{
		return Vector{ x * n,y * n,z * n };
	}
	Vector operator/(float n)const //���׿����� /, v10
	{
		return Vector{ x / n,y / n,z / n };
	}
	Vector& operator++() // ���������� ++, v6
	{
		++x;
		++y;
		++z;
		return *this;
	}
	Vector& operator--() // ���������� --, v11
	{
		--x;
		--y;
		--z;
		return *this;
	}
	Vector& operator++(int) //���������� ++, v7
	{
		Vector temp = *this;
		++x;
		++y;
		++z;
		return temp;
	}
	Vector& operator--(int) // ���������� --, v12
	{
		Vector temp = *this;
		--x;
		--y;
		--z;
		return temp;
	}
	void print()
	{
		cout << x << " " << y << " " << z << endl;
	}
};

int main()
{
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	Vector v2 = v0 + v1; //���׿����� +, Vector v2 = v0.operator+(v1); ���� �ǹ�
	v2.print();

	Vector v3 = -v1; //���׿����� -, v1.operator-();
	v3.print();

	// ���׿����� *
	//���Ϳ���, ������� -> (v0.x*v1.x)+(v0.y*v1.y) = float
	float v4 = v0 * v1; //v0.operator*(v1);
	cout << v4 << endl;

	//���� * �Ǽ��� -> ����
	Vector v5 = v1 * 3.0f;//v1.operator*(3.0f)
	v5.print();

	Vector v6 = ++v1; //v1.operator++()
	v6.print();
	Vector v7 = v1++;
	v7.print();
	v1.print();

	Vector v8 = +v1; 
	v8.print();

	Vector v9 = v0 - v1;
	v9.print();

	Vector v10 = v1 / 3.0f;
	v10.print();

	Vector v11 = --v1;
	v11.print();
	Vector v12 = v1--;
	v12.print();
	v1.print();
}