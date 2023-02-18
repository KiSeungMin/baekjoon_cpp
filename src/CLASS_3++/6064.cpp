#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

vector<int>answers;

int GCD(int a, int b){

    if(a % b == 0)
        return b;

    return GCD(b, a % b);
}

void getAnswer(int N, int M, int a, int b){

    int LIMIT = (N * M) / GCD(N, M);

    int num1 = a;
    int num2 = b;
    int answer = -1;

    while(num1 <= LIMIT && num2 <= LIMIT){

        if(num1 == num2){
            answer = num1;
            break;
        }

        if(num1 > num2)
            num2 += M;

        else if(num1 < num2)
            num1 += N;
    }

    answers.push_back(answer);
}   

int main(){

    cin.tie(NULL);  cout.tie(NULL);

    int T; cin >> T;
    for(int t{0}; t < T; t++){
        int N, M, a, b;
        cin >> N >> M >> a >> b;
        getAnswer(N, M, a, b);
    }

    for(auto i : answers){
        cout<<i<<"\n";
    }

    return 0;
}