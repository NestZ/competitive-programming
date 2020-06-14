#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	map<int, int> m;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t != 0)m[t]++;
	}
	int ans = 0;
	for(pair<int, int> p : m){
		if(p.second > 2)return cout << -1, 0;
		else if(p.second == 2)ans++;
	}
	cout << ans;
}
