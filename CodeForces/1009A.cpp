#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<int> g(n);
	vector<int> b(m);
	for(int i = 0;i < n;i++)cin >> g[i];
	for(int i = 0;i < m;i++)cin >> b[i];
	int pg = 0;
	int pb = 0;
	int ans = 0;
	while(pg < n && pb < m){
		if(g[pg] <= b[pb]){
			pg++;
			pb++;
			ans++;
		}
		else pg++;
	}
	cout << ans;
}
