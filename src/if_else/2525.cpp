#include<iostream>
using namespace std;

int main(){

    int hour, minute;
    cin >> hour >> minute;

    int plus_minute;
    cin>>plus_minute;

    minute += plus_minute;

    int plus_hour = minute / 60;
    
    minute = minute % 60;

    hour += plus_hour;
    hour = hour % 24;

    cout<<hour<<" "<<minute<<"\n";

    return 0;
}