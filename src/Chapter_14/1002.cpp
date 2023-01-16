#include<iostream>
#include<cmath>
using namespace std;

int turret(int& x1, int& y1, int& r1, int& x2, int& y2, int& r2);

int main(){
	int T;
	cin >> T;
	int x1, y1, r1, x2, y2, r2;
	for (int t{ 0 }; t < T; t++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << turret(x1, y1, r1, x2, y2, r2) << endl;
	}
	return 0;
}

int turret(int& x1, int& y1, int& r1, int& x2, int& y2, int& r2){
	double d = abs(sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));

	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
		return -1;

	else if ((x1 == x2) && (y1 == y2) && (r1 != r2))
		return 0;
        
	else if (d > (r1 + r2))
		return 0;
	
	else if (d == (r1 + r2))
		return 1;
	
	else if ((d>abs(r1-r2)) && (d<(r1+r2)))
		return 2;
	
	else if (d==(abs(r1-r2)))
		return 1;

	else if (d<(abs(r1-r2)))
		return 0;
	
}