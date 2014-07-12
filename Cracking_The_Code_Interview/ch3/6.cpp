#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack <int> s1, s2;
void sortStack ()
{
	while (!s1.empty())
	{
		//cout << "hii\n";
		if (s2.empty())
		{
			//cout << "Pushing " << s1.top() << " into stack " << " s2 " << "\n";
			s2.push (s1.top());
			s1.pop();
		}
		else
		{
			//cout << "Pushing " << s1.top() << " into stack " << " s2 " << "\n";
			int v = s1.top();
			s1.pop();
			int k = 0;
			
			while (s2.top() < v)
			{
				//cout << "comparing " << s2.top() << " with " << v << "\n"; 
				int a1 = s2.top();
				s1.push(a1);
				k++;
				s2.pop();
			}
			s2.push(v);
			while (k--)
			{
				s2.push (s1.top());
				s1.pop();
			}
		}
	}
	
}
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int val;
		scanf ("%d",&val);
		s1.push(val);


	}
	//cout << "hii\n";
	sortStack ();
	while (!s2.empty())
	{
		//cout << "Pushing " << s2.top() << "on to the satck s1 " << "\n";
		s1.push (s2.top());
		s2.pop();
	}
	cout << s1.top() << "\n";
	cout << "\n";
}
