#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	int n = s.length();
	vector<ll> cnt_a(n);
	ll ans = 0;
	for(int i = 0;i < n - 2;i++){
		if(s[i] == 'A'){
			cnt_a[i]++;
			if(i > 0)cnt_a[i] += cnt_a[i - 1];
		}
		if(cnt_a[i] != 0 && s[i + 1] == 'B' && s[i + 2] == 'C'){
			ans += cnt_a[i];
			cnt_a[i + 2] = cnt_a[i];
		}
	}
	cout << ans << endl;
}
