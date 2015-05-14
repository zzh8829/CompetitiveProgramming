#include <cmath>
#include <iostream>

struct Vec
{
	float x,y,z;
	Vec(float _x=0,float _y=0,float _z=0):x(_x),y(_y),z(_z){};
	Vec operator+(const Vec& v)const{
		return Vec(x+v.x,y+v.y,z+v.z);
	}
	Vec operator-(const Vec& v)const{
		return Vec(x-v.x,y-v.y,z-v.z);
	}
	/*
	x  y  z  x  y  z
		x  x  x
	vx vy vz vx vy vz
	*/
	Vec crossProduct(const Vec& v)const{
		return Vec(
				y*v.z-z*v.y,
				z*v.x-x*v.z,
				x*v.y-y*v.x);
	}
	float dotProduct(const Vec& v)const{
		return x*v.x+y*v.y+z*v.z;
	}
	float norm(){
		return sqrt(x*x+y*y+z*z);
	}
	friend std::ostream& operator<<(std::ostream& out,const Vec& v)
	{
		out << "x: " << v.x << " y: " << v.y << " z: " << v.z;
		return out;
	}
};