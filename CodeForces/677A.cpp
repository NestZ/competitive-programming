#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n,h;cin >> n >> h;
	int b = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t > h)b++;
	}
	cout << n + b;
}
