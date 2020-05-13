#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = INT_MIN;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		int s = sqrt(t);
		if(s * s != t)ans = max(ans, t);
	}
	cout << ans;
}
