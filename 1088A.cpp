#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int a = 1;a <= n;a++){
		for(int b = 1;b <= n;b++){
			if(a % b == 0 && a / b < n && a * b > n)return cout << a << ' ' << b, 0;
		}
	}
	cout << -1;
}
