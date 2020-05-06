#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	int cnt = 0;
	map<char, int> m;
	for(int i = 0;i < n;i++)m[s[i]]++;
	for(pair<char, int> p : m)
		if(p.second & 1)cnt++;
	if(cnt <= 1)cout << "First";
	else if(cnt & 1)cout << "First";
	else cout << "Second";
}
