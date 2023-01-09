#include <iostream>
#define sync_with_stdio(NULL)
using namespace std;

const int LIMIT = 10001;

int main(void) {
    
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int count_num_arr[LIMIT] = { 0, };
    cin >> N;

    for (int i = 0; i < N; i++) {

        int input_num;
        cin >> input_num;
        count_num_arr[input_num]++;
    }

    for(int i{1}; i < LIMIT; i++){
        for(int j{0}; j < count_num_arr[i]; j++)
            cout<<i<<"\n";
    }
}
