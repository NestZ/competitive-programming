#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	ll ans = 0;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	vector<int> cnt_b(n);
	vector<ll> pre_b(n + 1);
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++)cin >> b[i];
	for(int i = 0;i < n;i++)cin >> c[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for(int i = 0;i < n;i++){
		cnt_b[i] = int(c.end() - lower_bound(c.begin(), c.end(), b[i] + 1));
	}
	for(int i = 1;i <= n;i++){
		pre_b[i] += cnt_b[i - 1] + pre_b[i - 1];
	}
	for(int i = 0;i < n;i++){
		int fst = int(lower_bound(b.begin(), b.end(), a[i] + 1) - b.begin());
		ans += pre_b[n] - pre_b[fst];
	}
	cout << ans << endl;
}
