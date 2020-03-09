#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int h, u, d, f;
	cin >> h >> u >> d >> f;
	while(h != 0){
		double currD = 0.0;
		double currSp = u * 1.0;
		double ff = f / 100.0 * u;
		int day = 0;
		bool flag = false;
		do{
			day++;
			currD += currSp;
			if(currD > h){
				cout << "success on day " << day << endl;
				flag = true;
				break;
			}
			currD -= (double)d;
			currSp = max(0.0, currSp - ff);
		}while(currD >= 0.0);
		if(!flag)cout << "failure on day " << day << endl;
		cin >> h >> u >> d >> f;
	}
}
