#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	map<string, string> m;
	m["purple"] = "Power";
	m["green"] = "Time";
	m["blue"] = "Space";
	m["orange"] = "Soul";
	m["red"] = "Reality";
	m["yellow"] = "Mind";
	vector<string> ans;
	map<string, int> cnt;
	for(int i = 0;i < n;i++){
		string t;cin >> t;
		cnt[t]++;
	}
	for(pair<string, string> p : m){
		if(cnt[p.first] == 0)ans.push_back(p.first);
	}
	cout << ans.size() << endl;
	for(string s : ans)cout << m[s] << endl;
}
