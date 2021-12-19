#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// find cycle

bool DFS(queue<int>& node, vector<bool>&recent, vector<bool>&visited, vector<vector<int>>& graph);

bool answer =true;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin>>T;

  for(int t{0}; t < T; t++){
    
    int point, line;
    cin>>point>>line;

    vector<int>tmp;
    vector<vector<int>>graph(point + 1, tmp);

    for(int i{0}; i < line; i++){

      int num1, num2;
      cin>>num1>>num2;

      graph[num1].push_back(num2);
      graph[num2].push_back(num1);
    }

    vector<bool>visited(point + 1, false); 

    for(int i{1};i <= point; i++){
      
      if(visited[i] == false){

        queue<int>node;
        node.push(i);

        vector<bool>recent (point+1, false);
        recent[i] = true;

        if(DFS(node, recent, visited, graph) == false){
          answer = false;
          break;
        }
      }
    }

    if(answer)
      cout<<"YES"<<"\n";

    else
      cout<<"NO"<<"\n";

    answer = true;
  }

  return 0;
}

bool DFS(queue<int>& node, vector<bool>&recent, vector<bool>&visited, vector<vector<int>>& graph){
  
  int size = node.size();

  for(int i{0}; i < size; i++){

    int front = node.front();

    node.pop();

    recent[front] = false;

    for(auto j : graph[front]){

      if(visited[j] == true){
        
        if(recent[j] == true)
          return false;
      }

      else if(visited[j] == false){
        node.push(j);
        visited[j] = true;
        recent[j] = true;
      }
    }
  }

  if(node.size() == 0)
    return true;

  DFS(node, recent, visited, graph);

  return true;
}