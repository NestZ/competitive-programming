#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;cin >> k;
	map<char, int> m;
	string s;cin >> s;
	int n = s.length();
	for(int i = 0;i < n;i++){
		m[s[i]]++;
	}
	string t = "";
	for(pair<char, int> p : m){
		if(p.second % k != 0)return cout << -1, 0;
		t += string(p.second / k, p.first);
	}
	string ans = "";
	for(int i = 0;i < k;i++)ans += t;
	cout << ans;
}
