#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int cur = 9;
		string ans = "98";
		if(n == 1)cout << 9;
		else if(n == 2)cout << 98;
		else{
			for(int i = 0;i < n - 2;i++){
				ans += to_string(cur);
				cur++;
				if(cur > 9)cur = 0;
			}
			cout << ans;
		}
		cout << endl;
	}
}
