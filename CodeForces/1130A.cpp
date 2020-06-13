#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int p = 0;
	int ne = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t < 0)ne++;
		else if(t > 0)p++;
	}
	if(p >= (n + 1) / 2)cout << 1;
	else if(ne >= (n + 1) / 2)cout << -1;
	else cout << 0;
}
