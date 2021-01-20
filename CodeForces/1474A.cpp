#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		string s;cin >> s;
		string ans = "1";
		int last = int(ans[0] - '0') + int(s[0] - '0');
		for(int i = 1;i < n;i++){
			int cur = int(s[i] - '0') + 1;
			if(cur == last){
				ans += "0";
				cur = int(s[i] - '0');
			}
			else{
				ans += "1";
			}
			last = cur;
		}
		cout << ans << endl;
	}
}
