#include<iostream>
#include<vector>
#define sync_with_stdio(false);
using namespace std;

vector<long long> getInput(int N){
    
    vector<long long>result;
    for(int i{0}; i < N; i++){
        long long num; cin >> num;
        result.push_back(num);
    }

    return result;
}

long long getAnswer(int N){

    long long min_value = 1000000000000;
    vector<long long> input_arr;
    for(int i{0}; i < N; i++){
        long long num; cin >> num;
        if(num < min_value){
            min_value = num;
        }
        input_arr.push_back(num);
    }
    
    long up_count = 1;
    long down_count = 1;
    long long answer = min_value * N;
    long long before = input_arr[N - 1];
    for(int i{N - 2}; i >= 0; i--){
        long long num_now = input_arr[i];
        long long result;

        if(num_now > before){
            up_count++;
            down_count = 1;
            result = up_count * before;

            if(result > answer)
                answer = result;
        }
        else if(num_now < before){
            down_count++;
            up_count = 1;
            result = down_count * num_now;

            if(result > answer)
                answer = result;
        }
        else{
            up_count++;
            down_count++;

            result = (up_count) * num_now;
            if(result > answer)
                answer = result;

            result = (down_count) * num_now;
            if(result > answer)
                answer = result;
        }

        before = num_now;
    }

    return answer;
}

int main(){

    cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    while(N != 0){
        cout<<getAnswer(N)<<"\n";
        cin >> N;
    }

    return 0;
}