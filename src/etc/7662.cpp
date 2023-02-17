#include<iostream>
#include<queue>
#define sync_with_stdio(false)
using namespace std;

void getInput(){

    cin.tie(NULL);
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    int n; cin >> n;
    int insertCount = 0;
    int deleteCount = 0;
    int max_deleteCount = 0;
    int min_deleteCount = 0;
    char operation;
    int code;
    for(int i{0}; i < n; i++){
        cin >> operation;
        cin >> code;

        if(operation == 'I'){
            max_pq.push(code);
            min_pq.push(code);
            insertCount++;
        }

        else if(operation == 'D'){

            if(max_pq.empty() && min_pq.empty()){
                deleteCount = 0;
                continue;
            }

            if(code == 1){
                max_pq.pop();  
                max_deleteCount++;              
            } else if(code == -1){
                min_pq.pop();
                min_deleteCount++;
            }

            deleteCount++;

            if(insertCount <= deleteCount){
                while(!max_pq.empty()){
                    max_pq.pop();
                }
                while(!min_pq.empty()){
                    min_pq.pop();
                }

                insertCount = 0;
                deleteCount = 0;
                max_deleteCount = 0;
                min_deleteCount = 0;
            }
        }
    }

    for(int i{0}; i < max_deleteCount; i++){
        min_pq.pop();
    }

    for(int i{0}; i < min_deleteCount; i++){
        max_pq.pop();
    }

    if(max_pq.empty() && min_pq.empty()){
        cout<<"EMPTY\n";
    } else{
        cout<<max_pq.top() <<" "<<min_pq.top()<<"\n";
    }
}

int main(){

    int T; cin >> T;
    for(int t{0}; t < T; t++){
        getInput();        
    }
    
    return 0;
}