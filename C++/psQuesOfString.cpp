#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void strReverse(char* p){
    char* q, r;
    q=p;
    while(*q!='\0'){
        q++;

    }
    q--;
    while(p<q){
        r=*p;
        *p=*q;
        *q=r;
        p++;
        q--;
    }
}


int main() {
    // char a[10];
    // scanf("%s",a);
    // strReverse(a);
    // cout<<a<<endl;


    // char a[100], *j;
    // cout<<"Enter string";
    // scanf("%s",a);
    // j=a;
    // while(*j!='\0'){
    //     if(*j>=65 && *j<=90){
    //         *j=*j+32;
    //     }
    //     else{
    //         *j=*j-32;
    //     }
    //     j++;
    // }
    // cout<<a;



    return 0;
}