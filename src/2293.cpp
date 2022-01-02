#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, goal;
vector<int>cost;
vector<int>DP(10001, -1);

void getAnswer(int num);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>goal;

  for(int i{0}; i < N ; i++){
    int num;
    cin>>num;
    cost.push_back(num);
  }

  sort(cost.begin(), cost.end());

  DP[0] = 0;

  getAnswer(goal);

  for(int i{0}; i <= goal; i++){
    cout<<DP[i]<<" ";
  }

  return 0;
}

void getAnswer(int num){

  if(DP[num] != -1)
    return;

  int sum = 0;

  for(int i{0}; i < cost.size(); i++){

    if(num - cost[i] >= 0){

      if(DP[num - cost[i]] == -1)
        getAnswer(num - cost[i]);

      sum = sum + DP[num - cost[i]] + 1;
    }

    else
      break;
  }

  DP[num] = sum;
}
