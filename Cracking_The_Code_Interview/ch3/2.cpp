#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define MAX 12
int Stack[MAX];
int min_arr[MAX];
vector <int> v1_min;
int top = -1;
int idx_min = -1;
void push (int val)
{
	if (top == -1)
	{
		top++;
		Stack[top] = val;
		min_arr[++idx_min] = val;
	}
	else
	{
		int val1 = Stack[top];
		if (val < val1)
			min_arr[++idx_min] = val;
		top++;
		Stack[top] = val;
	}

}
void pop ()
{
	if (top == -1)
		cout << "Stack is empty\n";
	else
	{
		int val = Stack[top];
		if (val == min_arr[idx_min])
		{
			idx_min--;
			top--;
		}
	}
}
int min_val ()
{
	return min_arr[idx_min];
}
int top_val ()
{
	return Stack[top];
}
int main()
{
	int T;
	cin >> T;
	int val;
	while (T--)
	{
		cin >> val;
		push(val);
	}
	cout << top_val() << "\n";
	cout << min_val() << "\n";
	pop();
	cout << top_val() << "\n";
	cout << min_val() << "\n";
}
