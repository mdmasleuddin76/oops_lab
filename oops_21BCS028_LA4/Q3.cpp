#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
class Point
{

    double _x;
    double _y;
    static int count;

public:
    void setCoords(double, double);
    void printCoords();
    double distFrom(Point &p);
    Point midPoint(Point &p);
    Point();
    Point(double x, double y);
    Point(Point &p);
    ~Point();
    Point operator+(const Point &obj) const;
    bool operator>(const Point &obj) const;
    bool operator<(const Point &obj) const;
    bool operator==(const Point &obj) const;
    int getcount();
};
int Point::count = 0;
void Point::setCoords(double x, double y)
{
    _x = x;
    _y = y;
}
void Point::printCoords()
{

    cout << "(" << _x << "," << _y << ")" << endl;
}
double Point::distFrom(Point &p)
{
    double d = ((p._x - _x) * (p._x - _x)) + ((p._y - _y) * (p._y - _y));
    return sqrt(d);
}
Point Point::midPoint(Point &p)
{
    Point temp;
    temp._x = (_x + p._x) / 2;
    temp._y = (_y + p._y) / 2;
    return temp;
}
Point::Point()
{
    _x = 0;
    _y = 0;
    count++;
}
Point::Point(double x, double y)
{
    _x = x;
    _y = y;
    count++;
}
Point::Point(Point &p)
{
    _x = p._x;
    _y = p._y;
    count++;
}
Point::~Point()
{
    count--;
    cout << "Destructor is called " << endl;
}
Point Point::operator+(const Point &obj) const
{
    Point temp;
    temp._x = _x + obj._x;
    temp._y = _y + obj._y;
    return temp;
}
int Point::getcount()
{
    return count;
}
bool Point::operator<(const Point &obj) const
{
    float t1 = (_x * _x) + (_y * _y), t2 = (obj._x * obj._x) + (obj._y * obj._y);
    if (t1 < t2)
        return true;
    return false;
}
bool Point::operator>(const Point &obj) const
{
    float t1 = (_x * _x) + (_y * _y), t2 = (obj._x * obj._x) + (obj._y * obj._y);
    if (t1 > t2)
        return true;
    return false;
}
bool Point::operator==(const Point &obj) const
{
    float e = 0.1;
    float t1 = (_x * _x) + (_y * _y), t2 = (obj._x * obj._x) + (obj._y * obj._y);
    if (abs(t1 - t2)< 0.1)
        return true;
    return false;
}
int main()
{
    Point p1(1.2, 2.3), p2, p3, p4;
    p1.printCoords();
    cout << endl;
    p2.setCoords(3.2, 4.1);
    cout << p1.distFrom(p2) << endl;
    p3 = p1.midPoint(p2);
    p3.printCoords();
    p4 = p3;
    p4.printCoords();
    Point p5;
    p5 = p1 + p2;
    cout << (p1 < p2) << endl;
    cout << (p1 > p2) << endl;
    cout << (p1 == p2) << endl;
    p5.printCoords();
    getch();
}