#include<iostream>
#include<vector>
using namespace std;

int N;
int maximum=-1000000000;
int minimum=1000000000;
const int operatorCount=4;

vector<int>num;
vector<vector<int>>operatorArray;

void getOperator(int position, vector<int>operatorInput, vector<int> result);
void getAnswer();

int main(){

    cin>>N;

    vector<int>operatorInput(operatorCount, 0);

    for(int i{0}; i<N; i++){

        int n; cin>>n;

        num.push_back(n);
    }

    for(int i{0}; i<operatorCount; i++){

        int n; cin>>n;         
        operatorInput[i]=n; 
    }

    for(int i{0}; i<operatorCount; i++){

        if(operatorInput[i]>0){
            vector<int>tmp={};
            getOperator(i, operatorInput, tmp);
        }
    }

    getAnswer();

    cout<<maximum<<"\n"<<minimum<<"\n";

    return 0;
}

void getOperator(int position, vector<int>operatorInput, vector<int> result){

    result.push_back(position);

    if(result.size() == N-1){

        operatorArray.push_back(result);
        return;
    }

    operatorInput[position]--;

    for(int i{0}; i<operatorCount; i++){

        if(operatorInput[i] > 0){
            getOperator(i, operatorInput, result);
        }
    }
}

void getAnswer(){

    for(size_t i{0}; i<operatorArray.size(); i++){

        int answer=num[0];

        int operatorIndex=0;

        for(int j{1}; j<N; j++){

            switch(operatorArray[i][operatorIndex]){
                case 0:
                    answer=answer+num[j];
                    break;

                case 1:
                    answer=answer-num[j];   
                    break;

                case 2:
                    answer=answer*num[j];
                    break;

                case 3: 
                    answer=answer/num[j];
                    break;
            }

            operatorIndex++;
        }

        if(answer > maximum)
            maximum=answer;

        if(answer < minimum)
            minimum=answer;
    }

}





