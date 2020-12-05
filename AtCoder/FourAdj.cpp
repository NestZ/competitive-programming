#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int cnt = 0;
	int cnt2 = 0;
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		if(num % 4 == 0)cnt++;
		else if(num % 2 == 0)cnt2++;
	}
	n -= max(cnt2 - 1, 0);
	if(n == 1 || cnt >= n / 2)cout << "Yes";
	else cout << "No";
	cout << endl;
}
