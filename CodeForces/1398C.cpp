#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		string s;cin >> s;
		vector<ll> arr(n);
		for(ll i = 0;i < n;i++)arr[i] = s[i] - '0';
		vector<ll> pre(n + 1);
		map<ll, ll> m;
		for(ll i = 1;i <= n;i++){
			pre[i] += arr[i - 1] + pre[i - 1];
		}
		for(ll i = 0;i <= n;i++)m[pre[i] - i]++;
		ll ans = 0;
		for(pair<ll, ll> p : m)ans += p.second * (p.second - 1) / 2;
		cout << ans << endl;
	}
}
