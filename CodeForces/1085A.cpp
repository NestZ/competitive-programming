#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	int m = (n - 1) / 2;
	int r = m + 1;
	int l = m - 1;
	cout << s[m];
	bool isr = true;
	while(r < n || l >= 0){
		if(isr)cout << s[r++];
		else cout << s[l--];
		isr = !isr;
	}
}
