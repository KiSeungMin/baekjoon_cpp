#include<iostream>
#define sync_with_stdio(false)
using namespace std;

bool pita(int a, int b, int c);

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	while (a != 0 || b != 0 || c != 0){

		if(pita(a, b, c))
            cout<<"right\n";
        else
            cout<<"wrong\n";

		cin >> a >> b >> c;
	}

	return 0;
}

bool pita(int a, int b, int c){
     if(a > b){
        int tmp = a;
        a = b;
        b = tmp;
     }
     if(b > c){
        int tmp = b;
        b = c;
        c = tmp;
     }

     if(a * a + b * b == c * c)
        return true;

    return false;
}