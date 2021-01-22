#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	ll ans = 1;
	vector<ll> c(n);
	vector<ll> s(n);
	for(int i = 0;i < n;i++)cin >> c[i];
	for(int i = 0;i < n;i++)cin >> s[i];
	sort(c.begin(), c.end());
	sort(s.begin(), s.end());
	vector<ll> cnt(n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(c[i] <= s[j])cnt[i]++;
		}
	}
	for(int i = n - 1;i >= 0;i--){
		ans *= cnt[i] - ll(n - i - 1);
	}
	cout << ans << endl;
}
