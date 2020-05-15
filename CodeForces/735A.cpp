#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	string s;cin >> s;
	int p = s.find('G');
	for(int i = p;i < n;i += k){
		if(s[i] == '#')break;
		if(s[i] == 'T')return cout << "YES", 0;
	}
	for(int i = p;i >= 0;i -= k){
		if(s[i] == '#')return cout << "NO", 0;
		if(s[i] == 'T')return cout << "YES", 0;
	}
	cout << "NO";
}
