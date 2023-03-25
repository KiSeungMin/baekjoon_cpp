#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int N;

int main()
{
	cin.tie(NULL);

    cin>>N;
    double sum_element = 0;
    int max_element = 0;

    for(int i{0}; i < N; i++){
        int num;
        cin>>num;

        sum_element += num;

        if(num > max_element)
            max_element = num;
    }

    double new_sum_element = sum_element * (100 / static_cast<double>(max_element));
    double new_average = new_sum_element / N;

    cout<<new_average<<"\n";
    
	return 0;
}