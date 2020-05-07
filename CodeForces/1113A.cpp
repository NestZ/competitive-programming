#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, v;cin >> n >> v;
	int w = n - 1;
	int ans = 0;
	int curr = 0;
	for(int i = 1;i <= n;i++){
		int c = v - curr;
		int e = min(w, c);
		ans += e * i;
		w -= e;
		curr += e - 1;
	}
	cout << ans;
}
