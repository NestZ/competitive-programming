#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int l = 0;
	int r = 0;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		arr.push_back({a, b});
		l += a;
		r += b;
	}
	int curr = abs(l - r);
	int ans = 0;
	for(int i = 0;i < n;i++){
		l -= (arr[i].first - arr[i].second);
		r -= (arr[i].second - arr[i].first);
		if(abs(l - r) > curr){
			ans = i + 1;
			curr = abs(l - r);
		}
		l -= (arr[i].second - arr[i].first);
		r -= (arr[i].first - arr[i].second);
	}
	cout << ans;
}
