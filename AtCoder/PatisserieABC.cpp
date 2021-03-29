#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	ll ans = 0;
	vector<vector<ll>> c(n, vector<ll>(3));
	for(auto &cur : c)cin >> cur[0] >> cur[1] >> cur[2];
	for(int i = 0;i < (1 << 3);i++){
		vector<ll> s;
		for(int j = 0;j < n;j++){
			ll sum = 0;
			for(int k = 0;k < 3;k++){
				sum += (i & (1 << k)) == 0 ? c[j][k] : -c[j][k];
			}
			s.push_back(sum);
		}
		sort(s.rbegin(), s.rend());

		ll sum = 0;
		for(int j = 0;j < m;j++)
			sum += s[j];
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

