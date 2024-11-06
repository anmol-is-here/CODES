#include<bits/stdc++.h>
#include<vector>
using namespace std;
// Function to sort 0's and 1's...

void sortZerosOnes(vector <int> &v) {
    int count = 0;
    for (int ele:v) {
        if (ele == 0) {
            count++;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (i<count) {
            v[i] = 0;
        }
        else {
            v[i] = 1;
        }
    }   

    // Another method to sort 0's and 1's...

    int left_ptr = 0;
    int right_ptr = v.size()-1;

    while (left_ptr < right_ptr) {
        if (v[left_ptr] == 1 && v[right_ptr] == 0) {
            v[left_ptr++] = 0;
            v[right_ptr--] = 1;
        }
        else if (v[left_ptr] == 0) {
            left_ptr++;
        }
        else if (v[right_ptr] == 1) {
            right_ptr--;
        }
    }
    return;
}

// Function to sort even and odd numbers...

void sortByParity(vector <int> &v) {
    int left_ptr = 0;
    int right_ptr = (v.size()-1);

    while (left_ptr < right_ptr) {
        if (v[left_ptr]%2 ==  1&& v[right_ptr]%2 == 0) {
            swap(v[left_ptr], v[right_ptr]);
            left_ptr++;
            right_ptr--;
        }
        else if (v[left_ptr]%2 == 0) {
            left_ptr++;
        }
        else if (v[right_ptr]%2 == 1) {
            right_ptr--;
        }
    }
    return;
}

// Function to sort the square of values in an array...

void sortSquareOfAbsValue(vector <int> &v) {
    int left_ptr = 0;
    int right_ptr = (v.size()-1);
    
    vector <int> squr;

    while (left_ptr <= right_ptr) {
        if (abs(v[left_ptr]) > abs(v[right_ptr])) {
            squr.push_back(v[left_ptr]*v[left_ptr]);
            left_ptr++;
        }
        else {
            squr.push_back(v[right_ptr]*v[right_ptr]);
            right_ptr--;
        }
    }

    reverse(squr.begin(),squr.end());

    for (int i = 0; i < squr.size(); i++)
    {
        cout<<squr[i]<<" ";
    }
    cout<<endl;
    return;
}

int main() {
    int n;
    cin>>n;

    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    
    // sortZerosOnes(v);
    // sortByParity(v);
    sortSquareOfAbsValue(v);
    
    return 0;
}
