#include "Point.h"
#include<sstream>
#include<cmath>
#include<iostream>


Point::Point()
{
}

Point::~Point()
{
}
Point::Point(double x,double y)
{
	m_x=x;
	m_y=y;
}

// Get the x value
double Point::GetX()
{
return m_x;
}
// Get the y value
double Point::GetY()
{
return m_y;
}



// Set the x value
void Point::SetX(double newxval)
{
m_x = newxval;
}
// Set the y value
void Point::SetY(double newyval)
{
m_y = newyval;
}


void Point::ToString()
{
std::stringstream ss;
ss << "Point(" << GetX() << "," << GetY() << ")";
std::string mystr=ss.str();
cout << mystr << endl;
}

double Point:: DistanceOrigin()
{
	double result= pow(m_x,2) + pow( m_y, 2);

	return sqrt(result);
}

double Point:: Distance(Point p)
{
	double xbetween= (p.m_x-m_x)*(p.m_x-m_x);
	double ybetween= (p.m_y-m_y)*(p.m_y-m_y);

	return sqrt( xbetween + ybetween);
}
Point Point:: operator - (void ) const; // Negate the coordinates.
{ // the additive inverse of current point
	return Point( - m_x , - m_y);
	
}

Point Point :: operator * (double factor) const; // Scale the coordinates.
{     
	   return Point( factor* m_x, factor*m_y);    //return the double scaled coordinates

}

Point Point::operator + (const Point& p) const; // Add coordinates.
{   
	
	return Point(m_x+p.m_x, m_y+p.m_y);
}

bool Point :: operator == (const Point& p) const; // Equally compare operator.
{          
	if(this== &p)
	         {        // return bool value 1 if the current Point variable is equal to Point variable p, else return 0
		return 1;
           }
            else
			return 0;

}     
Point& Point :: operator = (const Point& source); // Assignment operator.
{ 
	if (this == &source)
	{	return *this;}
	else
	{
	m_x = source.m_x;
	m_y = source.m_y;

	return *this;
	}             
}
Point& Point :: operator *= (double factor); // Scale the coordinates & assign by the factor user enteres. 
{
		m_x*=factor;
		m_y*=factor;

	    return *this;
}