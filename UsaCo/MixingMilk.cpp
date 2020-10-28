/*
ID: nestz
LANG: C++14
TASK: milk
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("milk.out", "w", stdout);
	freopen("milk.in", "r", stdin);

	int n, m;cin >> n >> m;
	int ans = 0;
	vector<pair<int, int>> price(m);
	for(int i = 0;i < m;i++){
		int p, a;cin >> p >> a;
		price[i] = make_pair(p, a);
	}
	sort(price.begin(), price.end());
	for(int i = 0;i < m;i++){
		if(n == 0)break;
		int buy = min(n, price[i].second);
		n -= buy;
		ans += buy * price[i].first;
	}
	cout << ans << endl;
}
