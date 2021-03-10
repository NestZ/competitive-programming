#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		string s;cin >> s;
		if(k == 0)cout << "YES\n";
		else if(n % 2 == 0 && k == n / 2)cout << "NO\n";
		else{
			int cnt = 0;
			for(int i = 0;i < n / 2;i++){
				if(s[i] == s[n - i - 1])cnt++;
				else break;
			}
			if(cnt >= k)cout << "YES";
			else cout << "NO";
			cout << endl;
		}
	}
}
