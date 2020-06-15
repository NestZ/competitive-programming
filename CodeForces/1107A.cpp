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
		if(n == 1)cout << "NO";
		if(n == 2 && s[0] >= s[1])cout << "NO";
		else{
			cout << "YES" << endl << 2 << endl;
			cout << s[0] << ' ' << s.substr(1, n - 1);
		}
		cout << endl;
	}
}
