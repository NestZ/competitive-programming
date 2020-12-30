#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;cin >> s >> t;
	vector<int> cnts(26);
	vector<int> cntt(26);
	for(char c : s)cnts[c - 'a']++;
	for(char c : t)cntt[c - 'a']++;
	sort(cnts.begin(), cnts.end());
	sort(cntt.begin(), cntt.end());
	bool ans = true;
	for(int i = 0;i < 26;i++){
		if(cnts[i] != cntt[i])ans = false;
	}
	if(ans)cout << "Yes";
	else cout << "No";
	cout << endl;
}
