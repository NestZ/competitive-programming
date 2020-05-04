#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int k;cin >> k;
	vector<int> w;
	for(int i = 0;i < 26;i++){
		int t;cin >> t;
		w.push_back(t);
	}
	int n = s.length();
	int ans = 0;
	int mx = *max_element(w.begin(), w.end());
	for(int i = 0;i < n;i++){
		ans += w[s[i] - 'a'] * (i + 1);
	}
	for(int i = n + 1;i <= n + k;i++){
		ans += mx * i;
	}
	cout << ans;
}
