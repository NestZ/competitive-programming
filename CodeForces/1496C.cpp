#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> miner;
		vector<int> dia;
		for(int i = 0;i < 2 * n;i++){
			int x, y;cin >> x >> y;
			if(x == 0)miner.push_back(abs(y));
			else if(y == 0)dia.push_back(abs(x));
		}
		sort(miner.begin(), miner.end());
		sort(dia.begin(), dia.end());
		double ans = 0;
		for(int i = 0;i < n;i++){
			ans += sqrt((double)miner[i] * (double)miner[i] +
					(double)dia[i] * (double)dia[i]);
		}
		printf("%.10lf\n", ans);
	}
}
