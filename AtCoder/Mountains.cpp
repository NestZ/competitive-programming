#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = 0;
	vector<pair<int, int>> f;
	vector<pair<int, int>> s;
	map<int, int> fst;
	map<int, int> snd;
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		if(i & 1)snd[num]++;
		else fst[num]++;
	}
	for(auto p : fst)f.emplace_back(p.second, p.first);
	for(auto p : snd)s.emplace_back(p.second, p.first);
	sort(f.rbegin(), f.rend());
	sort(s.rbegin(), s.rend());
	if(f[0].second != s[0].second){
		ans = n - f[0].first - s[0].first;
	}
	else{
		ans = min(n - f[1].first - s[0].first, n - f[0].first - s[1].first);
	}
	cout << ans << endl;
}
