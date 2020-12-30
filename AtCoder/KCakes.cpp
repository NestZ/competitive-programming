#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int sum, t;cin >> sum >> t;
	vector<int> cnt(t);
	int mx = 0;
	for(int i = 0;i < t;i++){
		cin >> cnt[i];
		mx = max(mx, cnt[i]);
	}
	cout << max(0, mx - sum - 1 + mx) << endl;
}
