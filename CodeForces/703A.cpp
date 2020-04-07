#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int m = 0;
	int c = 0;
	while(n--){
		int a, b;cin >> a >> b;
		if(a > b)m++;
		else if(b > a)c++;
	}
	if(m > c)cout << "Mishka";
	else if(c > m)cout << "Chris";
	else cout << "Friendship is magic!^^";
}
