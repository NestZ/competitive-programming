#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, h;cin >> n >> h;
	int ans = 0;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		arr.emplace_back(b, a);
	}
	sort(arr.rbegin(), arr.rend());
	pair<int, int> mx_w = arr[0];
	int mx_index = 0;
	for(int i = 1;i < n;i++){
		if(arr[i].second > mx_w.second){
			mx_index = i;
			mx_w = arr[i];
		}
		else if(arr[i].second == mx_w.second){
			if(arr[i].first < mx_w.first){
				mx_index = i;
				mx_w = arr[i];
			}
		}
	}
	for(int i = 0;i < n;i++){
		if(i == mx_index)continue;
		if(mx_w.first >= h){
			ans++;
			h -= mx_w.first;
			break;
		}
		if(arr[i].first > mx_w.second){
			h -= arr[i].first;
			ans++;
			if(h <= 0)break;
		}
		else break;
	}
	if(h > 0){
		if(mx_w.first > mx_w.second){
			ans += (h - mx_w.first + (mx_w.second - 1)) / mx_w.second + 1;
		}
		else ans += (h + mx_w.second - 1) / mx_w.second;
	}
	cout << ans << endl;
}
