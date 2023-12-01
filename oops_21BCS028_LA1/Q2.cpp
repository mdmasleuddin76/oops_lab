#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (1)
    {
        int opt;
        cout << "Select an Option" << endl
             << "Enter 1 to Convert from Kg to Pound" << endl
             << "Enter 2 to Convert from POund to Kg" << endl
             << "Enter 3 to exit" << endl;
        cin >> opt;
        if (opt == 1)
        {
            double weight;
            cout << "Enter the Weight in (KG)" << endl;
            cin >> weight;
            cout << " Weight in Pound -->" << 2.20462 * weight << " Pound" << endl;
        }
        else if (opt == 2)
        {
            double weight;
            cout << "Enter the Weight in (Pound)" << endl;
            cin >> weight;
            cout << " Weight in Pound -->" << 0.453592 * weight << " KG" << endl;
        }
        else if (opt == 3)
            return 0;
        else
        {
            cout << "You Entered Wrong Key" << endl;
        }
    }
    return 0;
}