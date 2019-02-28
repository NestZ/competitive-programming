#include<iostream>
using namespace std;

int main(){
  string team[4];
  int shoot[4] = {0};
  int shooted[4] = {0};
  int scoreboard[4][4] = {0};
  int score[4] = {0};
  int max;

  for(int i = 0;i < 4;i++){
    cin >> team[i];
  }

  for(int i = 0;i < 4;i++){
    for(int j = 0;j < 4;j++){
      cin >> scoreboard[i][j];
    }
  }

  for(int i = 0;i < 4;i++){
    for(int j = 0;j < 4;j++){
      shoot[i] += scoreboard[i][j];
      shooted[i] += scoreboard[j][i];
    }
  }

  for(int i = 0;i < 4;i++){
    for(int j = i+1;j < 4;j++){
      if(scoreboard[i][j] > scoreboard[j][i])score[i] += 3;
      else if(scoreboard[i][j] < scoreboard[j][i])score[j] += 3;
      else{
        score[i]++;
        score[j]++;
      }
    }
  }

  for(int j = 0;j < 4;j++){
    max = 0;
    for(int i = 1;i < 4;i++){
      if(score[i] > score[max])max = i;
      else if(score[i] == score[max]){
        if(shoot[i] - shooted[i] > shoot[max] - shooted[max])max = i;
        else if(shoot[i] - shooted[i] == shoot[max] - shooted[max]){
          if(shoot[i] > shoot[max])max = i;
        }
      }
    }
    cout << team[max] << " " << score[max] << "\n";
    score[max] = -1;
  }

  return 0;
}
