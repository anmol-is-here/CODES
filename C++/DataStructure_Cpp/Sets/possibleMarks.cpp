#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, p, q;
    cin>>n>>p>>q;
    set<int> s;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n; j++){
            int correct = i;
            int incorrect = j;
            int unattemped = n - (i + j);
            if(unattemped >= 0){
                int score = correct*p + incorrect*q;
                s.insert(score);
            } else{
                break;
            }
        }
    }
    cout<<s.size();
    
    return 0;
}