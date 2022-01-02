#include<iostream>
#include<vector>
using namespace std;

int N, M;
int answer = 10002;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>N>>M;

  vector<int> memory;
  vector<int>cost;

  for(int i{0}; i <N; i++){

    int num;
    cin>>num;
    memory.push_back(num);
  }

  for(int i{0}; i < N; i++){
    
    int num;
    cin>>num;
    cost.push_back(num);
  }

  vector<long long>DP(10001, 0);

  for(int i{0}; i < N; i++){

    for(int j{10000}; j >= 0; j--){

      if(j + cost[i] < 10001 && memory[i] + DP[j] > DP[j + cost[i]]){
        DP[j + cost[i]] = memory[i] + DP[j];
      
        if(j + cost[i] < answer && DP[j +cost[i]] >= M)
          answer = j + cost[i];
      }
    }
  }

  cout<<answer<<"\n";

  return 0;
}