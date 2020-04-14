#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int sum = 0;
	for(int i = 0;i < 5;i++){
		int t;cin >> t;
		sum += t;
	}
	if(sum % 5 != 0 || sum / 5 == 0)cout << -1;
	else{
		cout << sum / 5;
	}
}
