#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool is(int n){
	for(int i = 2;i * i <= n;i++){
		if(n % i == 0)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 1;;i++){
		int num = n * i + 1;
		if(!is(num))return cout << i, 0;
	}
}
