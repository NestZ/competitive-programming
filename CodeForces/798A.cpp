#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int is(string s){
	int n = s.length();
	int cnt = 0;
	for(int i = 0;i < n / 2;i++)
		if(s[i] != s[n - i - 1])cnt++;
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	if(is(s) == 1 || (is(s) == 0 && (s.length() & 1)))return cout << "YES", 0;
	cout << "NO";
}
