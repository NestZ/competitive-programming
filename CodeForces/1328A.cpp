#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	while(n--){
		int a,b;cin >> a >> b;
		int t = a % b;
		cout << (b - t) % b << endl;
	}
}
