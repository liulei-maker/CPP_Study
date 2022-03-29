#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;


int KMPSearch(const string str1, const string str2)
{
	const int len1 = str1.length();
	const int len2 = str2.length();
	
	int* next = new int[len2]();

	int i = 0;
	int j = -1;
	next[i] = -1;
	while (i < len2)
	{
		if (j == -1 || str2[i] == str2[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
	i = 0;
	j = 0;
	while (i < len1 && j < len2)
	{
		if (j == -1 || str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == len2)
		return i - j;
	else
		return -1;
}


int main()
{
	
	string str1 = "sdgadwasadagds";
	string str2 = "ada";
	cout<<KMPSearch(str1, str2);

	return 0;
}

