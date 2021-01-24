#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

bool comp(pair<int, int> &a, pair<int, int> &b){
	int sa = a.first + a.second;
	int sb = b.first + b.second;
	return sa < sb;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	ll a = 0;
	ll b = 0;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int pa, pb;cin >> pa >> pb;
		arr.emplace_back(pa, pb);
	}
	sort(arr.rbegin(), arr.rend(), comp);
	for(int i = 0;i < n;i++){
		if(i & 1)b += arr[i].second;
		else a += arr[i].first;
	}
	cout << a - b << endl;
}
