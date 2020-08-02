#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int mod(string num, int a){
	int res = 0;
	int n = num.length();
	for(int i = 0;i < n;i++){
		res = (res * 10 + (int)num[i] - '0') % a;
	}
	return res;
}

int main(){
	string n;cin >> n;
	cout << mod(n, 3) << " " << mod(n, 11);
}
