#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

  int N;
  cin>>N;

  vector<int>sosu;

  vector<bool>find(N + 1, true);
  find[0] = false;
  find[1] = false;

  for(int i{2}; i < N + 1; i++){

    if(!find[i])
      continue;

    sosu.push_back(i);

    for(int j{2 * i}; j < N + 1; j = j + i)
      find[j] = false;
    
  }

  int answer = 0;

  for(int i{0}; i < sosu.size(); i ++){
    
    if(sosu[i] > N)
      break;

    int res = 0;
    for(int j{i}; j < sosu.size(); j++){

      res += sosu[j];

      if(res < N)
        continue;

      else if(res == N){
        answer++;
        break;
      }

      else if(res > N)
        break;

    }
  }

  cout<<answer<<'\n';

  return 0;
}