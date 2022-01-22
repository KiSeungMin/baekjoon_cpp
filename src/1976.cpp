#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<int> parent;
vector<int> goal;
vector<vector<int>> graph;

void input();
void getAnswer();

int main() {
  input();
  getAnswer();
}

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i{0}; i <= N; i++) {
    parent.push_back(-1);
  }

  vector<int> tmptmp;
  graph.push_back(tmptmp);

  for (int i{0}; i < N; i++) {
    vector<int> tmp;
    tmp.push_back(0);
    for (int j{0}; j < N; j++) {
      int num;
      cin >> num;
      tmp.push_back(num);
    }

    graph.push_back(tmp);
  }

  for (int i{0}; i < M; i++) {
    int num;
    cin >> num;
    goal.push_back(num);
  }

}

void getAnswer() {
  for (int i{1}; i <= N; i++) {

    for (int j{i}; j <= N; j++) {
      
      if (graph[i][j] == 0)
        continue;

      else {
        int pointer1 = i;
        int pointer2 = j;

        if (parent[i] == -1)
          pointer1 = -1;

        else {
          while (parent[pointer1] != pointer1) pointer1 = parent[pointer1];
        }

        if (parent[j] == -1)
          pointer2 = -1;

        else {
          while (parent[pointer2] != pointer2) pointer2 = parent[pointer2];
        }

        if (pointer1 == -1 && pointer2 == -1) {
          parent[i] = i;
          parent[j] = i;
          continue;
        }

        else if (pointer1 != -1 && pointer2 == -1) {
          parent[j] = pointer1;
          continue;
        }

        else if (pointer1 == -1 && pointer2 != -1) {
          parent[i] = pointer2;
          continue;
        }

        else if (pointer1 == pointer2)
          continue;

        else {
          parent[pointer2] = pointer1;
          continue;
        }
      }
    }
  }


  if (M <= 1) {
    cout << "YES" << '\n';
    return;
  }

  int parentAll = parent[goal[0]];

  if(parentAll == -1){

    for(int i{1}; i < M; i++){
      if(goal[i] != goal[0]){
        cout<<"NO"<<'\n';
        return;
      }
    }

    cout<<"YES"<<'\n';
    return;
  }

  while (parentAll != parent[parentAll]) parentAll = parent[parentAll];

  for (int i{1}; i < M; i++) {

    int parentNow = parent[goal[i]];

    if(parentNow == -1){
      cout<<"NO"<<'\n';
      return;
    }

    while (parentNow != parent[parentNow]) parentNow = parent[parentNow];

    if (parentAll != parentNow) {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
  return;
}