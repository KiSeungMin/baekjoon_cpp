#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int N;
vector<int>preOrder;
vector<int>inOrder;
vector<int>postOrder;
vector<bool>check;

vector<pair<int, int>>child;
vector<int>parent;

void getPreOrder(stack<int>&stk);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;
  
  for(int i{0}; i < N + 1; i++){
    pair<int, int>tmp;
    child.push_back(tmp);

    check.push_back(false);
    parent.push_back(0);
  }

  for(int i{0}; i < N; i++){

    char index;
    char child1, child2;
    int id, ch1, ch2;

    cin>>index>>child1>>child2;

    id = index - 'A' + 1; 
    ch1 = child1 == '.' ? 0 : child1 - 'A' + 1;
    ch2 = child2 == '.' ? 0 : child2 - 'A' + 1;

    pair<int, int>tmp = {ch1, ch2};
    child[static_cast<int>(index-'A' + 1)] = tmp;

    parent[ch1] = id;
    parent[ch2] = id;
  }

  // A == 1 B == 2 C == 3
  
  // getPreOrder
  stack<int>stk;
  stk.push(1);
  getPreOrder(stk);

  for(int i{0}; i < preOrder.size(); i++){
    cout<<static_cast<char>(preOrder[i] + 64);
  }
  cout<<"\n";

  int index = 1;
  int firstChild;
  int secondChild;

  // getInOrder
  
  while(true){

    if(inOrder.size() == N || index == 0)
      break;

    if(check[index]){
      index = parent[index];
      continue;
    }

    firstChild = child[index].first;
    secondChild = child[index].second;

    // NO CHILD

    if(firstChild == 0 && secondChild == 0){

      inOrder.push_back(index);
      check[index] = true;

      if(inOrder.size() == N)
        break;

      else{
        index = parent[index];
        continue; 
      }
    }

    // HAS FIRST CHILD

    if(firstChild != 0){

      if(check[firstChild]){
        inOrder.push_back(index);
        check[index] = true;

        if(secondChild != 0){
          index = secondChild;
          continue;
        }

        else{
          index = parent[index];
          continue;
        }
      }

      else
        index = firstChild;
        continue;
    }

    // ONLY HAS SECOND CHILD

    else{
      inOrder.push_back(index);
      check[index] = true;
      index = secondChild;
      continue;
    }

    continue;
  }

  for(int i{0}; i < inOrder.size(); i++){
    cout<<static_cast<char>(inOrder[i] + 64);
  }
  cout<<"\n";

  for(int i{0}; i < check.size(); i++){
    check[i] = false;
  }

  index= 1;

  while(true){

    if(postOrder.size() == N || index == 0)
      break;

    firstChild = child[index].first;
    secondChild = child[index].second;

    if((firstChild == 0 || check[firstChild]) && (secondChild == 0 || check[secondChild])){
      check[index] = true;
      postOrder.push_back(index);
      index = parent[index];
      continue;
    }

    if(firstChild != 0){

      if(check[firstChild]){

        if(secondChild != 0){
          index = secondChild;
          continue;
        }

        index = parent[index];
        continue;
      }

      else{
        index = firstChild;
        continue;
      }
    }

    else{
      index = secondChild;
      continue;
    }
  }

  for(int i{0}; i < postOrder.size(); i++){
    cout<<static_cast<char>(postOrder[i] + 64);
  }
  cout<<"\n";

  return 0;
}

void getPreOrder(stack<int>& stk){

   int top = stk.top();
   stk.pop();

   preOrder.push_back(top);

   if(child[top].second != 0){
     stk.push(child[top].second);
   }

   if(child[top].first != 0){
     stk.push(child[top].first);
   }

   if(stk.size() == 0)
    return;

   getPreOrder(stk);
}