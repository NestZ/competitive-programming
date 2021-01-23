#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;cin >> n >> x;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	ll ans = 0;
	for(int i = 0;i < n - 1;i++){
		int cur = arr[i] + arr[i + 1];
		int rem = cur - x;
		if(rem > 0){
			int mn = min(rem, arr[i + 1]);
			ans += rem;
			rem -= mn;
			arr[i + 1] -= mn;
			if(rem > 0)arr[i] -= rem;
		}
	}
	cout << ans << endl;
}
