#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	ll ans = 0;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++)cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i = 0;i < n;i++){
		ans += abs(a[i] - b[i]);
	}
	cout << ans << endl;
}
