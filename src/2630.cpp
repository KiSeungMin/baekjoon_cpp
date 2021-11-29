#include<iostream>
#include<vector>
using namespace std;

int whiteResult=0;
int blueResult=0;

vector<vector<bool>>arr;

void getAnswer(int rowStart, int colStart, int length);

int main(){

    int N;
    cin>>N;

    for(int i{0}; i < N; i++){
        
        vector<bool>tmp;
        for(int j{0}; j < N; j++){
            int num;
            cin>>num;
            tmp.push_back(int(num));
        }
        arr.push_back(tmp);
    }

    getAnswer(0, 0, N);

    cout<<whiteResult<<"\n"<<blueResult<<"\n";
    
    return 0;
}

void getAnswer(int rowStart, int colStart, int length){

    int count=0;

    for(int i{0}; i < length; i++){

        for(int j{0}; j < length; j++){

            if(arr[i + rowStart][j + colStart])
                count++;
        }
    }

    if(count == length * length){
        blueResult++;
        return;
    }

    else if(count == 0){
        whiteResult++;
        return;
    }

    getAnswer(rowStart, colStart, length/2);
    getAnswer(rowStart, colStart + (length/2), length/2);
    getAnswer(rowStart + (length/2), colStart, length/2);
    getAnswer(rowStart + (length/2), colStart + (length/2), length/2);

}