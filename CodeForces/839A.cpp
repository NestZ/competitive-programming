#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	int curr = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		curr += t;
		int g = min(8, curr);
		curr -= g;
		k -= g;
		if(k <= 0)return cout << i + 1, 0;
	}
	cout << -1;
}
