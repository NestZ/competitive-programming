#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		arr.push_back({t, i});
	}
	sort(arr.rbegin(), arr.rend());
	int cnt = 0;
	vector<int> ans;
	for(int i = 0;i < n;i++){
		if(i == 0){
			cnt++;
			ans.push_back(arr[i].second + 1);
		}
		else{
			ans.push_back(arr[i].second + 1);
			cnt += arr[i].first * i + 1;
		}
	}
	cout << cnt << endl;
	for(int i : ans)cout << i << ' ';
}
