#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N, M;
    cin>>N>>M;

    vector<int>up;
    vector<int>down;
    int answer=0;

    for(int  i{0}; i<M; i++){
        up.push_back(N-i);
        down.push_back(i+1);
    }

    for(int i{0}; i < down.size(); i++){

        for(int j{0}; j < up.size(); j++){

            if(up[j] % down[i] ==0){
                up[j]=up[j]/down[i];
                break;
            }
        }
    }

    for(int i{0}; i < up.size(); i++){

        while(up[i] % 10 == 0){
            up[i] = up[i] / 10;
            answer++;
        }

        up[i]=up[i] % 10000;
    }

    for(int i{1}; i < up.size(); i++){

        up[i]=up[i] * up[i-1];

        while(up[i] % 10 ==0){
            up[i] = up[i] /10;
            answer++;
        }

        up[i]=up[i] % 10000;
    }

    cout<<answer<<endl;

    return 0;
}