#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		int cnt = 0;
		while(t > 0){
			if(t % 10 == 4 || t % 10 == 7)cnt++;
			t /= 10;
		}
		if(cnt <= k)ans++;
	}
	cout << ans;
}
