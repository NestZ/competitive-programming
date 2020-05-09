#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	string s;cin >> s;
	set<char> se;
	for(int i = 0;i < k;i++){
		char t;cin >> t;
		se.insert(t);
	}
	ll ans = 0;
	ll curr = 0;
	for(int i = 0;i < n;i++){
		if(se.count(s[i]) != 0)curr++;
		else{
			ans += curr * (curr + 1) / 2;
			curr = 0;
		}
	}
	if(curr != 0)ans += curr * (curr + 1) / 2;
	cout << ans;
}
