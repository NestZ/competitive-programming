#include<bits/stdc++.h>
using namespace std;

int main(){
    int lenght;
    string s;
    int num = 0;
    cin >> lenght >> s;
    for(int i = 0;i < lenght;i++){
        if(s[i] == '1'){
            num++;
        }
        else{
            num--;
        }
    }
    if(num != 0){
        cout << 1 << "\n" << s;
    }
    else{
        cout << 2 << "\n";
        for(int i = 0;i < lenght - 1;i++){
            cout << s[i];
        }
        cout << ' ' << s[lenght - 1];
    }
    return 0;
}