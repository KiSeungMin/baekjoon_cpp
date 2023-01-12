#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int N, M;
int answer = 0;
int CA = 1;

vector<bool>check;
vector<int>parent;
vector<int>parentArr;

void init();
void getAnswer();
void DFS(queue<int>& node, int colorNow, vector<int>& adjacent);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;

  while(N != 0 || M != 0){
    init();
    getAnswer();
    CA++;
    cin>>N>>M;
  }

  return 0;
}

void init(){

  parent.clear();
  check.clear();
  answer = 0;

  for(int i{0}; i <= N; i++){
    parent.push_back(-1);
    check.push_back(true);
  }

  for(int i{0}; i < M; i++){

    int num1, num2;
    cin>>num1>>num2;

    int pointer1 = num1;
    int pointer2 = num2;

    if(parent[num1] == -1)
      pointer1 = -1;

    else {
      while(parent[pointer1] != pointer1)
        pointer1 = parent[pointer1];
    }

    if(parent[num2] == -1)
      pointer2 = -1;

    else{
      while(parent[pointer2] != pointer2)
        pointer2 = parent[pointer2];
    }
    
    if(pointer1 < 0 && pointer2 < 0){

      if(num1 < num2){
        parent[num1]  = num1;
        parent[num2] = num1;
      }
      else if(num1 > num2){
        parent[num1] = num2;
        parent[num2] = num2;
      }
      else{
        parent[num1] = num1;
        check[parent[num1]] = false;
      }

      continue;
    }

    else if(pointer1 == pointer2){

      check[pointer1] = false;
      check[pointer2] = false;

      continue;
    }

    else if(pointer1 > 0  && pointer2 < 0){
      parent[num2] = pointer1;
      continue;
    }

    else if(pointer1 < 0 && pointer2 > 0){
      parent[num1] = pointer2;
      continue;
    }

    else{
      if(check[pointer1] == false || check[pointer2] == false){
        check[pointer1] = false;
        check[pointer2] = false;
        parent[pointer2] = pointer1;
      }
    }
  }
}

void getAnswer(){

  for(int i{1}; i <= N; i++){

    if(parent[i] != i && parent[i] > 0)
      continue;

    else if(parent[i] == -1)
      answer++;

    else{
      if(check[i]){
        answer++;
      } 
    }
  }

  cout<<"Case "<<CA<<": ";
  if(answer == 0){
    cout<<"No trees.\n";
    return;
  }

  else if(answer == 1){
    cout<<"There is one tree.\n";
    return;
  }

  cout<<"A forest of "<<answer<<" trees.\n";
  return;
}
