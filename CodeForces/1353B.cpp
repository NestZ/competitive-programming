#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		vector<int> a(n);
		vector<int> b(n);
		int sum = 0;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			sum += a[i];
		}
		for(int i = 0;i < n;i++)cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int l = 0;
		int r = n - 1;
		for(int i = 0;i < k;i++){
			sum += max(0, b[r--] - a[l++]);
		}
		cout << sum << endl;
	}
}
