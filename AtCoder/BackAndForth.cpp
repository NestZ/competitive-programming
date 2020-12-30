#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int dis_y = abs(sy - ty);
	int dis_x = abs(sx - tx);
	cout << 'L';
	for(int i = 0;i < dis_y + 1;i++)cout << 'U';
	for(int i = 0;i < dis_x + 1;i++)cout << 'R';
	for(int i = 0;i < dis_y + 1;i++)cout << 'D';
	for(int i = 0;i < dis_x;i++)cout << 'L';

	for(int i = 0;i < dis_y;i++)cout << 'U';
	for(int i = 0;i < dis_x + 1;i++)cout << 'R';
	for(int i = 0;i < dis_y + 1;i++)cout << 'D';
	for(int i = 0;i < dis_x + 1;i++)cout << 'L';
	cout << 'U' << endl;
}
