#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	if(m < n - 1 || (m + 1) / 2 > n + 1)return cout << -1, 0;
	string ans = "";
	if(n > m){
		ans += '0';
		n--;
	}
	while(n > 0 || m > 0){
		if(m / 2 > n && m >= 2){
			ans += "11";
			m -= 2;
		}
		else{
			ans += '1';
			m--;
		}
		if(n > 0){
			ans += '0';
			n--;
		}
	}
	cout << ans;
}
