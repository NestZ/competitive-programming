#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];
	vector<pair<pair<int, int>, pair<int, int>>> ans;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m - 1;j++){
			if(arr[i][j] % 2 == 0)continue;
			auto cur = make_pair(i + 1, j + 1);
			auto p = make_pair(i + 1, j + 2);
			ans.emplace_back(cur, p);
			arr[i][j]--;
			arr[i][j + 1]++;
		}
	}
	for(int i = 0;i < n - 1;i++){
		if(arr[i][m - 1] % 2 == 0)continue;
		auto cur = make_pair(i + 1, m);
		auto p = make_pair(i + 2, m);
		arr[i][m - 1]--;
		arr[i + 1][m - 1]++;
		ans.emplace_back(cur, p);
	}
	cout << ans.size() << endl;
	for(auto p : ans){
		auto p1 = p.first;
		auto p2 = p.second;
		cout << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << endl;
	}
}
