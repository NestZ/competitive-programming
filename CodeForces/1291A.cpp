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
		int cnto = 0;
		for(int i = 0;i < n;i++){
			if((s[i] - '0') & 1)cnto++;
		}
		if(cnto <= 1)cout << -1;
		else{
			int cnt = 0;
			for(int i = 0;i < n;i++){
				if((s[i] - '0') & 1){
					cout << s[i];
					cnt++;
					if(cnt == 2)break;
				}
			}
		}
		cout << endl;
	}
}
