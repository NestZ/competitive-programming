#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, k;cin >> n >> k;
	k = 240 - k;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(k - i * 5 < 0)break;
		else k -= i * 5;
		ans++;
	}
	cout << ans;
}
