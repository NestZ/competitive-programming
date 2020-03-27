#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int sX = 0;
	int sY = 0;
	int sZ = 0;
	for(int i = 0;i < n;i++){
		int x,y,z;cin >> x >> y >> z;
		sX += x;
		sY += y;
		sZ += z;
	}
	if(sX == 0 && sY == 0 && sZ == 0)cout << "YES";
	else cout << "NO";
}
