#include<iostream>
#define sync_with_stdio(false)
using namespace std;

int getMin(int a, int b);

int main(){

    int x, y, w, h;
    cin>>x>>y>>w>>h;

    int xMin = getMin(x, abs(w - x));
    int yMin = getMin(y, abs(h - y));

    cout<<getMin(xMin, yMin)<<"\n";

    return 0;
}

int getMin(int a, int b){
    return (a < b ? a : b);
}