#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int a = 1, b = 1;
	int mn = INT_MAX;
	for(int i = 1;i * i <= n;i++){
		if(n % i == 0){
			int t = n / i;
			if(abs(i - t) < mn){
				a = i;
				b = t;
			}
		}
	}
	cout << a << ' ' << b;
}
