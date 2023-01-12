#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

// find cycle

void DFS(queue<int>& node, vector<int>& color, vector<bool>&visited, vector<vector<int>>& graph);

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

    vector<int>color(point + 1, -1);
    vector<bool>visited(point + 1, false); 

    for(int i{1};i <= point; i++){
      
      if(visited[i] == false){

        queue<int>node;
        node.push(i);

        color[i] = 0;
        visited[i]=true;

        DFS(node, color, visited, graph);
        
        if(answer == false)
          break;

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

void DFS(queue<int>& node, vector<int>& color, vector<bool>&visited, vector<vector<int>>& graph){
  
  int size = node.size();

  for(int i{0}; i < size; i++){

    int front = node.front();

    node.pop();

    for(auto j : graph[front]){

      if(visited[j] == true){

        if(color[j] == color[front]){
          answer =false;
          return;
        }
      }

      else if(visited[j] == false){
        node.push(j);
        visited[j] = true;
        color[j] = abs(color[front] -1);
      }
    }
  }

  if(node.size() == 0)
    return;

  DFS(node, color, visited, graph);

  return;
}