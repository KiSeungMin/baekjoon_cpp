#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

  int N, goal;
  cin>>N>>goal;

  vector<int>arr;
  vector<int>sum;
  sum.push_back(0);
  for(int i{0}; i < N; i++){
    int num;
    cin>>num;
    
    if(num == goal)
    {
      cout<<1<<"\n";
      return 0;
    }

    sum.push_back(sum[sum.size()-1] + num);

    arr.push_back(num);
  }

  int answer = N;
  int start = N;
  int end = N;

  if(sum[sum.size()-1] < goal){
    cout<<0<<"\n";
    return 0;
  }

  while(end >= 0){

    while(sum[end] - sum[start] < goal && start >= 0)
      start--;

    if(sum[end] - sum[start] >= goal){

      if(end - start < answer)
        answer = end - start;
    }

    end--;
  }

  cout<<answer<<'\n';

  return 0;
}