#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int a = 0;
	int b = 0;
	int c = 0;
	int n = s.length();
	for(int i = 0;i < n;i++){
		if(s[i] == 'a')a++;
		else if(s[i] == 'b')b++;
		else c++;
	}
	if(max({a, b, c}) - min({a, b, c}) > 1)cout << "NO";
	else cout << "YES";
	cout << endl;
}
