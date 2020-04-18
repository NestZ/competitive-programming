#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m;cin >> n >> m;
	int t = max(n, m);
	int ans = 0;
	for(int i = 0;i * i <= t;i++){
		for(int j = 0;j * j <= t;j++){
			if(i * i + j == n && i + j * j == m)ans++;
		}
	}
	cout << ans;
}
