#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		string s;cin >> s;
		int n = s.length();
		if(s.substr(n - 2, 2) == "po")cout << "FILIPINO";
		else if(s.substr(n - 4, 4) == "desu" || s.substr(n - 4, 4) == "masu")
			cout << "JAPANESE";
		else cout << "KOREAN";
		cout << endl;
	}
}
