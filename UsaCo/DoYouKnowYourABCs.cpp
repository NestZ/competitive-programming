/*
ID: nestz
LANG: C++14
TASK: gift1
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> arr(7);
	for(int i = 0;i < 7;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0;i < 4;i++){
		for(int j = i + 1;j < 5;j++){
			for(int k = j + 1;k < 6;k++){
				if(arr[i] + arr[j] + arr[k] == arr[6]){
					cout << arr[i] << ' ' << arr[j] << ' ' << arr[k] << endl;
					return 0;
				}
			}
		}
	}
}
