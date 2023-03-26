#include<iostream>
#include<queue>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL); cout.tie(NULL);

    int N;  cin >> N;
    priority_queue<int> q;
    for(int i{0}; i < N; i++){
        int num; cin >> num;
        q.push(-1 * num);
    }

    int answer = 0;
    int num1 ,num2, result;

    while(true){

        if(q.size() <= 1){
            break;
        }

        num1 = q.top(); q.pop();
        num2 = q.top(); q.pop();
        result = (num1 + num2) * -1;
        
        answer += result;

        q.push(result * -1);
    }

    cout<<answer<<"\n";

    return 0;
}