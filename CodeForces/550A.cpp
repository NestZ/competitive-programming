#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n = s.size();
	int ina = 0;
	int inb = 0;
	ina = s.find("AB");
	inb = s.find("BA");
	while(ina != string::npos){
		while(inb != string::npos){
			if(abs(ina - inb) > 1)return cout << "YES", 0;
			inb = s.find("BA", inb + 1);
		}
		inb = s.find("BA");
		ina = s.find("AB", ina + 1);
	}
	cout << "NO";
}
