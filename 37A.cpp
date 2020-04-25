#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	set<int> s;
	map<int, int> m;
	int mx = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		s.insert(t);
		m[t]++;
		mx = max(mx, m[t]);
	}
	cout << mx << ' ' << s.size();
}
