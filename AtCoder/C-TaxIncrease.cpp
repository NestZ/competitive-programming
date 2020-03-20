#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a,b;cin >> a >> b;
	for(int i = 1;i <= 1300;i++){
		if(int(i * 0.08) == a && int(i * 0.1) == b)return cout << i, 0;
	}
	cout << -1;
}
