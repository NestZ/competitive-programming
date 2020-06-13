#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, r;cin >> n >> m >> r;
	int minb = INT_MAX;
	int maxs = INT_MIN;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		minb = min(minb, t);
	}
	for(int i = 0;i < m;i++){
		int t;cin >> t;
		maxs = max(maxs, t);
	}
	if(minb >= maxs){
		cout << r;
		return 0;
	}
	int cnt = r / minb;
	r -= cnt * minb;
	r += cnt * maxs;
	cout << r;
}
