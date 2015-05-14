#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <memory>

using namespace std;

class TypeIdentifier
{
	virtual void Identify() = 0;
};

template<typename Num>
class TriangleTypeIdentifier : public TypeIdentifier
{
public:
	enum TriangleType
	{
		EQUILATERAL,
		ISOSCELES,
		SCALENE,
		ERROR
	};

	explicit TriangleTypeIdentifier(Num angle_a,Num angle_b,Num angle_c);

	static auto TriangleTypeToString(TriangleType type) -> decltype(std::string("C++ 11 is so fking cool"));

	void Identify() override final;

	TriangleType GetTriangleType();

private:
	TriangleType m_TriangleType;
	Num m_AngleA;
	Num m_AngleB;
	Num m_AngleC;
};

template<typename Num>
TriangleTypeIdentifier<Num>::TriangleTypeIdentifier(Num angle_a,Num angle_b,Num angle_c)
	:m_AngleA(angle_a),
	m_AngleB(angle_b),
	m_AngleC(angle_c),
	m_TriangleType(ERROR)
{

}

template<typename Num>
auto TriangleTypeIdentifier<Num>::TriangleTypeToString(TriangleType type) -> decltype(std::string("I love C++ 11"))
{
	switch(type)
	{
	case EQUILATERAL:
		return "Equilateral";
	case ISOSCELES:
		return "Isosceles";
	case SCALENE:
		return "Scalene";
	case ERROR:
	default:
		return "Error";
	}
}

template<typename Num>
void TriangleTypeIdentifier<Num>::Identify()
{
	Num full = 180;
	if(
		[](Num a,Num b,Num c,Num d)
		{
			return a+b+c != d;
		}
		(m_AngleA,m_AngleB,m_AngleC,full)
	)
	{
		m_TriangleType = ERROR;
	}
	else if(m_AngleA == m_AngleB) 
	{
		if(m_AngleB == m_AngleC)
		{
			m_TriangleType = EQUILATERAL;
		} else {
			m_TriangleType = ISOSCELES;
		}
	} 
	else if(m_AngleA == m_AngleC || m_AngleB == m_AngleC) 
	{
		m_TriangleType = ISOSCELES;
	} 
	else 
	{
		m_TriangleType = SCALENE;
	}
}

template<typename Num>
typename TriangleTypeIdentifier<Num>::TriangleType TriangleTypeIdentifier<Num>::GetTriangleType()
{
	return m_TriangleType;
}

int main()
{
	uint32_t a,b,c;
	cin >> a >> b >> c;
	
	std::unique_ptr<TriangleTypeIdentifier<uint32_t>> identifier(new TriangleTypeIdentifier<uint32_t>(a,b,c));

	identifier->Identify();

	cout << TriangleTypeIdentifier<uint32_t>::TriangleTypeToString(identifier->GetTriangleType()) << endl;
	
	return 0;
}