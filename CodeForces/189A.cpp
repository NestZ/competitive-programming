#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, a, b, c;cin >> n >> a >> b >> c;
	int ans = 0;
	for(int i = 0;i <= n / a;i++){
		for(int j = 0;j <= n / b;j++){
			int t = n - (a * i + b * j);
			if(t < 0)continue;
			if(t % c == 0)ans = max(ans, i + j + t / c);
		}
	}
	cout << ans;
}
