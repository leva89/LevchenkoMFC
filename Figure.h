/*#pragma once
class CFigure
{
public:
	CFigure(void);
	~CFigure(void);
};
*/

/*
#pragma once   
class CCircle
{
public:
	CCircle(double x, double y, double R);
	~CCircle(void);
public:
	void Draw(CDC &dc);
	bool IsInside(double x, double y);
	void Move(double dx, double dy);
protected:
	double m_dCenterX;
	double m_dCenterY;
	double m_dRadius; 
};

*/


#pragma once
#include <iostream>
//#define PI 3.14159265358

const double PI = acos(-1);

using namespace std;

class CMy2DPoint {
public:
	double m_x, m_y;
	CMy2DPoint();
	CMy2DPoint(double x, double y) : m_x(x), m_y(y) {};
	~CMy2DPoint();

	CMy2DPoint operator +(const CMy2DPoint& vector); // перегрузка оператора "+"
	CMy2DPoint operator -(const CMy2DPoint& vector); // перегрузка оператора "-"
	double operator *(const CMy2DPoint& vector);  // перегрузка оператора "*" (скалярное произведение)
	CMy2DPoint operator *(double v);  // перегрузка оператора "*" (умножение справа)
	CMy2DPoint operator /(double v);  // перегрузка оператора "/"
	bool operator ==(const CMy2DPoint& vector);  // перегрузка оператора "=="
	bool operator !=(const CMy2DPoint& vector);  // перегрузка оператора "!="
	CMy2DPoint& Rotate(double alpha);
	POINT GetP() const
	{
		POINT p;
		p.x = m_x;
		p.y = m_y;
		return p;
	}
	


};
CMy2DPoint operator *(double v, const CMy2DPoint& vector);  // перегрузка оператора "*" (умножение слева)
//ostream& operator <<(ostream& out, const CMy2DPoint& vector);  // перегрузка вывода
//istream& operator >>(istream& in, CMy2DPoint& vector);  // перегрузка ввода



class CMy2DObjectA4 {
	double A, A1, A2, A3;
	CMy2DPoint m_centre;

	//double m_dAngle;
public:
	double m_dAngle;
	CMy2DObjectA4();
	CMy2DObjectA4(double a, double a1, double a2, double a3, double x = 0, double y = 0, double ang = 0);
	~CMy2DObjectA4();

	double GetA();  
	double GetA1();
	double GetA2();
	double GetA3();
	CMy2DPoint GetCentre(); 
	double GetAngle(); 
	void Set();
	void SetA(double a);
	void SetA1(double a1);
	void SetA2(double a2);
	void SetA3(double a3);
	void SetCentre(const CMy2DPoint& centre); 
	void SetCentre(double x, double y);
	void SetDAngle(double dAngle);
	void Rotate(double dAngle);  
	void Move(double dX, double dY, double dAngle = 0);  
	void Move(const CMy2DPoint& delta, double dAngle = 0);
	bool IsInside(double x, double y);  
	bool IsInside(const CMy2DPoint& point);  

	void Draw(CDC &dc);

	friend ostream& operator <<(ostream& out, const CMy2DObjectA4& vector);  // перегрузка вывода
    friend istream& operator >>(istream& in, CMy2DObjectA4& vector);  // перегрузка ввода

	
}; 