#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long a[100000];
void preCompute ()
{
  	for (int i = 0; i < 100000; i++)
    	{
      		a[i] = i*i;
    	}	
  
}
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  	int T;
  	preCompute ();
  	cin >> T;
  	while (T--)
    	{
      		long long A, B;
      		cin >> A >> B;
		cout << A << " " << B << "\n";
		int low, hi;
      		low = lower_bound (a, a+100000, A) - a;
      		hi =  upper_bound (a,a+100000, B) - a;
      		cout << low << " " << hi << "\n";
      		cout << hi-low << "\n";
      	
    	}
	return 0;
}

