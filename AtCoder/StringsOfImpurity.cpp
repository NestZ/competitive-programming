#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t;cin >> s >> t;
	ll ns = s.length();
	ll nt = t.length();
	vector<vector<ll>> fst(ns + 1, vector<ll>(26, -1));
	for(int i = ns - 1;i >= 0;i--){
		for(int j = 0;j < 26;j++){
			if(i == ns - 1)fst[i][j] = -1;
			else fst[i][j] = fst[i + 1][j];
		}
		fst[i][s[i] - 'a'] = i;
	}
	for(int i = 0;i < nt;i++){
		if(fst[0][t[i] - 'a'] == -1){
			cout << -1 << endl;
			return 0;
		}
	}
	ll ans = 0;
	ll cur_pos = fst[0][t[0] - 'a'];
	for(int i = 1;i < nt;i++){
		ll nxt = fst[cur_pos + 1][t[i] - 'a'];
		if(nxt == -1){
			ans += ns;
			cur_pos = fst[0][t[i] - 'a'];
		}
		else cur_pos = nxt;
	}
	cout << ans + cur_pos + 1 << endl;
}
