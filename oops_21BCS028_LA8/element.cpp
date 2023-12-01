#include <bits/stdc++.h>
using namespace std;

class Element
{
public:
    virtual void print() = 0;
    // virtual double norm() = 0;
};




class Point : public Element
{
public:
    void print()
    {
        cout << "Print function from Point" << endl;
    }
};
class Vector : public Element
{
public:
    void print()
    {
        cout << "Print function from Vector" << endl;
    }
};
class Location : public Point
{
};

int main()
{
    Point p;
    Vector v;
    Location l;
    p.print();
    v.print();
    l.print();
}