#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	for(int q = 0;q < t;q++){
		int n;cin >> n;
		set<string> s;
		map<char, int> m;
		for(int i = 0;i < n;i++){
			string st;cin >> st;
			int l = st.length();
			for(int j = 0;j < l;j++){
				m[st[j]]++;
			}
		}
		bool flag = true;
		for(auto p : m){
			if(p.second % n != 0)flag = false;
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
