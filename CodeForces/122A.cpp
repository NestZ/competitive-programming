#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool is(int n){
	while(n > 0){
		if(n % 10 != 4 && n % 10 != 7)return false;
		n /= 10;
	}
	return true;
}

int main(){
	int n;cin >> n;
	for(int i = 1;i <= n;i++){
		if(is(i) && n % i == 0)return cout << "YES", 0;
	}
	cout << "NO";
}
