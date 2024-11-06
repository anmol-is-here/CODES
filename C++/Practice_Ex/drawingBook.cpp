#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p, count = 0;
	cin>>n>>p;
	int z = n/2;
	if (n%2 == 0) {
		if (p < z) {
			for (int i = 0; i < p; i++)
			{
				count++;
			}
			cout<<count/2;
		}
		else {
			for (int i = n; i >= p ; i--)
			{
				count++;
			}
			cout<<count/2;
		}
	}
	else {
		if (p <= z) {
			for (int i = 0; i < p; i++)
			{
				count++;
			}
			cout<<count/2;
		}
		else {
			for (int i = n; i > p ; i--)
			{
				count++;
			}
			cout<<count/2;
		}
	}
}