#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int cnt(int n){
	int ans = 0;
	for(int i = 2;i * i <= n;i++){
		if(n % i == 0){
			ans++;
			while(n % i == 0)n /= i;
		}
	}
	if(n > 1)ans++;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(cnt(i) == 2)ans++;
	}
	cout << ans;
}
