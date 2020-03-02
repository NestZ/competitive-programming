#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;
int arr[20][20];
int ans = 0;

int adj(int i, int j, int num){
	if(i < 0 || j < 0 || i >= n || j >= n || arr[i][j] != num)return 0;
	arr[i][j] = -1;
	assert(num != -1);
	return 1 + adj(i, j + 1, num) + adj(i, j - 1, num) + adj(i + 1, j, num) + adj(i - 1, j, num);
}

void check(int i, int j){
	if((i == n - 1 && j == n - 1) || arr[i][j] == -1)return;
	assert(arr[i][j] != -1);
	if(j + 1 < n && i + 1 < n && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j]){
		if(adj(i, j, arr[i][j]) == 3)ans++;
	}
	else if(i + 1 < n && j - 1 >= 0 && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 1][j - 1]){
		if(adj(i, j, arr[i][j]) == 3)ans++;
	}
	else if(j + 1 < n && i + 1 < n && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j + 1]){
		if(adj(i, j, arr[i][j]) == 3)ans++;
	}
	else if(i + 1 < n && j + 1 < n && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 1][j + 1]){
		if(adj(i, j, arr[i][j]) == 3)ans++;
	}
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> arr[i][j];
			assert(arr[i][j] != -1);
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			check(i, j);
		}
	}
	cout << ans;
}
