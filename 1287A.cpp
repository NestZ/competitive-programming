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
		int mx = 0;
		int curr = 0;
		bool a = false;
		for(int i = 0;i < n;i++){
			if(s[i] == 'P' && a){
				curr++;
				mx = max(mx, curr);
			}
			else if(s[i] == 'A'){
				curr = 0;
				a = true;
			}
		}
		cout << mx << endl;
	}
}
