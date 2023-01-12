#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N;
    cin>>N;

    vector<long long>distance;
    vector<long long>point;

    for(int i{0}; i < N-1; i++){
        long long num;
        cin>>num;

        distance.push_back(num);
    }

    for(int i{0}; i < N; i++){
        long long num;
        cin>>num;

        point.push_back(num);
    }

    int start=0;
    int end=N-1;

    long long answer=0;

    while(true){

        for(int i{start+1}; i < N; i++){

            if(point[start] > point[i]){
                end=i;
                break;
            }
        }

        for(int j{start}; j < end; j++){
            answer=answer + point[start] * distance[j];
        }

        start=end;
        end=N-1;

        if(start >= N - 1)
            break;
    }

    cout<<answer<<endl;

    return 0;
}