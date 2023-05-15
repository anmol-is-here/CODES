#include <iostream>
#include <vector>
#include <string>
using namespace std;

int onesLength(string &s, int k) {
    int start {0};
    int end {0};
    int zeroCount {0};
    int maxLen {0};
    while (end<s.length()) {
        if (s[end] == '0') {
            zeroCount++;
        }
        while (zeroCount > k) {
            if (s[start] == '0') {
                zeroCount--;
            }
            start++;
        }
        maxLen = max(maxLen, (end-start+1));
        end++;
    }
    return maxLen;
}

int main() {
    string str ("10001001");
    int k {3};                    // k is maximum numberr of zeros which can be replaced by 1 to get maximum length.
    cout<<onesLength(str, k);
    return 0;
}