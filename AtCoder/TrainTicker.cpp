#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	vector<int> arr;
	for(int i = 0;i < 4;i++)arr.push_back(s[i] - '0');
	if(arr[0] + arr[1] + arr[2] + arr[3] == 7)
		printf("%d+%d+%d+%d=7\n", arr[0], arr[1], arr[2], arr[3]);
	else if(arr[0] + arr[1] + arr[2] - arr[3] == 7)
		printf("%d+%d+%d-%d=7\n", arr[0], arr[1], arr[2], arr[3]);
	else if(arr[0] + arr[1] - arr[2] + arr[3] == 7)
		printf("%d+%d-%d+%d=7\n", arr[0], arr[1], arr[2], arr[3]);
	else if(arr[0] + arr[1] - arr[2] - arr[3] == 7)
		printf("%d+%d-%d-%d=7\n", arr[0], arr[1], arr[2], arr[3]);
	else if(arr[0] - arr[1] + arr[2] + arr[3] == 7)
		printf("%d-%d+%d+%d=7\n", arr[0], arr[1], arr[2], arr[3]);
	else if(arr[0] - arr[1] + arr[2] - arr[3] == 7)
		printf("%d-%d+%d-%d=7\n", arr[0], arr[1], arr[2], arr[3]);
	else if(arr[0] - arr[1] - arr[2] + arr[3] == 7)
		printf("%d-%d-%d+%d=7\n", arr[0], arr[1], arr[2], arr[3]);
	else if(arr[0] - arr[1] - arr[2] - arr[3] == 7)
		printf("%d-%d-%d-%d=7\n", arr[0], arr[1], arr[2], arr[3]);
}
