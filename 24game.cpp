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

bool compareDouble(double x, double y)
{
	int diff = x - y;
	return diff < 1e-5 && -diff < 1e-5;
}

bool Solve24_rec(vector<card>& nums, string& solution)
{
	int n = nums.size();
	if (n == 0)
		return false;
	else if (n == 1 && compareDouble(nums[0].val, 24.0))
	{
		solution = nums[0].msg; // record how the answer is obtained
		return true;
	}
	else if (n == 1)
		return false;

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			card left = nums[i];
			card right = nums[j];

			vector<card> nums_rest;
			for (int k = 0; k < n; ++k)
				if (k != i && k != j)
					nums_rest.push_back(nums[k]);

			for (int k = 0; k < 6; ++k)
			{
				// try all possible six operations with the two numbers
				// notice that left - right and right - left, left / right and right / left are different operations
				vector<card> temp = nums_rest;
				if (k == 0) temp.push_back({ left.val + right.val, update_message(left.msg, right.msg, '+') });
				else if (k == 1) temp.push_back({ left.val - right.val, update_message(left.msg, right.msg, '-') });
				else if (k == 2) temp.push_back({ right.val - left.val, update_message(right.msg, left.msg, '-') });
				else if (k == 3) temp.push_back({ left.val * right.val, update_message(left.msg, right.msg, '*') });
				else if (k == 4 && right.val != 0) temp.push_back({ left.val / right.val, update_message(left.msg, right.msg, '/') });
				else if (k == 5 && left.val != 0) temp.push_back({ right.val / left.val, update_message(left.msg, right.msg, '/') });

				if (Solve24_rec(temp, solution))
					return true;
			}

		}

	return false;
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
