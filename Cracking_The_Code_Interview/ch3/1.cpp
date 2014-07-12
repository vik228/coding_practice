#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 3
int stacks[3*MAX];
int stack_num[3];
void push (int stackNum, int val)
{
	if (stack_num[stackNum]+1 < MAX)
	{
		stack_num[stackNum] += 1;
		int idx = stackNum*MAX + stack_num[stackNum];
		stacks[idx] = val;
	}
	else
		cout << "Stack is full\n";
}
void pop (int stackNum)
{
	if (stack_num[stackNum] == -1)
		cout << "Stack is empty\n";
	else
	{
		int idx = stackNum*MAX + stack_num[stackNum];
		int t = stacks[idx];
		stacks[idx] = 0;
		stack_num[stackNum] -= 1;
	}
}
int top(int stackNum)
{
	int idx = stackNum*MAX + stack_num[stackNum];
	return stacks[idx];

}
int main()
{
	for (int i = 0; i < 3; i++)
		stack_num[i] = -1;
	push (0, 1);
	push (0, 2);
	push (1, 2);
	push (2, 2);
	for (int i = 0; i < 9; i++)
	{
		cout << stacks[i] << "\t";
	}
	cout << "\n";
	cout << "Elements after popping from the first stack\n";
	pop (0);
	pop (0);
	for (int i = 0; i < 9; i++)
		cout << stacks[i] << "\t";
	cout << "\n";
}


