#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	string s;cin >> s;
	int cnt = count(s.begin(), s.end(), '1');
	vector<ll> mod_plus(n);
	vector<ll> mod_minus(n);
	vector<ll> ans(n);
	ll cur_plus = 1;
	ll cur_minus = 1;
	mod_plus[n - 1] = cur_plus % (cnt + 1);
	if(cnt == 1)mod_minus[n - 1] = 0;
	else mod_minus[n - 1] = cur_minus % (cnt - 1);
	ll sum_mod_plus = 0;
	ll sum_mod_minus = 0;
	for(int i = 1;i < n;i++){
		cur_plus = cur_plus * 2 % (cnt + 1);
		if(cnt == 1)cur_minus = 0;
		else cur_minus = cur_minus * 2 % (cnt - 1);
		mod_plus[n - i - 1] = cur_plus;
		mod_minus[n - i - 1] = cur_minus;
	}
	for(int i = 0;i < n;i++){
		if(s[i] == '1'){
			sum_mod_plus += mod_plus[i];
			sum_mod_minus += mod_minus[i];
		}
	}
	for(int i = 0;i < n;i++){
		ll num = 0;
		if(s[i] == '0'){
			int cur = 1;
			num = (sum_mod_plus + mod_plus[i]) % (cnt + 1);
			while(num != 0){
				cur++;
				num = num % __builtin_popcount(num);
			}
			ans[i] = cur;
		}
		else{
			int cur = 1;
			if(cnt == 1){
				num = 0;
				cur = 0;
			}
			else num = ((sum_mod_minus - mod_minus[i]) + (cnt - 1)) % (cnt - 1);
			while(num != 0){
				cur++;
				num = num % __builtin_popcount(num);
			}
			ans[i] = cur;
		}
	}
	for(int i : ans)
		cout << i << endl;
}
