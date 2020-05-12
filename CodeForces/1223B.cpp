#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		string a;cin >> a;
		string b;cin >> b;
		int n = a.length();
		set<char> s;
		bool flag = false;
		for(int i = 0;i < n;i++)s.insert(a[i]);
		for(int i = 0;i < n;i++){
			if(s.count(b[i]) != 0)flag = true;
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
