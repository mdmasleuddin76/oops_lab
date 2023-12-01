#include <iostream>
using namespace std;

class Line
{
private:
    double length;

public:
    void setLength(double len);
    double getLength(void);
    Line(); // This is the constructor
    ~Line();
};
// Member function definition including constructor
Line::Line()
{
    cout << "Object is being created"<< endl;
}
Line::~Line()
{
    cout << "Object is being Deleted"<< endl;
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
    Line line;
    // get initially set length
    line.setLength(len);
    cout << "Length of line :" << line.getLength() << endl;

    return 0;
}