#include<iostream>
using namespace std;

int power(int base, int raise){
    if (raise == 0) return 1;

    if (raise == 1) return base;
    
    return (power(base, (raise-1)) * base);
}

int powerOptimized(int p, int q){
    if (q == 0){
        return 1;
    }
    if (q % 2 == 0){
        int result = powerOptimized(p, q/2);
        return result * result;
    }
    else{
        int result = powerOptimized(p, (q-1)/2);
        return result * result * p;
    }
}

int main() {
    int ans = power(2, 3);
    cout<<ans<<endl;
    return 0;
}