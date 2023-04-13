#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int num;
    while (num-- > 0)
    {
        int n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            v.push_back(ele);
        }
        const int N = 300;
        vector<int> freq(N, 0);
        int ans;


        for (int i = 0; i < n; i++)
        {
            freq[v[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (freq [i] == 3) {
                cout<<0<<endl;
            }
            else if (freq[i] == 2) {
                ans = i;
                freq[i] = -1;
            }
            else {
                cout<<freq[i-1] - freq[i]<<endl;
            }
        } 
        vector <int> answ;
        for (int i = 0; i < n; i++) {
            answ[i] = ans - v[i];
        }
        int min = *min_element(answ.begin(), answ.end());
        cout<<min<<endl;
    }
    return 0;
}