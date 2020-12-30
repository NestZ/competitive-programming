#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int x, l;cin >> x >> l;
		arr.emplace_back(x + l, x - l);
	}
	sort(arr.begin(), arr.end());
	int ans = 1;
	int cur_e = arr[0].first;
	for(int i = 1;i < n;i++){
		if(arr[i].second < cur_e)continue;
		ans++;
		cur_e = arr[i].first;
	}
	cout << ans << endl;
}
