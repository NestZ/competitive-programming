#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(8, 0);
	int oth = 0;
	for(int i = 0;i < n;i++){
		int r;cin >> r;
		if(r >= 3200)oth++;
		else if(r >= 2800)arr[7] = 1;
		else if(r >= 2400)arr[6] = 1;
		else if(r >= 2000)arr[5] = 1;
		else if(r >= 1600)arr[4] = 1;
		else if(r >= 1200)arr[3] = 1;
		else if(r >= 800)arr[2] = 1;
		else if(r >= 400)arr[1] = 1;
		else arr[0] = 1;
	}
	int sum = 0;
	for(int i = 0;i < 8;i++)sum += arr[i];
	cout << max(1, sum) << ' ' << sum + oth << endl;
}
