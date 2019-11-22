#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    set<int> set;
    cin >> num;
    set.insert(num);
    do{
        num++;
        while(num % 10 == 0)num /= 10;
        int size = set.size();
        set.insert(num);
        if(set.size() == size)break;
    }
    while(true);
    cout << set.size();
    return 0;
}