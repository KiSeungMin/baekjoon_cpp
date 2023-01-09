#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(NULL)
using namespace std;

int COUNT_STUDENT;
int CUT_RANK;

int main(){

    cin>>COUNT_STUDENT>>CUT_RANK;

    vector<int>scores(COUNT_STUDENT, 0);
    for(int i{0}; i < COUNT_STUDENT; i++){
        cin>>scores[i];
    }

    sort(scores.begin(), scores.end());

    cout<<scores[COUNT_STUDENT - CUT_RANK]<<"\n";

    return 0;
}