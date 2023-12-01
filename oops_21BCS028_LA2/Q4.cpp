#include <iostream>
using namespace std;

class Line
{
private:
    double length;

public:
    void setLength(double len);
    double getLength(void);
    Line(double len); // This is the constructor
    Line(Line& p);
};
// Member function definition including constructor
Line::Line(double len)
{
    cout<<"constructor called"<<endl;
    cout << "Object is being created , length =" << len << endl;
    length = len;
}
Line::Line(Line &p)
{
    cout<<" copy constructor called"<<endl;
    cout << "Object is being created , length =" << p.length<< endl;
    length = p.length;
}
void Line::setLength(double len)
{
    length = len;
}
double Line::getLength(void)
{
    return length;
}
// Main function for the program
int main()
{
    double len;
    cout << "Enter the Length" << endl;
    cin >> len;
    Line line(len);
    Line l3=line;
    cout<<l3.getLength()<<endl;
    // get initially set length
    cout << "Length of line :" << line.getLength() << endl;
    Line temp(line);
    cout << "Length of line :" <<temp.getLength() << endl;
    return 0;
}