#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;cin >> a >> b;
	int aw = 0;
	int d = 0;
	int bw = 0;
	for(int i = 1;i <= 6;i++){
		if(abs(i - a) < abs(i - b))aw++;
		else if(abs(i - b) < abs(i - a))bw++;
		else d++;
	}
	cout << aw << ' ' << d << ' ' << bw;
}
