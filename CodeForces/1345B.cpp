#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int ans = 0;
		while(n > 1){
			int curr = 1;
			int w = curr * (curr + 1) / 2 * 3 - curr;
			while(n >= w){
				curr++;
				int tmp = curr * (curr + 1) / 2 * 3 - curr;
				if(n >= tmp)w = tmp;
				else break;
			}
			n -= w;
			ans++;
		}
		cout << ans << endl;
	}
}
