#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m;cin >> n >> m;
	int ans = 0;
	while(n < m){
		if(m & 1){
			m++;
			ans++;
		}
		ans++;
		m >>= 1;
	}
	ans += n - m;
	cout << ans;
}
