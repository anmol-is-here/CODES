#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 2, 4, 0, 6};
    int sum = 7, count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            for (int k = j+1; k < 6; k++)
            {
                if (arr[i]+arr[j]+arr[k] == sum) {
                    count++;
                }
            }   
        }
    }
    cout<<count<<endl;
    return 0;
}