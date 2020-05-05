#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, gx, gy;cin >> n >> gx >> gy;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int x, y;cin >> x >> y;
		arr.push_back({x, y});
	}
	vector<bool> d(n, false);
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(d[i])continue;
		d[i] = true;
		ans++;
		for(int j = i + 1;j < n;j++){
		int x1 = gx;
		int y1 = gy;
		int x2 = arr[i].first;
		int y2 = arr[i].second;
		int x3 = arr[j].first;
		int y3 = arr[j].second;
		if((x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1))d[j] = true;
		}
	}
	cout << ans;
}
