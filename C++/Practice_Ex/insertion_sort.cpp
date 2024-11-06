#include <iostream>
using namespace std;

int main()
{
    int i, j, ele, a[20], size, min, var_p;
    cout << "Enter the size of array";
    cin >> size;
    cout << "Enter elements \n";
    for (i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < size - 1; i++)
    {
        min = a[i];
        var_p = i;
        for (j = i + 1; j < size; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                var_p = j;
            }
        }
        ele = a[i];
        a[i] = a[var_p];
        a[var_p] = ele;
    }

    cout << "sorted array is \n";
    for (i = 0; i < 1; i++)
    {
        cout << a[i] << "  ";
    }

    return 0;
}