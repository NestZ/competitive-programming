#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		arr.push_back({t, i});
	}
	sort(arr.begin(), arr.end());
	int curr = 0;
	set<int> s;
	for(int i = 0;i < n;i++){
		if(curr + arr[i].first <= k){
			curr += arr[i].first;
			s.insert(arr[i].second + 1);
		}
		else break;
	}
	cout << s.size() << endl;
	for(int i : s)cout << i << ' ';
}
