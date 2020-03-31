#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	long long n;cin >> n;
	if(n & 1)cout << -((n + 1) / 2);
	else cout << n / 2;
}
