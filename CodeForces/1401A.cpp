#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		if(a < b)cout << b - a;
		else{
			cout << (abs(a - b) & 1);
		}
		cout << endl;
	}
}
