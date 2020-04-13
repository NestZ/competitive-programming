#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		if(360 % (180 - n) == 0)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
