#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> p_cnt(51);
vector<ll> len(51);

ll eat(int n, ll x){
	if(x == 0)return 0;
	if(x == 1){
		if(n == 0)return 1;
		return 0;
	}
	if(x >= len[n] - 1)return p_cnt[n];
	ll ans = 0;
	if(x > len[n - 1] + 1){
		ans += p_cnt[n - 1] + 1;
		ans += eat(n - 1, x - len[n - 1] - 2);
	}
	else if(x <= len[n - 1] + 1){
		ans += eat(n - 1, x - 1);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	ll x;cin >> x;
	p_cnt[0] = 1;	
	len[0] = 1;
	for(int i = 1;i < 51;i++){
		p_cnt[i] = p_cnt[i - 1] * 2 + 1;
		len[i] = len[i - 1] * 2 + 3;
	}
	cout << eat(n, x) << endl;
}
