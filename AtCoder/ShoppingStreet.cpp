#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<int> f(n);
	vector<vector<int>> p(n, vector<int>(11));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 10;j++){
			int b;cin >> b;
			f[i] += (b << j);
		}
	}
	for(int i = 0;i < n;i++)
		for(int j = 0;j <= 10;j++)
			cin >> p[i][j];	
	int ans = INT_MIN;
	for(int i = 1;i < (1 << 10);i++){
		int pr = 0;
		for(int j = 0;j < n;j++){
			pr += p[j][__builtin_popcount(i & f[j])];
		}
		ans = max(ans, pr);
	}
	cout << ans << endl;
}
