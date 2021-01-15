#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	int n = s.length();
	int k;cin >> k;
	for(int i = 0;i < n;i++){
		if(s[i] == 'a')continue;
		int diff = 26 - int(s[i] - 'a');
		if(diff <= k){
			s[i] = 'a';
			k -= diff;
		}
	}
	if(k > 0){
		int rem = int(s[n - 1] - 'a') + k;
		s[n - 1] = char('a' + (rem % 26));
	}
	cout << s << endl;
}
