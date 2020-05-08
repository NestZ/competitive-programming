#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	string s;cin >> s;
	set<char> sc;
	map<char, int> m;
	int mn = INT_MAX;
	for(int i = 0;i < n;i++){
		m[s[i]]++;
		sc.insert(s[i]);
	}
	if(sc.size() != k)return cout << 0, 0;
	for(pair<char, int> p : m)mn = min(mn, p.second);
	cout << k * mn;
}
