#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<pair<int, int>> arr;
	map<pair<int, int>, int> m;
	vector<pair<int, int>> ori;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		arr.push_back({t, i});
		ori.push_back({t, i});
	}
	sort(arr.rbegin(), arr.rend());
	int curr = 1;
	for(int i = 0;i < n;i++){
		if(i == 0)m[arr[i]] = curr;
		else{
			if(arr[i].first < arr[i - 1].first)m[arr[i]] = curr = i + 1;
			else m[arr[i]] = curr;
		}
	}
	for(int i = 0;i < n;i++)cout << m[ori[i]] << ' ';
}
