#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;cin >> x >> y;
	int diff = abs(abs(x) - abs(y));
	if(x == y) {}
	else if(x == 0){
		if(y < 0)diff++;
	}
	else if(y == 0){
		if(x > 0)diff++;
	}
	else if((x > 0 && y > 0) || (x < 0 && y < 0)){
		if(x > y)diff += 2;
	}
	else diff++;
	cout << diff << endl;
}
