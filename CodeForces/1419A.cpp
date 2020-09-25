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
		if(n & 1){
			bool ans = false;
			for(int i = 1;i <= n;i++){
				if(i & 1){
					if((s[i - 1] - '0') % 2 != 0){
						cout << 1 << endl;
						ans = true;
						break;
					}
				}
			}
			if(!ans)cout << 2 << endl;
		}
		else{
			bool ans = false;
			for(int i = 1;i <= n;i++){
				if((i & 1) ^ 1){
					if((s[i - 1] - '0') % 2 == 0){
						cout << 2 << endl;
						ans = true;
						break;
					}
				}
			}
			if(!ans)cout << 1 << endl;
		}
	}
}
