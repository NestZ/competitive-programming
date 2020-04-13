#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n, a, b;cin >> n >> a >> b;
		string ans = "";
		for(int i = 0;i < b;i++)ans += 'a' + i;
		string s = "";
		while((int)s.length() < n)s += ans;
		cout << s.substr(0, n) << endl;
	}
}
