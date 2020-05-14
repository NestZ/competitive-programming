#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int sum = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		sum += t;
	}
	int ans = 0;
	for(int i = 1;i <= 5;i++){
		if((sum + i) % (n + 1) != 1)ans++;
	}
	cout << ans;
}
