#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int k;cin >> k;
	while(k != 0){
		int x, y;cin >> x >> y;
		for(int i = 0;i < k;i++){
			int a, b;cin >> a >> b;
			if(a == x || b == y)cout << "divisa";
			else if(b > y)cout << (a > x ? "NE" : "NO");
			else cout << (a > x ? "SE" : "SO");
			cout << endl;
		}
		cin >> k;
	}
}
