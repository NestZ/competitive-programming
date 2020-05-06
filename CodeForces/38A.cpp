#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> e(n - 1);
	for(int i = 0;i < n - 1;i++)cin >> e[i];
	int a, b;cin >> a >> b;
	a--;b--;
	int ans = 0;
	for(int i = a;i < b;i++)ans += e[i];
	cout << ans;
}
