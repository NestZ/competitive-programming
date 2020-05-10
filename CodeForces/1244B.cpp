#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		string s;cin >> s;
		int cnt = 0;
		int ans = 0;
		int fst = n - 1;
		int lst = 0;
		if(s[0] == '1' || s[n - 1] == '1')ans = n * 2;
		else{
			for(int i = 0;i < n;i++){
				if(s[i] == '1'){
					cnt++;
					fst = min(fst, i);
					lst = max(lst, i);
				}
			}
			if(cnt == 0)ans = n;
			else{
				ans += max(fst, n - lst - 1);
				ans += max(min(fst, n - lst - 1) + 2 * cnt, (lst - fst + 1) * 2 + max(fst, n - lst - 1));
			}
		}
		cout << ans << endl;
	}
}
