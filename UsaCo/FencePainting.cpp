/*
ID: nestz
LANG: C++14
TASK: paint
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("paint.out", "w", stdout);
	freopen("paint.in", "r", stdin);

	int a, b, c, d;cin >> a >> b >> c >> d;
	vector<int> arr(101, 0);
	for(int i = a;i <= b;i++)arr[i] = 1;
	for(int i = c;i <= d;i++)arr[i] = 1;
	int ans = 0;
	int cnt = 0;
	for(int i : arr){
		if(i == 1)cnt++;
		else{
			if(cnt > 0){
				ans += cnt - 1;
				cnt = 0;
			}
		}
	}
	if(cnt > 0)ans += cnt - 1;
	cout << ans << endl;
}
