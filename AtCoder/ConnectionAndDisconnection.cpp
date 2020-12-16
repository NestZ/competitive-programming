#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	ll k;cin >> k;
	ll n = s.length();
	vector<ll> same;
	ll cur = 1;
	for(int i = 1;i < n;i++){
		if(s[i] == s[i - 1])cur++;
		else{
			same.push_back(cur);
			cur = 1;
		}
	}
	same.push_back(cur);
	int len = same.size();
	if(len == 1){
		cout << same[0] * k / 2 << endl;
	}
	else{
		ll fst = same[0];
		ll mid = 0;
		ll lst = same[len - 1];
		ll ans = 0;
		for(int i = 1;i < len - 1;i++)mid += same[i] / 2;
		if(s[n - 1] != s[0])ans = (fst / 2 + mid + lst / 2) * k;
		else ans = (fst / 2) + (mid * k) + (lst / 2) + ((fst + lst) / 2 * (k - 1));
		cout << ans << endl;
	}
}
