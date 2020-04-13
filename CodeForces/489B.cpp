#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> b(n);
	for(int i = 0;i < n;i++)cin >> b[i];
	int m;cin >> m;
	vector<int> g(m);
	for(int i = 0;i < m;i++)cin >> g[i];
	int cn = 0;
	int cm = 0;
	sort(b.begin(), b.end());
	sort(g.begin(), g.end());
	int ans = 0;
	while(cn < n && cm < m){
		if(abs(b[cn] - g[cm]) <= 1){
			ans++;
			cn++;
			cm++;
		}
		else if(b[cn] < g[cm])cn++;
		else cm++;
	}
	cout << ans;
}
