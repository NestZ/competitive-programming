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
		arr.emplace_back(b, a);
	}
	sort(arr.begin(), arr.end());
	int cur = 0;
	for(int i = 0;i < n;i++){
		cur += arr[i].second;
		if(cur > arr[i].first)return cout << "No\n", 0;
	}
	cout << "Yes\n";
}
