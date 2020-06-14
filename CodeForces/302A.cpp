#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int ne = 0;
	int p = 0;
	for(int i = 1;i <= n;i++){
		int t;cin >> t;
		if(t < 0)ne++;
		else p++;
	}
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		int w = b - a + 1;
		if(w == 1 || (w & 1))cout << 0;
		else if(ne >= w / 2 && p >= w / 2)cout << 1;
		else cout << 0;
		cout << endl;
	}
}
