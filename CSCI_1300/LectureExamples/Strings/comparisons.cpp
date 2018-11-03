#include <iostream>
#include <string>
using namespace std;

// strings are compared character by character

int main()
{
	string str1, str2;
	str1 = "My name is Inigo Montoya.";
	str2 = "My name is Montoya Inigo.";
	
	if (str1 == str2)
	{
		cout << "Same name" << endl;
	}
	if (str1 < str2)
	{
		cout << "Larger" << endl;
	}
	
	return 0;
}