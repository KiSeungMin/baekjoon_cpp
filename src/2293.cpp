#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void getAnswer(int num);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, goal;
  cin>>N>>goal;

  vector<int>cost;
  vector<int>DP(goal + 1, 0);

  for(int i{0}; i < N ; i++){
    int num;
    cin>>num;
    cost.push_back(num);
  }

  sort(cost.begin(), cost.end());

  DP[0] = 1;

  for(int i{0}; i < N; i++){

    for(int j{cost[i]}; j < DP.size(); j ++){

      DP[j] = DP[j] + DP[j - cost[i]];
    }
  }

  cout<<DP[goal]<<"\n";

  return 0;
}
