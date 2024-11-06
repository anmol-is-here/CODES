#include<iostream>
using namespace std;

bool palin(int num, int *temp){
    if(num > 0 and num < 9) {
        int lastDigitOfTemp = (*temp)%10;
        (*temp) /= 10;
        return (num == lastDigitOfTemp);
    }
    bool result = (palin(num/10, temp) and (num%10) == ((*temp)%10));
    (*temp) /= 10;
    return result;

}

int main() {
    int num = 121;
    int anotherNum = num;
    int *temp = &anotherNum;
    cout<<palin(num, temp);
    return 0;
}