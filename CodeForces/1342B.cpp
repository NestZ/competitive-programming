#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		string s;cin >> s;
		int l = s.length();
		set<char> se;
		for(int i = 0;i < l;i++)se.insert(s[i]);
		if(se.size() == 1)cout << s << endl;
		else{
			for(int i = 0;i < 2 * l;i++)cout << i % 2;
			cout << endl;
		}
	}
}
