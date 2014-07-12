#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int findCompressedSize (char* s)
{
	int size = 0;
	for (int i = 0; i < strlen (s);)
	{
		size++;
		char last = s[i];
		while (s[i] == last)
		{
			i++;
		}
	}
	return 2*size;
}
char* count_chars (char* s)
{
	int j = 0;
	int size = findCompressedSize(s);
	if (size > strlen (s))
		return s;
	char* ret_val = new char[size + 1];
	for (int i = 0; i < strlen(s);)
	{
		int cnt = 1;
		ret_val[j] = s[i];
		i++;
		while (s[i] == ret_val[j])
		{
			cnt++;
			i++;
		}
		j++;
		ret_val[j++] = cnt + '0';
	}
	return ret_val;
}
int main()
{
	char s[100];
	char* ret_val;
	gets (s);
	ret_val = count_chars (s);
	cout << ret_val << "\n";
}
