#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	int ans = INT_MIN;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		int gett = (b <= k ? a : a - (b - k));
		ans = max(ans, gett);
	}
	cout << ans;
}
