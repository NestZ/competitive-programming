#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		arr.push_back({a, b});
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		bool u = false;
		bool d = false;
		bool l = false;
		bool r = false;
		for(int j = 0;j < n;j++){
			if(i == j)continue;
			if(arr[j].first == arr[i].first && arr[j].second > arr[i].second)u = true;
			if(arr[j].first == arr[i].first && arr[j].second < arr[i].second)d = true;
			if(arr[j].first < arr[i].first && arr[j].second == arr[i].second)l = true;
			if(arr[j].first > arr[i].first && arr[j].second == arr[i].second)r = true;
		}
		if(u && d && l && r)ans++;
	}
	cout << ans;
}
