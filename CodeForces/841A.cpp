#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	string s;cin >> s;
	map<char, int> m;
	for(int i = 0;i < n;i++){
		m[s[i]]++;
		if(m[s[i]] > k)return cout << "NO", 0;
	}
	cout << "YES";
}
