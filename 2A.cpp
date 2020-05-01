#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<pair<string, int>> arr;
	map<string, int> m;
	map<string, int> f;
	int mx = INT_MIN;
	for(int i = 0;i < n;i++){
		string s;cin >> s;
		int t;cin >> t;
		m[s] += t;
		arr.push_back({s, t});
	}
	set<string> c;
	for(pair<string, int> p : m)mx = max(mx, p.second);
	for(pair<string, int> p : m)if(p.second == mx)c.insert(p.first);
	for(int i = 0;i < n;i++){
		f[arr[i].first] += arr[i].second;
		if(f[arr[i].first] >= mx && c.count(arr[i].first) != 0)return cout << arr[i].first, 0;
	}
}
