#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		bool flag = true; 
		int a,b,c,d;cin >> a >> b >> c >> d;
		int x1,x,x2,y1,y,y2;cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if(a > b && x - x1 < a - b)flag = false;
		if(b > a && x2 - x < b - a)flag = false;
		if(c > d && y - y1 < c - d)flag = false;
		if(d > c && y2 - y < d - c)flag = false;
		if((a > 0 || b > 0) && x == x1 && x == x2)flag = false;
		else if((c > 0 || d > 0) && y == y1 && y == y2)flag = false;
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
