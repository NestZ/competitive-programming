#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int r = 0;
	int l = 0;
	while(n--){
		char c;cin >> c;
		if(c == 'R')r++;
		else l++;
	}
	cout << l + r + 1;
}
