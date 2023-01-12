#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int>parent;

void input();
bool getAnswer(int num1, int num2, int count);

int main(){
  
  input();  
  return 0;
}

void input(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;

  for(int i{0}; i < N; i++)
    parent.push_back(-1);

  for(int i{1}; i <= M; i++){
    int num1, num2;
    cin>>num1>>num2;
    bool answer = getAnswer(num1, num2, i);

    if(answer == false)
      return;
  }

  cout<<0<<"\n";
  return;
}

bool getAnswer(int num1, int num2, int count){

  int pointer1 = num1;
  int pointer2 = num2;

  if(parent[num1] == -1)
    pointer1 = -1;

  else{
    while(parent[pointer1] != pointer1)
      pointer1 = parent[pointer1];
  }

  if(parent[num2] == -1)
    pointer2 = -1;

  else{
    while(parent[pointer2] != pointer2)
      pointer2 = parent[pointer2];
  }  

  if(pointer1 == -1 && pointer2 == -1){
    parent[num1] = num1;
    parent[num2] = num1;
    return true;
  }

  else if(pointer1 != -1 && pointer2 == -1){
    parent[num2] = pointer1;
    return true;
  }

  else if(pointer1 == -1 && pointer2 != -1){
    parent[num1] = pointer2;
    return true;
  }

  else if(pointer1 == pointer2){
    cout<<count<<"\n";
    return false;
  }

  else{
    parent[pointer2] = pointer1;
    return true;
  }
}