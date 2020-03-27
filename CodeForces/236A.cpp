#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n = s.length();
	set<char> se;
	for(int i = 0;i < n;i++)se.insert(s[i]);
	cout << (se.size() & 1 ? "IGNORE HIM!" : "CHAT WITH HER!");
}
