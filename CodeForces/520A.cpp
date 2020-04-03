#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	string s;cin >> s;
	set<char> se;
	for(int i = 0;i < n;i++)se.insert(tolower(s[i]));
	cout << (se.size() == 26 ? "YES" : "NO");
}
