#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
int answer=0;

int DP[1<<21];    // DP
bool check[1<<21];    // 해당 원소를 이미 큐에 넣었는지 체크
vector<vector<int>>arr;

void input();
void getAnswer(queue<pair<int, int>>& que);

/* 비트마스크를 이용한 풀이*/

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
      tmp.push_back(num);
    }
    arr.push_back(tmp);
  }

  queue<pair<int, int>>que;

  // 첫 번째 값 : 비트마스크, 두 번째 값 : 현재 더해야 하는 열의 인덱스
  que.push({0, 0});

  while(!que.empty())
    getAnswer(que);

  /*
  for(int i{0}; i < (1 << N); i++){
    cout<<i<<" : "<< DP[i]<<"\n";
  }
  */

  /* 모든 열의 값을 다 더했을 때 최솟값*/
  cout<<DP[(1 << N) - 1]<<"\n";
}

void getAnswer(queue<pair<int, int>>& que){

  if(que.empty())
    return;

  pair<int, int> top = que.front();
  que.pop();

  int bitMask = top.first;
  int indexNow = top.second;

  // 이미 최솟값을 구했으므로 종료
  if(bitMask == (1 << N) - 1)
    return;

  for(int i{0}; i < N; i++){

    // 현재 행을 이미 사용했다면
    if(bitMask & (1 << i))
      continue;

    else{

      //현재 행을 추가했을 때 , 값을 갱신할 수 있다면 갱신
      int bitMaskNext = bitMask | (1 << i);

      if(DP[bitMaskNext] == 0){
        DP[bitMaskNext] = DP[bitMask] + arr[i][indexNow];
      }

      else if(DP[bitMaskNext] != 0){

        if(DP[bitMask] + arr[i][indexNow] < DP[bitMaskNext])
          DP[bitMaskNext] = DP[bitMask] + arr[i][indexNow];
      }

      if(check[bitMaskNext] == false){
        check[bitMaskNext] = true;
        que.push({bitMaskNext, indexNow + 1});
      }
    }
  }
}