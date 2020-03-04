#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	char s;cin >> s;
	map<char, int> m;
	while(s != '!'){
		if(s == '#'){
			char c;cin >> c;
			cout << m[c] << endl;
		}
		else if(s == '='){
			char c;cin >> c;
			int t;cin >> t;
			m[c] = t;
		}
		else if(s == '+'){
			char a, b;cin >> a >> b;
			m[a] = m[a] + m[b];
		}
		else if(s == '-'){
			char a, b;cin >> a >> b;
			m[a] = m[a] - m[b];
		}
		else if(s == '*'){
			char a, b;cin >> a >> b;
			m[a] = m[a] * m[b];
		}
		else if(s == '/'){
			char a, b;cin >> a >> b;
			m[a] = m[a] / m[b];
		}
		cin >> s;
	}
	cout << '!';
}
