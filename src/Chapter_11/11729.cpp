#include<iostream>
#include<cmath>
#define sync_with_stdio(false)
using namespace std;

int answer = 0;

void hanoi(int start_num, int end_num, int start_point, int end_point){

    if(start_num == end_num){
        cout<<start_point<<" "<<end_point<<"\n";
        answer++;
        return;
    }

    // 중간 지점 : 시작 지점과 목표 지점을 제외한 나머지 지점 (6에서 시작 지점이랑 끝 지점 빼면 중간 지점 나옴)
    int center_point = 6 - (start_point + end_point);

    hanoi(start_num, end_num - 1, start_point, center_point);
    hanoi(end_num, end_num, start_point, end_point);
    hanoi(start_num, end_num - 1, center_point, end_point);
}

int main(){

    cout.tie(NULL);

    int K;
    cin>>K;

    cout<<static_cast<int>(pow(2, K) - 1)<<"\n";

    hanoi(1, K, 1, 3);
}