#include<iostream>
#include<vector>
using namespace std;

const int INF  = 2000000000;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin>>N;

  vector<int>count(N + 1, INF);
  count[1] = 0;
  vector<int>parent(N + 1, 0);
  for(int i{2}; i < N + 1; i++){
    parent[i] = i;
  }

  for(int i{2}; i < N + 1; i++){

    int min = INF;

    if(i  == 2){
      parent[i] = 1;
      count[i] = 1;
    }

    else if(i==3){
      parent[i] = 1;
      count[i] = 1;
    }

    else{

      if(i % 2 == 0){

        if(count[i/2] + 1 < min){

          count[i] = count[i/2] + 1;
          parent[i] = i / 2;
          min = count[i/2] + 1;
        }
      }

      if(i % 3 == 0){

        if(count[i/3] + 1 < min){

          count[i] = count[i/3] + 1;
          parent[i] = i / 3;
          min = count[i/3] + 1;
        }
      }

      if(count[i-1] + 1 < min){

        count[i] = count[i-1] + 1;
        parent[i] = i - 1;
        min = count[i-1] + 1;
      }
    }
  }

  cout<<count[N]<<"\n";
  cout<<N<<" ";

  int next = parent[N];
  while(next != 0){

    cout<<next<<" ";
    next = parent[next];
  }
  cout<<"\n";

  return 0;
}