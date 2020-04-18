#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		string s = string(n / 2, '1');
		if(n & 1)s[0] = '7';
		cout << s << endl;
	}
}
