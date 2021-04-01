#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const ll INF = 1e15;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m, r;cin >> n >> m >> r;
	ll ans = INT64_MAX;
	vector<ll> go(r);
	vector<ll> perm(r);
	vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
	for(int i = 0;i < r;i++)cin >> go[i];
	for(int i = 0;i < r;i++)perm[i] = i;
	for(int i = 0;i < m;i++){
		ll a, b, c;cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j)dist[i][j] = 0;
				else dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	do{
		ll sum = 0;
		for(int i = 0;i < r - 1;i++){
			sum += dist[go[perm[i]]][go[perm[i + 1]]];
		}
		ans = min(ans, sum);
	}while(next_permutation(perm.begin(), perm.end()));
	cout << ans << endl;
}
