#include<iostream>
#include<vector>
#include<iomanip>
#define sync_with_stdio(false)
using namespace std;

int T;

int main()
{
	cin.tie(NULL);
	
	cin >> T;

	for (int t{ 0 }; t < T; t++)
	{
		int count_student;
		cin >> count_student;

		vector<int>score_student;
		int sum_score{ 0 };
		
		for (int i{ 0 }; i < count_student; i++){
			int score;
			cin >> score;
			score_student.push_back(score);
		}

		for (int i{ 0 }; i < count_student; i++){
			sum_score += score_student[i];
		}

        int count_over_average{ 0 };
		double average = static_cast<double>(sum_score) / count_student;
		for (int i{ 0 }; i < count_student; i++)
		{
			if (score_student[i] > average)
				count_over_average++;
		}

		double result = (static_cast<double>(count_over_average) / count_student)*100;
		cout << setprecision(3) << fixed << result << "%\n";
	}
	return 0;
}