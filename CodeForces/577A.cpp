#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, x;cin >> n >> x;
	int ans = 0;
	for(int i = 1;i * i <= x;i++){
		if(x % i != 0)continue;
		int t = x / i;
		if(i <= n && t <= n){
			if(i == t)ans++;
			else ans += 2;
		}
	}
	cout << ans;
}
