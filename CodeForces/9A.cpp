#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a, b;cin >> a >> b;
	if(max(a, b) == 1)cout << "1/1";
	else{
		int x = 6 - max(a, b) + 1;
		int y = 6;
		if(x % 2 == 0 && y % 2 == 0){
			x >>= 1;
			y >>= 1;
		}
		else if(x % 3 == 0 && y % 3 == 0){
			x /= 3;
			y /= 3;
		}
		cout << x << '/' << y;
	}
}
