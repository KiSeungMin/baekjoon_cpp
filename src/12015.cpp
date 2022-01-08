#include<iostream>
#include<vector>
using namespace std;

int search(int start, int end, int target, vector<int>& arr);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>DP(1000001, 0);
    
    int N;
    cin>>N;
 
    vector<int>arr;

    for(int i{0}; i < N; i++){
       int num;
       cin>>num;
       arr.push_back(num);
    }
    
    DP[1] = arr[0];
    int answer = 1;

    for(int i{1}; i < arr.size(); i++){

      if(arr[i] > DP[answer]){

          answer++;
          DP[answer] = arr[i];
          continue;
      }

      int index = search(1, answer - 1, arr[i], DP);
      DP[index] = arr[i];
    }

    cout<<answer<<"\n";

    return 0;
}

int search(int start, int end, int target, vector<int>& arr){

   if(target < arr[start]){
       return start;
   }

   if(target > arr[end]){
       return end + 1;
   }

   int center = (end + start)/2;

   if(target == arr[center])
       return center;

   else if(start >= end)
        return center;

   else if(target < arr[center]){

       if(target > arr[center - 1])
          return center;

       return search(start, center - 1, target, arr);
   }

   else if(target > arr[center]){

       if(target  < arr[center + 1])
           return center + 1;

        return search(center + 1, end, target, arr);
   }

   return 0;
}
