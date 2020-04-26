#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool comp(pair<int, int> p1, pair<int, int> p2){
	if(p1.first != p2.first)return p1.first > p2.first;
	return p1.second < p2.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int a, b, c, d;cin >> a >> b >> c >> d;
		int sum = a + b + c + d;
		arr.push_back({sum, i});
	}
	sort(arr.begin(), arr.end(), comp);
	for(int i = 0;i < n;i++){
		if(arr[i].second == 0)cout << i + 1;
	}
}
