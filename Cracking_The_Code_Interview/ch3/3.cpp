#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int top = -1;
vector <int> stack[12];
#define CAPACITY 5
int individual_tops[12];
void push (int val)
{
	if (top > 12*5)
	{
		cout << "Stack is full\n";
		return;
	}
	top += 1;
	int i = (top)/5;
	individual_tops[i] += 1;
	stack[i].push_back (val);
}
void pop()
{
	if (top == -1)
	{
		cout << "Stack is empty\n";
		return;
	}
	top--;
}
void pop(int idx)
{
	if (individual_tops[idx] == -1)
		cout << "Stack is empty\n";
	int top_row = top/5;
	if (top_row == idx)
	{
		top -= 1;
		individual_tops[idx] -= 1;
	}
	
}
int top_val()
{
	//cout << top << "\n";
	int i = top/5;
	int j = top%5;
	//cout << i << " " << j << "\n";
	int t = stack[i][j];
	//cout << t << "\n";
	return t;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int val;
		scanf ("%d",&val);
		push(val);
	}
	cout << top_val() << "\n";
	pop();
	cout << top_val() << "\n";
	pop();
	cout << top_val() << "\n";
}

