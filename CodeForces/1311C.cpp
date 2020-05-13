#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, m;cin >> n >> m;
		string s;cin >> s;
		vector<int> f(m, 0);
		for(int i = 0;i < m;i++)cin >> f[i];
		vector<int> fre(n + 5);
		for(int i = 0;i < m;i++){
			fre[0]++;
			fre[f[i]]--;
		}
		fre[0]++;
		fre[n]--;
		map<char, int> ma;
		int curr = 0;
		for(int i = 0;i < n;i++){
			curr += fre[i];
			ma[s[i]] += curr;
		}
		for(int i = 'a';i <= 'z';i++)cout << ma[(char)i] << ' ';
		cout << endl;
	}
}
