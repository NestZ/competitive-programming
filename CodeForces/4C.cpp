#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	map<string, int> m;
	while(n--){
		string t;cin >> t;
		if(m[t] == 0)cout << "OK" << endl;
		else cout << t << m[t] << endl;
		m[t]++;
	}
}
