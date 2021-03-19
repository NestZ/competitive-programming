#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	set<pair<int, int>> useless;
	vector<pair<int, int>> ans;
	int r = n;
	int l = 1;
	if(n & 1)r--;
	while(l < r)
		useless.insert({l++, r--});
	for(int i = 1;i <= n - 1;i++){
		for(int j = i + 1;j <= n;j++){
			if(useless.count({i, j}) == 0)
				ans.emplace_back(i, j);
		}
	}
	cout << ans.size() << endl;
	for(auto p : ans)
		cout << p.first << ' ' << p.second << endl;
}
