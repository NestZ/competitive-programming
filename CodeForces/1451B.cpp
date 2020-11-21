#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, q;cin >> n >> q;
		string s;cin >> s;
		for(int i = 0;i < q;i++){
			int l, r;cin >> l >> r;
			l--;
			r--;
			string want = s.substr(l, r - l + 1);
			int ptr = 0;
			bool h = false;
			bool found = false;
			bool ans = false;
			for(int j = 0;j < n;j++){
				if(s[j] != want[ptr] && found)h = true;
				else if(s[j] == want[ptr]){
					ptr++;
					found = true;
					if(ptr == want.length() - 1 && !h)j++;
				};
				if(ptr == want.length()){
					ans = true;
					break;
				}
			}
			if(ans)cout << "YES";
			else cout << "NO";
			cout << endl;
		}
	}
}
