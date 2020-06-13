#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	int a = 0;
	int b = 0;
	for(int i = 0;i < n;i++){
		if(s[i] != '4' && s[i] != '7')return cout << "NO", 0;
		if(i < n / 2)a += s[i] - '0';
		else b += s[i] - '0';
	}
	if(a == b)cout << "YES";
	else cout << "NO";
}
