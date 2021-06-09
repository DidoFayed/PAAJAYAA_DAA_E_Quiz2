#include <iostream>
#include <string>
#include <vector>

/* implementation of a 24 game solver using depth first search algorithm
given four cards, each card contains number 1 to 9 */
using namespace std;

struct card  
{
	double val;
	string msg;
};

bool Solve24_rec(vector<card>& nums, string& solution);

bool Solve24(vector<int>& nums, string& solution)
{
	vector<card> input;
	for (int i = 0; i < nums.size(); ++i)
		input.push_back({ (double) nums[i], to_string(nums[i]) });

	return Solve24_rec(input, solution);
}

bool hasChar(string s, char c)
{
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == c)
			return true;
	return false;
}

bool has_unbound_operator(string msg, string op)
{
	string s;
	for (int i = 0; i < msg.size(); ++i)
		if (!(isdigit(msg[i]) || msg[i] == ' '))
			s += msg[i];
	
	bool res = false;
	for (int j = 0; j < op.size(); ++j)
		for (int k = 0; k < s.size(); ++k)
			if (s[k] == '(')
				k += 2;
			else if (s[k] == op[j])
				res = true;
	return res;
}

int main()
{
	vector<int> test(4);

	cout << "Enter number from 1 - 9" << endl;

    cout << "Enter the first number : ";
    cin >> test[0];
    cout << "Enter the second number : ";
    cin >> test[1];
    cout << "Enter the third number : ";
    cin >> test[2];
    cout << "Enter the fourth number : ";
    cin >> test[3];
	
	string method;
	bool out = Solve24(test, method);
	if(out)
	{
		cout << "the solution of " << ' ' << test[0] << ' ' << test[1] << ' ' << test[2] << ' ' << test[3] << " is: " << ' ' << method << endl;
		cout << " " << endl;
	}
	else
	{
		cout << "Sorry, there is no solution for the given numbers" << endl;
		cout << " " << endl;
	}
}
