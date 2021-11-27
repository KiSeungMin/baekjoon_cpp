#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){

    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin>>N;

    vector<int>result(N, -1);
    stack<pair<int, int>> stk;

    for(int i{0}; i <N; i++){
        
        int num;
        cin>>num;

        // 입력받은 수보다 작을 경우 스택에서 제거하고 result 벡터에 num값 저장
        while(!stk.empty() && num > stk.top().first){

            result[stk.top().second]=num;
            stk.pop();
        }

        pair<int, int>tmp={num, i};
        stk.push(tmp);
    }

    for(auto v : result)
        cout<<v<<" ";

    cout<<endl;

    return 0;
}