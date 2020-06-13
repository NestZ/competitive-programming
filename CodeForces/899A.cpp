#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int co = 0;
	int ct = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t == 1)co++;
		else ct++;
	}
	int ans = 0;
	ans += min(co, ct);
	co -= ans;
	ans += co / 3;
	cout << ans;
}
