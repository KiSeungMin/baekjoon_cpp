#include<iostream>
#include<vector>
using namespace std;

int N, M;

void init();

int main(){

  int T;
  cin>>T;

  for(int t{0}; t < T; t++){
    init();
  }
}

void init(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;

  for(int i{0}; i < M; i++){
    int num1, num2;
    cin>>num1>>num2;
  }

  cout<<N-1<<"\n";
}