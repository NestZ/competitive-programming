#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	map<int, int> m;
	set<char> se;
	bool flag = false;
	for(int i = 0;i < n;i++){
		m[s[i]]++;
		se.insert(s[i]);
		if(m[s[i]] > 1)flag = true;
	}
	if(flag || se.size() == 1)cout << "Yes";
	else cout << "No";
}
