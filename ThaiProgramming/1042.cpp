#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;cin >> n >> m >> k;
	vector<int> nn(10000, 0);
	vector<int> mm(10000, 0);
	for(int i = 0;i < k;i++){
		int x, y, r;cin >> x >> y >> r;
		nn[max(0, x - r)]++;
		nn[x + r + 1]--;
		mm[max(0, y - r)]++;
		mm[y + r + 1]--;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		nn[i] += nn[i - 1];
		ans = max(ans, nn[i]);
	}
	for(int i = 1;i <= m;i++){
		mm[i] += mm[i - 1];
		ans = max(ans, mm[i]);
	}
	cout << ans << endl;
}
