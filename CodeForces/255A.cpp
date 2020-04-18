#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int a = 0;
	int b = 0;
	int c = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(i % 3 == 0)a += t;
		else if(i % 3 == 1)b += t;
		else c += t;
	}
	if(a > b && a > c)cout << "chest";
	else if(b > a && b > c)cout << "biceps";
	else cout << "back";
}
