#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector <int> v;

    // cout<<"Size : "<<v.size()<<endl;
    // cout<<"Capacity : "<<v.capacity()<<endl;

    // v.push_back(1);
    // cout<<"Size : "<<v.size()<<endl;
    // cout<<"Capacity : "<<v.capacity()<<endl;

    // v.push_back(2);
    // cout<<"Size : "<<v.size()<<endl;
    // cout<<"Capacity : "<<v.capacity()<<endl;

    // v.push_back(3);
    // cout<<"Size : "<<v.size()<<endl;
    // cout<<"Capacity : "<<v.capacity()<<endl;

    // v.push_back(4);
    // cout<<"Size : "<<v.size()<<endl;
    // cout<<"Capacity : "<<v.capacity()<<endl;

    // v.resize(10);
    // cout<<"Size : "<<v.size()<<endl;
    // cout<<"Capacity : "<<v.capacity()<<endl;

    // v.pop_back();
    // v.pop_back();

    // cout<<"Size : "<<v.size()<<endl;
    // cout<<"Capacity : "<<v.capacity()<<endl;
    for (int i = 0; i < 5; i++) {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    cout<<endl;

    return 0;
}