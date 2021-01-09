#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mx = 100005;
vector<bool> is_p(mx, true);
vector<bool> sim(mx, false);
vector<ll> cnt(mx, 0);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	is_p[0] = false;
	is_p[1] = false;
	for(ll i = 2;i < mx;i++){
		if(!is_p[i])continue;
		for(ll j = i * i;j < mx;j += i)
			is_p[j] = false;
	}
	for(int i = 1;i < mx;i += 2){
		if(is_p[i] && is_p[(i + 1) / 2])
			sim[i] = true;
	}
	for(int i = 0;i < mx;i++){
		if(sim[i])cnt[i]++;
		cnt[i] += cnt[i - 1];
	}
	int q;cin >> q;
	for(int i = 0;i < q;i++){
		int l, r;cin >> l >> r;
		cout << cnt[r] - cnt[l - 1] << endl;
	}
}
