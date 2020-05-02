#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;cin >> a >> b;
	int na = a.length();
	int nb = b.length();
	if(na != nb)return cout << "No", 0;
	string v = "aeiou";
	for(int i = 0;i < na;i++){
		bool ba = v.find(a[i]) == string::npos;
		bool bb = v.find(b[i]) == string::npos;
		if(ba ^ bb)return cout << "No", 0;
	}
	cout << "Yes";
}
