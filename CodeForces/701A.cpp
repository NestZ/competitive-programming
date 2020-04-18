#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	int sum = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	int w = sum * 2 / n;
	vector<bool> b(n, false);
	for(int i = 0;i < n - 1;i++){
		if(b[i])continue;
		for(int j = i + 1;j < n;j++){
			if(b[j])continue;
			if(arr[i] + arr[j] == w){
				cout << i + 1 << ' ' << j + 1 << endl;
				b[i] = true;
				b[j] = true;
				break;
			}
		}
	}
}
