#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a = 0;
	int b = 0;
	for(int i = 0;i < 3;i++){
		int t;cin >> t;
		a += t;
	}
	for(int i = 0;i < 3;i++){
		int t;cin >> t;
		b += t;
	}
	int n;cin >> n;
	if(((a + 4) / 5) + ((b + 9) / 10) <= n)cout << "YES";
	else cout << "NO";
}
