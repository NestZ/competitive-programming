#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		string s;cin >> s;
		sort(s.begin(), s.end());
		if(k == 1)cout << s;
		else{
			if(s[0] != s[k - 1])cout << s[k - 1];
			else{
				cout << s[0];
				if(s[k] != s[n - 1]){
					for(int i = k;i < n;i++)cout << s[i];
				}
				else{
					for(int i = 0;i < (n - 1) / k;i++)cout << s[k];
				}
			}
		}
		cout << endl;
	}		
}
