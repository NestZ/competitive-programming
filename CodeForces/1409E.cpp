#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		vector<int> x(n);
		vector<int> y(n);
		for(int i = 0;i < n;i++)cin >> x[i];
		for(int i = 0;i < n;i++)cin >> y[i];
		sort(x.begin(), x.end());
		vector<int> l(n);
		vector<int> r(n);
		int pos = n - 1;
		for(int i = n - 1;i >= 0;i--){
			while(x[pos] - x[i] > k)pos--;
			r[i] = pos - i + 1;
		}
		for(int i = n - 2;i >= 0;i--)r[i] = max(r[i], r[i + 1]);
		pos = 0;
		for(int i = 0;i < n;i++){
			while(x[i] - x[pos] > k)pos++;
			l[i] = i - pos + 1;
		}
		for(int i = 1;i < n;i++)l[i] = max(l[i], l[i - 1]);
		int ans = 1;
		for(int i = 0;i < n - 1;i++)ans = max(ans, l[i] + r[i + 1]);
		cout << ans << endl;
	}
}
