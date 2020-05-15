#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool f(int n){
	while(n > 0){
		int t = n % 10;
		if(t == 8)return true;
		n /= 10;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	if(n >= -8){
		for(int i = n + 1;;i++){
			if(f(i))return cout << i - n, 0;
		}
	}
	else{
		int m = abs(n);
		for(int i = m - 1;;i--){
			if(f(i))return cout << m - i, 0;
		}
	}
}
