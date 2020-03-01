#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a, b;cin >> a >> b;
	string s[5];
	string num[10] = {
		"010101111",
		"000001001", "010011110", "010011011",
		"000111001", "010110011", "010110111",
		"010001001", "010111111", "010111011"
	};
	cin.ignore();
	for(int i = 0;i < 3;i++){
		getline(cin, s[i]);
		while(s[i].length() < (unsigned int)(a * 3 + a - 1))s[i] += ' ';
	}
	ll fop = 0, sop = 0;
	for(int i = 0;i < a * 3 + a;i += 4){
		string t = "";
		for(int j = 0;j < 3;j++){
			for(int k = i;k < i + 3;k++){
				if(s[j][k] != ' ')t += '1';
				else t += '0';
			}
		}
		for(ll j = 0;j < 10;j++){
			if(t == num[j])fop = fop * 10ll + j;
		}
	}
	for(int i = 0;i < 3;i++){
		getline(cin, s[i]);
		while(s[i].length() < (unsigned int)(b * 3 + b - 1))s[i] += ' ';
	}
	for(int i = 0;i < b * 3 + b;i += 4){
		string t = "";
		for(int j = 0;j < 3;j++){
			for(int k = i;k < i + 3;k++){
				if(s[j][k] != ' ')t += '1';
				else t += '0';
			}
		}
		for(ll j = 0;j < 10;j++){
			if(t == num[j])sop = sop * 10ll + j;
		}
	}
	cout << fop + sop;
}
