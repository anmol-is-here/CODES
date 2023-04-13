#include<iostream>
using namespace std;

int main() {
    int size;
    cin>>size;
    int arr[size];
    for(int i = 0; i<size; i++) {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    // int count=0;
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            if (arr[i]+arr[j] == sum) {
                cout<<i;
            }
        }
    }
    // cout<<count;
    return 0;
}

/**
 * #include <iostream>
#include <vector>
using namespace std;
vector<int> targetsum(vector<int> &nums, int target)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
                ans.push_back(i);
            ans.push_back(j);
        }
    }
    return ans;
}
int main()
{
    vector<int> nums(5);
    int tar;
    cin >> tar;
    for (int i = 0; i < 5; i++)
    {
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }
    targetsum(nums, tar);
    return 0;
}
*/