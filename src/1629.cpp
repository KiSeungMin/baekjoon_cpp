#include<iostream>
using namespace std;

long long solution(long long A, long long B, long long C){
    long long answer = 1;
    A %= C;
        while(B > 0){

            if(B % 2 ==1){
                answer *= A;
                answer %=C;
            }

            A=((A%C) * (A%C))%C;

            B >>=1;
        }
    return answer;
}

int main(){

    long long A, B, C;
    cin>>A>>B>>C;

    cout<<solution(A, B, C);

    return 0;
}

/*
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int change=0;
const int bigInt=2147483647;

// A * A 를 C로 나눈 나머지는 abs(A-C)의 제곱을 C로 나눈 나머지와 같다.

int main(){

    int A, B, C;
    cin>>A>>B>>C;

    int num;
    int answer;

    vector<pair<int, int>>board;

    if(abs(A-C) > A)
        num=A;

    else
        num=A-C;

    pair<int, int> tmp={num, 1};
    board.push_back(tmp);

    while(board[board.size()-1].second < (bigInt / 2) && board[board.size()-1].second <= B){

        unsigned int last = board.size()-1;

        int fir = board[last].first * board[last].first;
        fir=fir % C;

        int sec= board[last].second * 2;

        pair<int, int> tmp = {fir, sec};

        board.push_back(tmp);
    }

    int powNow=0;
    int result=1;

    for(size_t i{board.size()-1}; i >=0 && i < 10000; i--){

        if(board[i].second + powNow <= B){
            result = result * board[i].first;
            powNow = powNow + board[i].second;

            if(result < 0){
                result = -1 * (abs(result) % C);
                continue;
            }

            else{
                result = result % C;
                continue;
            }
        }
    }

    if(result < 0)
        answer = C + result;

    else
        answer = result;

    cout<<answer<<endl;

}
*/