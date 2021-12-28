#include<iostream>
#include<vector>
using namespace std;

vector<vector<unsigned int>> result;
vector<vector<unsigned int>>sum;

unsigned int getAnswer(int start, int end);
unsigned getMin(unsigned int a, unsigned int b);

// result[a][b] = min(result[a][k] + result[k][b])

// result[a][k] : return result[a][k] + sum[a][k]

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin>>T;

  for(int t{0}; t < T; t++){

    int N;
    cin>>N;

    vector<int>arr;

    for(int i{0}; i < N; i++){

      int num;
      cin>>num;
      arr.push_back(num);
    }

    if(N == 1){
      cout<<0<<"\n";
      continue;
    }

    vector<unsigned int>tmp(N, 0);

    for(int i{0}; i < N; i++){

      result.push_back(tmp);
      sum.push_back(tmp);
    }

    for(int i{0}; i < N; i++){

      for(int j{i}; j < N; j++){

        sum[i][j] = sum[i][j-1] + arr[j];

        if(j == i) 
          result[i][i] = arr[i];

        if(j == i + 1)
          result[i][j] = arr[i] + arr[j];
      }
    }

    for(int i{0}; i < N; i++){
      sum[i][i] = 0;
    }

    getAnswer(0, N -1);

    cout<<result[0][N-1]<<"\n";

    sum.clear();
    result.clear();
  }

  return 0;
}

unsigned int getAnswer(int start, int end){

  if(result[start][end] == 0){

    unsigned int answer = 4000000000; 

    for(int i{start};i < end; i++){

      answer = getMin(answer, getAnswer(start, i) + getAnswer(i + 1, end));
    }

    result[start][end] = answer;
  }

  return result[start][end] + sum[start][end];
}

unsigned  getMin(unsigned int a, unsigned int b){

  if(a > b)
    return b;

  return a;
}

