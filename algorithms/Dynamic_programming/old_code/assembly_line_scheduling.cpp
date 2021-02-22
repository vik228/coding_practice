#include <iostream>
#include <cstdio>
using namespace std;
void recursive_print_stations(int l[][7],int i,int j)
{
	if (j == 0)
		return;
	recursive_print_stations(l,l[i][j],j-1);
	cout << "Line " << i << ",station " << j << "\n";
}
void print_stations(int l[][7],int n,int l_final)
{
	int i = l_final;
	cout << "line " << i << ",station " << n << "\n";
	for (int j = n; j >= 2; j--)
	{
		i = l[i][j];
		cout << "line " << i << ",station " << j - 1 << "\n";
	}
}
int main()
{
	int n;
	cout << "Enter the number of stations \n";
	cin >> n;
	int e1,e2,x1,x2,f_final,l_final;
	cout << "Enter the start times and End times \n";
	cin >> e1 >> e2 >> x1 >> x2;
	int S1[n], S2[n],T1[n-1],T2[n-1],l[3][7],f1[n],f2[n];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			l[i][j] = 0;
		}
	}
	cout << "Enter the station times of row S1\n";
	for (int i = 0; i < n; i++)
	{
		cin >> S1[i];
	}
	cout << "Enter the station times of row S2\n";
	for (int i = 0; i < n; i++)
	{
		cin >> S2[i];
	}
	cout << "Enter the transaction times from row S1 \n";
	for (int i = 0; i < n-1; i++)
	{
		cin >> T1[i];
	}
	cout << "Enter the transaction times from row S2 \n";
	for (int i = 0; i < n-1; i++)
	{
		cin >> T2[i];
	}
	f1[0] = S1[0] + e1;
	f2[0] = S2[0] + e2;
	for (int j = 1; j < n; j++)
	{
		if (f1[j - 1] + S1[j] <= f2[j - 1] + T2[j - 1] + S1[j])
		{
			f1[j] = f1[j - 1] + S1[j];
			l[1][j + 1] = 1;
		}
		else
		{
			f1[j] = f2[j - 1] + T2[j - 1] + S1[j];
			l[1][j + 1] = 2;
		}
		if (f2[j - 1] + S2[j] <= f1[j - 1] + T1[j - 1] + S2[j])
		{
			f2[j] = f2[j - 1] + S2[j];
			l[2][j + 1] = 2;
		}
		else
		{
			f2[j] = f1[j - 1] + T1[j - 1] + S2[j];
			l[2][j + 1] = 1;
		}
	}
	if (f1[n - 1] + x1 <= f2[n - 1] + x2)
	{
		f_final = f1[n - 1] + x1;
		l_final = 1;
	}
	else
	{
		f_final = f1[n - 1] + x2;
		l_final = 2;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "f1[i] " << f1[i] << "\n";
	}
	for (int i = 0; i < n; i++)
	{
		cout << "f2[i] " << f2[i] << "\n";
	}
	for (int i = 1; i < 3; i++)
	{
		for (int j = 2; j < n+1; j++)
		{	
			cout << l[i][j] << "\t";
		}
		cout << "\n";
	}
	print_stations(l,n,l_final);
	recursive_print_stations(l,l_final,n);
	//print_inc_stations(f1,f2,n);



	return 0;
}
