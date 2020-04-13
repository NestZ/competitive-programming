#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m;cin >> n >> m;
	bool b = true;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;cin >> c;
			if(c == 'C' || c == 'M' ||
				c == 'Y')b = false;
		}
	}
	if(b)cout << "#Black&White";
	else cout << "#Color";
}
