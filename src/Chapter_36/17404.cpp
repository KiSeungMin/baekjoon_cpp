#include<iostream>
#include<vector>
using namespace std;

int N;
int answer;
const int INF = 1000000000;

vector<vector<int>>cost;

void input();
void getAnswer(vector<vector<int>>& DP);
int getMin(int a, int b);

int main(){

  input();

  return 0;
}

void input(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;

  answer = INF;

  for(int i{0}; i < N; i++){

    vector<int>tmp={0,0,0};
    cin>>tmp[0]>>tmp[1]>>tmp[2];

    cost.push_back(tmp);
  }

  // 시작이 각각 0행, 1행, 2행이라고 가정하고 DP 돌림
  for(int i{0}; i < 3; i++){

    vector<vector<int>>DP;
    vector<int>tmp1 = {INF, INF, INF};
    DP.push_back(tmp1);

    for(int j{0}; j < N - 1; j++){
      vector<int>tmp2 = {0, 0, 0};
      DP.push_back(tmp2);
    }

    DP[0][i] = cost[0][i];

    DP[N - 1][i] = INF;

    getAnswer(DP);
  }

  cout<<answer<<"\n";

}

void getAnswer(vector<vector<int>>& DP){

  for(int i{1}; i < N; i++){

    for(int j{0}; j < 3; j++){

      if(j == 0)
        DP[i][j] += getMin(DP[i - 1][1], DP[i - 1][2]) + cost[i][j];

      else if(j == 1)
        DP[i][j] += getMin(DP[i - 1][0] , DP[i - 1][2]) + cost[i][j];

      else if(j == 2)
        DP[i][j] += getMin(DP[i - 1][0], DP[i - 1][1]) + cost[i][j];

      if(DP[i][j] >= INF)
        DP[i][j] = INF;
    }
  }

  for(int i{0}; i < 3; i++){

    if(DP[N-1][i] < answer)
      answer = DP[N-1][i];
  }

  /*
  for(int i{0}; i < N; i++){

    for(int j{0}; j <3; j++){

      cout<<DP[i][j]<<" ";
    }
    cout<<"\n";
  }
  */
}

int getMin(int a, int b){
  return a > b ? b : a;
}

