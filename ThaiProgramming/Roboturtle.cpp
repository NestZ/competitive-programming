Source #714165:
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int dir = 2;
int currX = 0;
int currY = 0;
char dirc[] = {'W', 'N', 'E', 'S'};

void fd(int s){
	switch(dir){
		case 0 :
			currX -= s;
			break;
		case 1 :
			currY += s;
			break;
		case 2 :
			currX += s;
			break;
		case 3 :
			currY -= s;
			break;
	};
}

int main(){
	int n;cin >> n;
	for(int i = 0;i < n;i++){
		string d;cin >> d;
		int s;cin >> s;
		if(d == "BW")dir += 2;
		else if(d == "LT")dir--;
		else if(d == "RT")dir++;
        if(dir == -1)dir = 3;
        else if(dir > 3)dir %= 4;
        fd(s);
		if(currX <= -50000 || currX >= 50000 || currY <= -50000 || currY >= 50000){
			return cout << "DEAD", 0;
		}
	}
	cout << currX << ' ' << currY << endl;
	cout << dirc[dir];
}
