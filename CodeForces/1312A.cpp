#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int a, b;cin >> a >> b;
		if((a - b) % b == 0 && b < a)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
