#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool notprime(int n){
	for(int i = 2;i * i <= n;i++){
		if(n % i == 0)return true;
	}
	return false;
}

int main(){
	int n;cin >> n;
	for(int i = 4;i < n;i++){
		int t = n - i;
		if(notprime(i) && notprime(t))return cout << i << ' ' << t, 0;
	}
}
