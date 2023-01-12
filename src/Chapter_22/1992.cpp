#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N;
vector<vector<bool>>arr;

void getAnswer(int rowStart, int colStart, int length);

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin>>N;

    for(int i{0}; i < N; i++){
        string s;
        cin>>s;
        vector<bool>tmp;
        for(int j{0}; j < N; j++){
            if(s[j] == '1'){
                tmp.push_back(1);
            }
            else if(s[j]=='0'){
                tmp.push_back(0);
            }
        }

        arr.push_back(tmp);
    }

    getAnswer(0, 0, N);

    cout<<"\n";

    return 0;
}

void getAnswer(int rowStart, int colStart, int length){

    int count=0;

    for(int i{0}; i < length; i++){
        for(int j{0}; j < length; j++){

            if(arr[rowStart + i][colStart + j])
                count++;
        }
    }
    
    if(count == length * length){

        if(length == N){
            cout<<1;
            return;
        }
        cout<<1;
        return;    
    }

    else if(count == 0){
        
        if(length == N){
            cout<<0;
            return;
        }
        cout<<0;
        return;
    }

    cout<<"(";

    int nextLength=length/2;

    getAnswer(rowStart, colStart, nextLength);
    getAnswer(rowStart, colStart + nextLength, nextLength);
    getAnswer(rowStart + nextLength, colStart, nextLength);
    getAnswer(rowStart + nextLength, colStart + nextLength, nextLength);

    cout <<")";
}