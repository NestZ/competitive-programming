#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		ll temp = n;
		vector<ll> ans;
		map<ll, ll> fac;
		for(ll i = 2;i * i <= n;i++){
			while(n % i == 0){
				fac[i]++;
				n /= i;
			}
		}
		if(n != 1)fac[n]++;
		ll mx_cnt = 0;
		ll mx_n = 0;
		for(auto p : fac){
			if(p.second > mx_cnt){
				mx_cnt = p.second;
				mx_n = p.first;
			}
		}
		ll cur_pro = pow(mx_n, mx_cnt);
		ll rem_pro = temp / cur_pro; 
		if(rem_pro % mx_n != 0){
			mx_cnt--;
			rem_pro *= mx_n;
		}
		cout << mx_cnt + 1 << endl;
		for(int i = 0;i < mx_cnt;i++)
			cout << mx_n << ' ';
		cout << rem_pro << endl;
	}
}
