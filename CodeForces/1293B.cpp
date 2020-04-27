#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	double ans = 0;
	for(int i = n;i > 0;i--){
		ans += 1.0 / i;
	}
	cout << ans;
}
