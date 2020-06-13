#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	if(n <= 2)return cout << 1, 0;
	int ans = n / 3 * 2;
	if(n % 3 != 0)ans++;
	cout << ans;
}
