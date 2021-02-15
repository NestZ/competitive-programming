#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<int> h(n);
	vector<int> p(n);
	vector<int> sum(n);
	for(int i = 0;i < n;i++)cin >> h[i];
	for(int i = 0;i < n;i++)cin >> p[i];
	sort(h.begin(), h.end());
	sort(p.rbegin(), p.rend());
	for(int i = 0;i < n;i++)sum[i] = h[i] + p[i];
	sort(sum.begin(), sum.end());
	ll ans = 0;
	for(int i = 1;i < n;i++)ans += sum[i] - sum[i - 1];
	cout << ans << endl;
}
