#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	map<string, bool> m;
	for(int i = 0;i < n;i++){
		string t;cin >> t;
		if(m[t])cout << "YES" << endl;
		else{
			m[t] = true;
			cout << "NO" <<endl;
		}
	}
}
