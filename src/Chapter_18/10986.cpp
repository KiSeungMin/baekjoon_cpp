#include<iostream>
#include<vector>
#include<queue>
#define sync_with_stdio(false)
using namespace std;

int N, M;
int answer = 0;

vector<int>input_arr;

void getAnswer(vector<int>& before, vector<int>& after, queue<int>&nextInt, int index);

int main(){

    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;

    for(int i{0}; i < N; i++){
        int input_num; cin>>input_num;
        input_arr.push_back(input_num);
    }

    vector<int>before(M, 0);
    vector<int>after(M, 0);
    queue<int>nextInt;

    int num = input_arr[0] % M;
    before[num]++;
    nextInt.push(num);

    if(num == 0)
        answer++;

    if(N > 1)
        getAnswer(before, after, nextInt, 1);

    cout<<answer<<"\n";

    return 0;
}

void getAnswer(vector<int>& before, vector<int>& after, queue<int>&nextInt, int index){
    
    int num = input_arr[index] % M;
    int length = nextInt.size();

    for(int j{0}; j < length; j++){
        int nowIndex = nextInt.front();
        nextInt.pop();

        int nextIndex = (nowIndex + num) % M;

        if(nextIndex == 0)
            answer += before[nowIndex];

        after[nextIndex] = before[nowIndex];

        nextInt.push(nextIndex);

        before[nowIndex] = 0;
    }

    if(after[num] == 0)
        nextInt.push(num);

    if(num == 0)
        answer++;

    after[num]++;

    if(index == N - 1)
        return;

    getAnswer(after, before, nextInt, index + 1);
}