#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s1;
  string s2;
  cin>>s1>>s2;

  vector<int>tmp1(s1.length() + 1, 0);
  vector<vector<int>>count(s2.length() + 1, tmp1);

  vector<pair<int, int>>tmp2(s1.length() + 1);
  vector<vector<pair<int, int>>> parent(s2.length() + 1, tmp2);

  for(int i{0}; i < s2.length() + 1; i++){

    for(int j{0}; j < s1.length() + 1; j++){

      parent[i][j].first = i;
      parent[i][j].second = j;
    }
  }

  int answer = 0;
  int answerRow = 0;
  int answerCol = 0;

  for(int i{0}; i < s2.length(); i++){

    for(int j{0}; j < s1.length(); j++){

      if(s2[i] == s1[j]){

        count[i + 1][j + 1] = count[i][j] + 1;
        parent[i + 1][j + 1].first = i;
        parent[i + 1][j + 1].second = j;

        if(count[i + 1][j + 1] > answer){
          answer = count[i + 1][j + 1];
          answerRow = i + 1;
          answerCol = j + 1;
        }
      }

      else{

        count[i + 1][j + 1] = count[i + 1][j];
        parent[i + 1][j + 1].first = i + 1;
        parent[i + 1][j + 1].second = j;

        if(count[i][j + 1] > count[i + 1][j + 1]){

          count[i + 1][j + 1] = count[i][j + 1];
          parent[i + 1][j + 1].first = i;
          parent[i + 1][j + 1].second = j + 1;
        }
      }
    }
  }

  /*
  for(int i{0}; i < s2.length() + 1; i ++){

    for(int j{0}; j < s1.length() + 1; j ++){

      cout<<"{"<<parent[i][j].first<<","<<parent[i][j].second<<"}"<<" ";
    }
    cout<<'\n';
  }
  */

  if(answer == 0){
    cout<<0<<"\n";
    return 0;
  }

  vector<char>answerArray;

  while(true){

    if(count[answerRow][answerCol] == 0)
      break;

     int parentRow = parent[answerRow][answerCol].first;
     int parentCol = parent[answerRow][answerCol].second;

    // 부모 원소와 현재 원소가 다를 경우에 정답을 구성하는 원소임
     if(count[parentRow][parentCol] != count[answerRow][answerCol])
      answerArray.push_back(s1[answerCol-1]);

     answerRow = parentRow;
     answerCol = parentCol;
  }

  cout<<answer<<"\n";
  for(int i{answer-1}; i >=0; i--){
    cout<<answerArray[i];
  }
  cout<<'\n';

  return 0;
}