#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = n / 4;
	if((n - 2) & 1)return cout << 0, 0;
	if(n % 4 == 0)ans--;
	cout << ans;
}
