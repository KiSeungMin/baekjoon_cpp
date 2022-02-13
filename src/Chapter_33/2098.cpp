#include<iostream>
#include<vector>
using namespace std;

int N;
const int INF = 1000000000;
int answer;

// DP[a][b] : bitmask가 b이고, 종착지가 a라고 할 때 비용의 최솟값
vector<vector<int>>DP;

// 비용
vector<vector<int>> cost;

void input();
void getAnswer(int bitMask);
int calculate(int end, int bitMask);
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

  for(int i{0}; i < N; i++){

    vector<int>tmp;

    for(int j{0}; j < N; j++){

      int num;
      cin>>num;

      num = (num > 0) ? num : INF;

      tmp.push_back(num);
    }

    cost.push_back(tmp);
  }

  for(int i{0}; i < N; i++){
    vector<int>tmp;

    for(int i{0}; i < (1 << N); i++)
      tmp.push_back(INF);

    DP.push_back(tmp);
  }
      
  for(int i{0}; i < N; i++)
    DP[i][0] = 0;

  answer = INF;

  for(int i{0}; i < (1 << N); i++)
    getAnswer(i);

  cout<<answer<<"\n";

  /*
  for(int i{0}; i < N; i++){
    for(int j{0}; j < (1 << N); j++){
      cout<<DP[i][j]<<" ";
    }
    cout<<"\n";
  }
  */

}

void getAnswer(int bitMask){

  if(bitMask == 0)
    return;

  // bitMask가 11111111.... 일 경우 11111111......0 중에서 최솟값을 만들 수 있는 경우를 찾는다
  else if(bitMask == (1 << N) - 1){

    int bitMaskNext = (1 << N) - 2;

    for(int j{1}; j < N; j++){

      if(DP[j][bitMaskNext] + cost[j][0] < answer)
        answer = getMin(answer, DP[j][bitMaskNext] + cost[j][0]);
    }
  }

  // bitMask가 1을 포함하면 찾지 않는다 (1을 무조건 시작점이자 종점으로 둔다고 가정하기 때문에)
  if(bitMask & (1 << 0))
    return;

  // bitMask가 0이 아닐 경우 
  else{

    for(int j{1}; j < N; j++){

      if(!(bitMask & (1 << j)))
        continue;

      // 현재 점을 종점으로 할 때 DP 테이블을 갱신할 수 있다면 갱신
      else
        DP[j][bitMask] = getMin(DP[j][bitMask], calculate(j, (bitMask & ~(1 << j))));   
    
    }
  }
}

// end를 종점으로 할 때 해당 지점에서의 최솟값
int calculate(int end, int bitMask){

  if(bitMask == 0)
    return cost[0][end];

  int res = INF;

  for(int j{1}; j < N; j++){

    if(DP[j][bitMask] == INF)
      continue;

    else{

      if(DP[j][bitMask] + cost[j][end] < res)
        res = DP[j][bitMask] + cost[j][end];

    }
  }

  return res;
}

int getMin(int a, int b){
  return a > b ? b : a;
}