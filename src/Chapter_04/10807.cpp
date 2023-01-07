#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL);

    int N;
    cin>>N;

    vector<int> number_count (201, 0);

    for (int i{0}; i < N; i++){
        int num;
        cin>>num;

        number_count[num + 100] ++;
    }    

    int find_number;
    cin>>find_number;

    cout<<number_count[find_number + 100]<<"\n";

    return 0;
}