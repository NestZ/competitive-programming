#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> f(n + 1, 0);
		int e = -1;
		for(int i = 0;i < n;i++){
			int k;cin >> k;
			bool flag = false;
			for(int j = 0;j < k;j++){
				int m;cin >> m;
				if(f[m] == 0 && !flag){
					f[m]++;
					flag = true;
				}
			}
			if(!flag)e = i + 1;
		}
		if(e == -1)cout << "OPTIMAL" << endl;
		else{
			cout << "IMPROVE" << endl;
			cout << e << ' ';
			for(int i = 1;i <= n;i++){
				if(f[i] == 0){
					cout << i  << endl;
					break;
				}
			}
		}
	}
}
