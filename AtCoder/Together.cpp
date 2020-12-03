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
		int num;cin >> num;
		m[num]++;
	}
	for(auto p : m){
		int cur = p.second;
		if(m.count(p.first + 1))cur += m[p.first + 1];
		if(m.count(p.first - 1))cur += m[p.first - 1];
		ans = max(ans, cur);
	}
	cout << ans << endl;
}
