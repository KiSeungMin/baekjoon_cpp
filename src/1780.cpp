#include<iostream>
#include<vector>
using namespace std;

int minusAns=0;
int zeroAns=0;
int oneAns=0;
vector<vector<int>>arr;

void getAnswer(int rowStart, int colStart, int length);

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin>>N;

    for(int i{0}; i < N; i++){
        vector<int>tmp;
        for(int j{0}; j < N; j++){

            int num;
            cin>>num;
            tmp.push_back(num);
        }
        arr.push_back(tmp);
    }

    getAnswer(0, 0, N);

    cout<<minusAns<<"\n"<<zeroAns<<"\n"<<oneAns<<"\n";
    return 0;
}

void getAnswer(int rowStart, int colStart, int length){

    int one=0;
    int zero=0;
    int minus=0;

    for(int i{0}; i < length; i++){

        for(int j{0}; j < length; j++){

            switch(arr[rowStart + i][colStart + j]){

                case -1:
                    minus++;
                    break;

                case 0:
                    zero++;
                    break;

                case 1:
                    one++;
                    break;
            }
        }
    }

    if(minus == length * length){
        minusAns++;
        return ;
    }

    else if(zero == length * length){
        zeroAns++;
        return;
    }

    else if(one == length * length){
        oneAns++;
        return;
    }

    int len = length / 3;

    getAnswer(rowStart, colStart, len);
    getAnswer(rowStart, colStart + len, len);
    getAnswer(rowStart, colStart + 2 * len, len);
    getAnswer(rowStart + len, colStart, len);
    getAnswer(rowStart + len, colStart + len, len);
    getAnswer(rowStart + len, colStart + 2*len, len);
    getAnswer(rowStart + 2*len, colStart, len);
    getAnswer(rowStart + 2*len, colStart + len, len);
    getAnswer(rowStart + 2*len, colStart + 2*len, len);

}