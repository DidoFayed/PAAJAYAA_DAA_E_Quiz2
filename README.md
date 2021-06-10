# The 24 Games Reports

##### Members:
- Dido Fabian Fayed       
  (05111940000059) 
- Vyra Fania Adelia       
  (05111940000109)
- Fidhia Ainun Khofifah   
  (05111940000203)


### Project Description

An implementation of 24 card games using Depth First Search algorithm with 4 input numbers. Each card contains a number 1 to 9. With 4 entered numbers, the 4 numbers must operated through some operators + (add), - (substract), / (divide), * (multiply), (, ) (bracket) to get 24 for the value.

For the example,
We have 2, 1, 3, 8 for the input numbers, the output will be shown 1 and the . It means that the calculation result of the formula is 24.
Explanation: (2-1) * 3 * 8

### Algorithm Description

We implement the depth first search algorithm in Search24_rec() function, where we use a recurrent approach. First we choose two numbers and try different operations for the solution. Then check if we can get 24 with the rest of the numbers and one of the result.

### Analysis
Made implementation of a 24 game solver using depth first search. Given four cards, determine whether a solution exists and return the solution
```c
# include<iostream>
# include<string>
# include<vector>
 
using namespace std;

struct card  
{
    double val;
    string msg;
};
 ```

After define a `card`, a `value` and `msg` (how this value is obtained), create recurrent `solve24` function that uses the remained numbers and the result from previous operation.  
```c
bool Solve24_rec(vector<card>& nums, string& solution);
```
The nums array contain four numbers from 1 to 9,  it will check if you can do arithmetic operations +, -, *, /, on these numbers and get twenty-four (24) as the result.
  
```c
  bool Solve24(vector<int>& nums, string& solution)
{
    vector<card> input;
    for (int i = 0; i < nums.size(); ++i)
        input.push_back({ (double) nums[i], to_string(nums[i]) });
 
    return Solve24_rec(input, solution);
}
```
This helper function `hasChar` to check if a string contains some char.
```c
bool hasChar(string s, char c)
{
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == c)
			return true;
	return false;
}
```
This helper function `has_unbound_operator` to check if a string contains a certain char not enclosed by parenthesis.
```c
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
```
`update_message` is a function to add operators, such as +, -, /, *, (, ) for the result. 
```c
string update_message(string lhs, string rhs, char op)
{
	if (op == '+')
		return lhs + ' ' + op + ' ' + rhs;
	else if (op == '-')
	{
		// if the right operand contains an unbounded minus sign
		if (has_unbound_operator(rhs, "-"))
			rhs = '(' + rhs + ')';
		return lhs + ' ' + op + ' ' + rhs;
	}
	else if (op == '*')
	{
		if (has_unbound_operator(lhs, "+-"))
			lhs = '(' + lhs + ')';
		// need to add paranthensis if there is unbound plus or minus sign
		if (has_unbound_operator(rhs, "+-"))
			rhs = '(' + rhs + ')';
		// need to add paranthesis if there is unbound plus or minus sign
		return lhs + ' ' + op + ' ' + rhs;
	}

	else if (op == '/')
	{
		if (has_unbound_operator(lhs, "+-"))
			lhs = '(' + lhs + ')';
		if (has_unbound_operator(rhs, "+-/"))
			rhs = '(' + rhs + ')';
		return lhs + ' ' + op + ' ' + rhs;
	}
	else
		cerr << "There is invalid operation" << endl;
}
```
Boolean function `compareDouble` is a function to check if 2 doubles are equal or not.
```c
bool compareDouble(double x, double y)
{
	int diff = x - y;
	return diff < 1e-5 && -diff < 1e-5;
}
```

### Output

![1623250116133](https://github.com/DidoFayed/PAAJAYAA_DAA_E_Quiz2/blob/main/ss/1623250116133.jpg)

![1623250181163](https://github.com/DidoFayed/PAAJAYAA_DAA_E_Quiz2/blob/main/ss/1623250181163.jpg)
