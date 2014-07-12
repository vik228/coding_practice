#include <iostream>
#include <stack>
using namespace std;
stack s1, s2;
void push_queue (int val)
{
	s1.push(val);
}
void pop_queue()
{
	if (s2.empty())
	{
		for (int i = 0; i < s1.size(); i++)
		{
			int val = s1.top();
			s2.push(val);
			s1.pop();
		}
	}
	s2.pop();
}
int main()
{
	int t;
	scanf ("%d",&t);
	int val;
	while (t--)
	{
		scanf ("%d",&val);
		push_queue(val);
	}

}
