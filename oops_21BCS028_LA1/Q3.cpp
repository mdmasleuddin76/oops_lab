#include <iostream>
using namespace std;

class Clock
{
private:
    int hour;
    int minute;
    int second;
    string meridian;

public:
    void setClock(int h, int m, int s, string mer)
    {
        hour = h;
        minute = m;
        second = s;
        meridian = mer;
    }

    void displayStandard()
    {
        cout << hour << ":" << minute << ":" << second << " " << meridian << endl;
    }

    void displayMilitary()
    {
        if (meridian == "PM" && hour != 12)
        {
            cout << hour + 12 << minute << endl;
        }
        else if (meridian == "AM" && hour == 12)
        {
            cout << "00" << minute << endl;
        }
        else
        {
            cout << hour << minute << endl;
        }
    }
};

int main()
{
    int hour,minute,second;
    string meridian;
    Clock myClock;
    cout << "Enter Hour" << endl;
    cin>>hour;
    cout << "Enter Minute" << endl;
    cin>>minute;
    cout << "Enter Seconds" << endl;
    cin>>second;
    cout<<"Enter the meridian"<<endl;
    cin>>meridian;
    myClock.setClock(hour,minute,second,meridian);
    cout << "Standard Format: ";
    myClock.displayStandard();
    cout << "Military Format: ";
    myClock.displayMilitary();
    return 0;
}