#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n, k;
string s;
vector<vector<int>> cnt(200005, vector<int>(26, 0));

int diff(int u, int v){
	int mx = 0;
	int ret = 0;
	for(int i = 0;i < 26;i++){
		ret += cnt[u][i] + cnt[v][i];
		mx = max(mx, cnt[u][i] + cnt[v][i]);
	}
	return ret - mx;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		cin >> n >> k >> s;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < 26;j++)
				cnt[i][j] = 0;
		for(int i = 0;i < n;i++)cnt[i % k][s[i] - 'a']++;
		int ans = 0;
		for(int i = 0;i < k;i++)ans += diff(i, k - i - 1);
		cout << ans / 2 << endl;
	}
}
