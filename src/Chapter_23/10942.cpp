#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int>arr;
vector<vector<int>>DP;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;

  for(int i{0}; i < N; i++){
    int num;
    cin>>num;
    arr.push_back(num);

    vector<int>tmp(N , -1);
    tmp[i] = 1;
    DP.push_back(tmp);
  }

  for(int i{0}; i < N; i++){

    // 가운데 숫자가 하나일 경우

    bool decal1 = true;

    int ptr1 = i;
    int ptr2 = i;

    while(ptr1 >= 0 && ptr2 < N){

      if(decal1){
        
        if(arr[ptr1] != arr[ptr2])
          decal1=false;
      } 

      DP[ptr1][ptr2] = decal1;    

      ptr1--;
      ptr2++;
    }

    // 가운데 숫자가 2개일 경우

    bool decal2 = true;

    int ptr3 = i;
    int ptr4 = i + 1;

    while(ptr3 >= 0 && ptr4  <  N){

      if(decal2){

        if(arr[ptr3] != arr[ptr4])
          decal2 = false;
      }

      DP[ptr3][ptr4] = decal2;

      ptr3--;
      ptr4++;
    }
  }

  int M;
  cin>>M;

  for(int i{0}; i< M; i++){

    int num1, num2;
    cin>>num1>>num2;

    cout<<DP[num1-1][num2-1]<<"\n";
  }

  return 0;
}