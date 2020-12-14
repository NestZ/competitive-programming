#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = 0;
	map<int, int> m;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		m[t]++;
	}
	for(auto p : m){
		if(p.second > p.first)ans += p.second - p.first;
		else if(p.second < p.first)ans += p.second;
	}
	cout << ans << endl;
}
