#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

const int N = 10;
const int LIMIT = 42;

int main()
{
	cin.tie(NULL);

    int result = 0;
    vector<bool> is_number_checked(LIMIT, false);

    for(int i{0}; i < N; i++){
        int num;
        cin>>num;

        int remainder = num % 42;
        if(!is_number_checked[remainder]){
            is_number_checked[remainder] = true;
            result++;
        }  
    }

    cout<<result<<"\n";
    
	return 0;
}