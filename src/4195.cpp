#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N;
map<string, int>mp;   // {name, index}
vector<int>parent;    //  parent
vector<int>people;    // people count

void input();
void getAnswer(int index1, int index2);

int main(){

  int T;
  cin>>T;

  for(int t{0}; t <T ; t++){
    input();
  }
 
  return 0;
}

void input(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  mp.clear();
  parent.clear();
  people.clear();

  for(int i{0}; i < 200000; i++){
    parent.push_back(-1);
    people.push_back(1);
  }

  cin>>N;

  int key = 0;

  for(int i{0}; i < N; i++){
    string s1, s2;

    cin>>s1>>s2;

    auto find1 = mp.find(s1);
    int index1;

    // 없으면 새로 추가
    if(find1 == mp.end()){
      mp.insert({ s1, key });
      index1 = key;
      key++;
    }

    // 이미 있는 이름이면 기존에 있던 인덱스 참고
    else
      index1 = find1->second;
    
    auto find2 = mp.find(s2);
    int index2;

    // 없으면 새로 추가
    if(find2 == mp.end()){
      mp.insert({s2, key});
      index2 = key;
      key++;
    }

    // 이미 있는 이름이면 기존에 있던 인덱스 참고
    else
      index2 = find2->second;
    
    getAnswer(index1, index2);
  }
}

void getAnswer(int index1, int index2){

  int pointer1, pointer2;

  pointer1 = index1;
  pointer2 = index2;

  if(parent[index1] == -1)
    pointer1 = -1;
  
  else{
    while(parent[pointer1] != pointer1)
      pointer1 = parent[pointer1];
  }

  if(parent[index2] == -1)
    pointer2 = -1;

  else{
    while(parent[pointer2] != pointer2)
      pointer2= parent[pointer2];
  }

  if(pointer1 == -1 && pointer2 == -1){
    parent[index2] = index1;
    parent[index1] = index1;

    people[index1] = 2;
    people[index2] = 2;

    cout<<2<<'\n';
    return; 
  }

  else if(pointer1 != -1 && pointer2 == -1){
    parent[index2] = pointer1;

    people[pointer1]++;

    cout<<people[pointer1]<<"\n";

    return;
  }
  
  else if(pointer1 == -1 && pointer2 != -1){
    parent[index1] = pointer2;

    people[pointer2]++;
    
    cout<<people[pointer2]<<"\n";

    return;
  }

  else if(pointer1 == pointer2){
    cout<<people[pointer1]<<"\n";
    return;
  }

  else{
    parent[pointer2] = pointer1;

    people[pointer1] += people[pointer2];

    cout<<people[pointer1]<<"\n";

    return;
  }
}