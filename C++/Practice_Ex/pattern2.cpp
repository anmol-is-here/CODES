#include <iostream>
using namespace std;
int main()
{
    int n = 7;
    // cin >> n;
    cout << "Input number is " << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1)
            {
                cout << "*";
            }
            else
            {
                for (j = n - i; j > 1; j--)
                {
                    cout << " ";
                }
                cout << "*";
                break;
            }
        }
        cout << endl;
    }
}