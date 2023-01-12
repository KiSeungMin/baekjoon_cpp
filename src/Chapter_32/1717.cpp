#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int>parent;

void init();
void getAnswer(int cmd, int num1, int num2);

int main(){

  init();

  return 0;
}

void init(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;

  for(int i{0}; i <= N; i++){
    parent.push_back(-1);
  }

  for(int i{0}; i < M; i++){

    int cmd, num1, num2;
    cin>>cmd>>num1>>num2;

    getAnswer(cmd, num1, num2);
  }
}

void getAnswer(int cmd, int num1, int num2){

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

  if(cmd == 0){

    if(pointer1 == -1 && pointer2 == -1){
      parent[num1] = num1;
      parent[num2] = num1;
      return;
    }

    else if(pointer1 != -1 && pointer2 == -1){
      parent[num2] = pointer1;
      return;
    }

    else if(pointer1 == -1 && pointer2 != -1){
      parent[num1] = pointer2;
      return;
    }

    else if(pointer1 == pointer2)
      return;

    else{
      parent[pointer2] = pointer1;
      return;
    }
    
    return;
  }

  else if(cmd == 1){

    if(pointer1 == pointer2 && pointer1 != -1)
      cout<<"YES";

    else if(num1 == num2)
      cout<<"YES";
      
    else
      cout<<"NO";

    cout<<'\n';
    return;
  } 
}