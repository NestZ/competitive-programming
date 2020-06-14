#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = INT_MAX;
	for(int i = 1;i * i <= n;i++){
		if(n % i != 0)continue;
		int w = n / i;
		ans = min(ans, 2 * w + 2 * i);	
	}
	cout << ans;
}
