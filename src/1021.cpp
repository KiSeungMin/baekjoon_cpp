#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int N, M;
    cin>>N>>M;

    vector<int>arr;
    deque<int>deq;

    for(int i{0}; i < M; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    for(int i{1}; i <= N; i++){
        deq.push_back(i);
    }

    int answer=0;

    for(int i{0}; i < arr.size(); i ++){

        auto it=find(deq.begin(), deq.end(), arr[i]);

        if(it - deq.begin() >= deq.end() - it + 1){

            while(deq.front() != arr[i]){
                
                deq.push_front(deq.back());
                deq.pop_back();
                answer++;
            }
        }
        else{

            while(deq.front() != arr[i]){

                deq.push_back(deq.front());
                deq.pop_front();
                answer++;
            }
        }

        deq.pop_front();
    }

    cout<<answer<<endl;

    return 0;
}