#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
typedef long long int ll;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	ll n;cin >> n;
	bool valid = true;
	vector<ll> leaf(n + 1);
	vector<ll> ans(n + 2, 0);
	for(int i = 0;i <= n;i++)cin >> leaf[i];
	ll cur = 1;
	for(ll i = 0;i <= min(27ll, n - 1);i++, cur <<= 1){
		if(leaf[i] >= cur)valid = false;
		cur -= leaf[i];
	}
	for(int i = n;i >= 0;i--){
		ans[i] = ans[i + 1] + leaf[i];
	}
	for(ll i = 0;i <= min(27ll, n);i++){
		ans[i] = min(ans[i], (ll)(1ll << i));
	}
	for(int i = 0;i < n;i++){
		if((ans[i] - leaf[i]) * 2 < ans[i + 1]){
			ans[i + 1] = (ans[i] - leaf[i]) * 2;	
		}
	}
	if(leaf[n] != ans[n])
		valid = false;
	if(valid){
		ll res = 0;
		for(ll i : ans)
			res += i;
		cout << res;
	}
	else cout << -1;
	cout << endl;
}
