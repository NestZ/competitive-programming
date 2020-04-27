#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int ans = n;
	int mx = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if((t + m - 1) / m >= mx){
			ans = i + 1;
			mx = (t + m - 1) / m;
		}
	}
	cout << ans;
}
