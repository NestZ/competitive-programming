#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	string t = "HQ9";
	if(s.find_first_of(t) != string::npos)cout << "YES";
	else cout << "NO";
}
