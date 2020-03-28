#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	string t = "hello";
	int cnt = 0;
	int n = s.length();
	for(int i = 0;i < n;i++){
		if(s[i] == t[cnt])cnt++;
		if(cnt == 5)return cout << "YES", 0;
	}
	cout << "NO";
}
