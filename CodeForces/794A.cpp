#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;cin >> a >> b >> c;
	int n;cin >> n;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t > b && t < c)ans++;
	}
	cout << ans;
}
