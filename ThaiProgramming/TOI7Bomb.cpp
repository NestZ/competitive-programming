#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<pair<int, int>> arr;
	vector<pair<int, int>> ans;
	vector<int> pre_mx(n + 1, INT_MIN);
	for(int i = 0;i < n;i++){
		int x, y;cin >> x >> y;
		arr.emplace_back(x, y);
	}
	sort(arr.begin(), arr.end());
	for(int i = n - 1;i >= 0;i--){
		pre_mx[i] = max(arr[i].second, pre_mx[i + 1]);
	}
	for(int i = 0;i < n;i++){
		auto temp = make_pair(arr[i].first + 1, INT_MIN);
		auto f = lower_bound(arr.begin() + i, arr.end(), temp);
		if(f == arr.end() || arr[i].second >= pre_mx[f - arr.begin()])
			ans.emplace_back(arr[i].first, -arr[i].second);
	}
	sort(ans.begin(), ans.end());
	for(auto p : ans){
		cout << p.first << ' ' << -p.second << endl;
	}
}
