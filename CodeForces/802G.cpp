#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	string t = "heidi";
	size_t f = -1;
	for(int i = 0;i < 5;i++){
		f = s.find(t[i], f + 1);
		if(f == string::npos)return cout << "NO", 0;
	}
	cout << "YES";
}
