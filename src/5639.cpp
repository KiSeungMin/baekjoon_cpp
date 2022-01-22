#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>>child;

void postOrder(int num);
void getAnswer(int num, int root);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  vector<int>arr;
  while(cin>>n) arr.push_back(n);

  int size = arr.size();

  for(int i{0}; i < 1000000; i++){
    pair<int, int>tmp = {-1, -1};
    child.push_back(tmp);
  }

  int root = arr[0];

  for(int i{1}; i < size; i++){
    getAnswer(arr[i], root);
  }

  postOrder(arr[0]);

  return 0;
}

void getAnswer(int num, int root){

  if(num < root){

    if(child[root].first == -1)
      child[root].first = num;
    
    else
      getAnswer(num, child[root].first);
  }

  else if(num > root){

    if(child[root].second == -1)
      child[root].second = num;

    else
      getAnswer(num, child[root].second);
  }
}

void postOrder(int num){

  if(num == -1)
    return;

  postOrder(child[num].first);
  postOrder(child[num].second);

  cout<<num<<"\n";

  return;
}