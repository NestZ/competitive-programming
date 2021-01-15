#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	map<pair<char, char>, ll> m;
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		string num = to_string(i);
		auto p = make_pair(num[0], num[num.length() - 1]);
		m[p]++;
	}
	for(int i = 1;i <= 9;i++){
		for(int j = i;j <= 9;j++){
			auto p = make_pair(char('0' + i), char('0' + j));
			auto rp = make_pair(p.second, p.first);
			if(i != j) ans += m[p] * m[rp] * 2;
			else ans += m[p] * m[rp];
		}
	}
	cout << ans << endl;
}
