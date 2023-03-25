#include<iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;

    char result;

	if (a >= 90 && a <= 100){
		result = 'A';
	}
	else if (a >= 80 && a < 90){
		result = 'B';
	}
    else if (a >= 70 && a < 80){
		result = 'C';
	}
	else if (a >= 60 && a < 70){
		result = 'D';
	}
	else{
		result = 'F';
	}

    cout<<result<<"\n";
    
	return 0;
}