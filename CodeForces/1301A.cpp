#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		string a, b, c;cin >> a >> b >> c;
		int n = a.length();
		bool flag = true;
		for(int i = 0;i < n;i++){
			if(a[i] != b[i] && c[i] != a[i] && c[i] != b[i])flag = false;
			else if(a[i] == b[i] && c[i] != b[i] && c[i] != a[i])flag = false;
		}
		if(flag)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
