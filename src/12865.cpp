#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int N, weightLimit;

    cin>>N>>weightLimit;

    vector<pair<int, int>>arr;

    for(int i{0}; i<N; i++){

        int num1;
        int num2;

        cin>>num1>>num2;

        pair<int, int>tmp={num1, num2};

        arr.push_back(tmp);
    }

    int answer=0;

    // 무게가 0~weightLimit일 때 가장 가치가 높은 값을 저장하는 벡터
    vector<int>maxWeight(weightLimit + 1, 0);

    // maxWeight의 값을 변경할 경우 그 쌍을 추가하는 벡터
    vector<pair<int, int>>board;

    board.push_back({0, 0});

    for(int i{0}; i < N; i++){

        int boardSize=board.size();

        for(int j{0}; j < boardSize; j++){

            int weight = arr[i].first + board[j].first;
            int value= arr[i].second + board[j].second;

            if(weight <= weightLimit && value > maxWeight[weight]){

                maxWeight[weight]=value;
                board.push_back({weight, value});

                if(value > answer)
                    answer=value;
            }
        }
    }

    cout<<answer<<endl;
   
    return 0;
}
