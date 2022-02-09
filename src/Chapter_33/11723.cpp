
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

  //vector<bool>arr (20, false);
  //vector<bool>T (20, true);
  //vector<bool>F (20, false);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin>>N;

  int bitSet = 0;
  bitSet |= (0 << 21);

  for(int i{0}; i < N; i++){

    string cmd;
    int index;

    cin>>cmd;

    if(cmd == "add"){
      
      cin>>index;

      bitSet |= (1 << index);      
      //arr[index - 1] = true;
    }

    else if(cmd == "remove"){

      cin>>index;

      bitSet =  bitSet & ~(1 << index); 
     //arr[index - 1]=false;
    }

    else if(cmd == "check"){

      cin>>index;

      if(bitSet & (1 << index)){
        cout<<1<<"\n";
      }

      else{
        cout<<0<<"\n";
      }

      /*
      if(arr[index - 1])
        cout<<1<<"\n";

      else
        cout<<0<<"\n";
      */
    }

    else if(cmd == "toggle"){
      cin>>index;

      bitSet = bitSet ^ (1 << index);
      //arr[index-1] = !arr[index-1];
    }
    
    else if(cmd == "all"){
      //arr = T;
      for(int i {1}; i <= 20; i++){
        bitSet |= (1 << i);
      }
    }

    else if(cmd == "empty"){
      //arr = F; 
      bitSet &= (1 << 21);
    }
  }

  return 0;
}
