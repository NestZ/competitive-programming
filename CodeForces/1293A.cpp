#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, s, k;cin >> n >> s >> k;
		set<int> se;
		for(int i = 0;i < k;i++){
			int a;cin >> a;
			se.insert(a);
		}
		int ans = INT_MAX;
		for(int i = s;i <= n;i++){
			if(se.count(i) == 0){
				ans = min(ans, i - s);
				break;
			}
		}
		for(int i = s;i >= 1;i--){
			if(se.count(i) == 0){
				ans = min(ans, s - i);
				break;
			}
		}
		cout << ans << endl;
	}
}
