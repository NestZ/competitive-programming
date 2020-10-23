/*
ID: nestz
LANG: C++14
TASK: milk2
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("milk2.out", "w", stdout);
	freopen("milk2.in", "r", stdin);

	int n;cin >> n;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int s, e;cin >> s >> e;
		arr.push_back({s, e});
	}
	sort(arr.begin(), arr.end());
	int mxi = 0;
	int last_end = arr[0].second;
	int mxm = arr[0].second - arr[0].first;
	int curm = mxm;
	for(int i = 1;i < n;i++){
		if(arr[i].second <= last_end)continue;
		if(arr[i].first > last_end){
			mxi = max(mxi, arr[i].first - last_end);
			mxm = max(mxm, curm);
			curm = arr[i].second - arr[i].first;
		}
		else{
			curm += arr[i].second - last_end;
		}
		last_end = arr[i].second;
	}
	cout << mxm << ' ' << mxi << endl;
}
