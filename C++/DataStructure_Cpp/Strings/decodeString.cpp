/**  Space Complexity -> O(n) where n is length of decoded string
 *   Time Complexity -> O(n) where n is length of decoded string
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string decode(string s) {
    string result ("");


    for (int i=0; i<s.length(); i++) {
        if (s[i] != ']') {
            result.push_back(s[i]); 
        }
        else {
            string str ("");


            while (!result.empty() and result.back() != '[') {
                str.push_back(result.back());
                result.pop_back();
            }
            reverse(str.begin(), str.end());
            result.pop_back();

            string num ("");
            while (!result.empty() and (result.back()>='0' and result.back()<='9')) {
                num.push_back(result.back());
                result.pop_back();
            }

            reverse(num.begin(), num.end());
            int int_num = stoi(num);

            while (int_num) {
                result += str;
                int_num--;
            }
        }
    }
    return result;
}

int main() {
    string str ("2[a2[b]3[c]]");

    cout<<decode(str);

    return 0;
}