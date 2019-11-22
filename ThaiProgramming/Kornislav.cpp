#include<iostream>
using namespace std;

int main(){
	int number[4];
	int temp;
	int status = 1;

	for(int i = 0;i < 4;i++)
		cin >> number[i];
	while(status == 1){
		status = 0;
		for(int j = 0;j < 3;j++){
			if(number[j] > number[j+1]){
				temp = number[j];
				number[j] = number[j+1];
				number[j+1] = temp;
				status = 1;
			}
		}
	}
	cout << number[2]*number[0];

	return 0;
}
