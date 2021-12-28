#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

unsigned long long answer = 0;

void getAnswer(vector<unsigned long long>& arr);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin>>T;

  for(int t{0}; t < T; t++){

    int N;
    cin>>N;

    vector<unsigned long long>arr;

    for(int i{0}; i < N; i++){

      int num;
      cin>>num;
      arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    getAnswer(arr);

    cout<<answer<<"\n";
  }

  return 0;
}

void getAnswer(vector<unsigned long long>& arr){

  for(int i{0}; i < arr.size(); i++){
    cout<<arr[i]<<" ";
  }

  cout<<"\n";

  if(arr.size() == 1)
    return;

  vector<unsigned long long>nextArr;

  for(int i{0}; i < arr.size(); i=i+2){

    if(i == arr.size()-1){
      nextArr.push_back(arr[i]);
      continue;
    }

    answer = answer + arr[i] + arr[i+1];
    nextArr.push_back(arr[i] + arr[i + 1]);
  }

  sort(nextArr.begin(), nextArr.end());

  getAnswer(nextArr);
}