/*
ID: nestz
LANG: C++14
TASK: friday
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool isLeap(int year){
	if(year % 100 == 0 && year % 400 == 0)return true;
	if(year % 4 == 0 && year % 100 != 0)return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("friday.out", "w", stdout);
	freopen("friday.in", "r", stdin);

	int n;cin >> n;
	int ans[7] = {0};
	int days[12] = {31, 99, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int curday = 2;
	for(int i = 1900;i < 1900 + n;i++){
		if(isLeap(i))days[1] = 29;
		else days[1] = 28;
		for(int month = 0;month < 12;month++){
			int day13 = (curday + 12) % 7;
			ans[day13]++;
			curday = (curday + days[month]) % 7;
		}
	}
	for(int i = 0;i < 7;i++){
		cout << ans[i];
		if(i != 6)cout << ' ';
	}
	cout << endl;
}
