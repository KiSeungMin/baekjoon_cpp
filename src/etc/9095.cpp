#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int factorial(int n){
    int result = 1;

    for(int i{1}; i <= n; i++){
        result *= i;
    }

    return result;
}

int getResult(int count_three, int count_two, int count_one){
    return factorial(count_three + count_two + count_one) / (factorial(count_three) * factorial(count_two) * factorial(count_one));
}

int getLogic(int num){

    int result = 0;
    int num_now = num;

    for(int count_three{0}; count_three * 3 <= num_now; count_three++){

        num_now = num_now - (3 * count_three);
        for(int count_two{0}; count_two * 2 <= num_now; count_two++){

            num_now = num_now - (2 * count_two);
            result += getResult(count_three, count_two, num_now);

            num_now += (2 * count_two);
        }

        num_now += (3 * count_three);
    }

    return result;
}

int main(){
    
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>answer_arr;

    for(int i{1}; i <= 10; i++){
        answer_arr.push_back(getLogic(i));
    }

    int T; cin >> T;
    for(int t{0}; t < T; t++){
        int num; cin >> num;
        cout<<answer_arr[num - 1]<<"\n";
    }

    return 0;
}