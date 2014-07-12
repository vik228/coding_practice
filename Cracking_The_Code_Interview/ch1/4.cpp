#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
using namespace std;
char* replace_spaces (char* s)
{
	int len = strlen (s);
	//cout << len << "\n";
	int spc_count = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
			spc_count++;
	}
	int new_length = len + 3*spc_count;
	char* a = new char[new_length];
	//cout << strlen(a) << "\n";
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			a[j] = '%';
			a[j+1] = '2';
			a[j + 2] = '0';
			j = j + 3;
		}
		else
		{
			//cout << j << ":" << i << "\n";
			a[j] = s[i];
			j++;
		}
	}
	//cout << strlen (a) << "\n";
	return a;
}
int main()
{
	char input[100];
	gets (input);
	char* out;
	out = replace_spaces (input);
	printf ("%s\n",out);
	return 0;

}
