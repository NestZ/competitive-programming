#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	set<string> s;
	string t;cin >> t;
	int n = t.length();
	for(int i = 0;i <= n;i++){
		for(int j = 0;j < 26;j++){
			string temp = t;
			char c = 'a' + j;
			s.insert(temp.insert(i, 1, c));
		}
	}
	cout << s.size();
}
