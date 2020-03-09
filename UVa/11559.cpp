#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, b, h, w;
	while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){
		int ans = INT_MAX;
		while(h--){
			int p;cin >> p;
			for(int i = 0;i < w;i++){
				int t;cin >> t;
				if(t >= n)ans = min(ans, p * n);
			}
		}
		if(ans == INT_MAX || ans > b)cout << "stay home";
		else cout << ans;
		cout << endl;
	}
}
