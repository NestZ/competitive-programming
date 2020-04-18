#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a, b, c;cin >> a >> b >> c;
	int mx = 0;
	for(int i = 0;i <= a;i++){
		int j = i + 1;
		int k = j + 1;
		if(j > b || k > c)break;
		mx = max(mx, i + j + k);
	}
	cout << mx;
}
