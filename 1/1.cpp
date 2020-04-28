#include <math.h> 
#include<iostream> 
using namespace std;
float F1(float x)
{
	float result = 0;
	if (x >= 0)
	{
		result = 5 * x + 7;
	}
	else
	{
		result = 1 / x;
	}
	return result;
}
void F2(float& x)
{
	x = F1(x);
}
int main()
{
	for (float i = -5; i < 3; i++)
	{
		float f = F1(i);
		cout « "i=" « i « ";F1(i)=" « f « endl;
	}
	cout « endl;
	for (float i = -5; i < 3; i++)
	{
		cout « "i=" « i « ",";
		F2(i);
		cout « "F2=" « i «endl;
	}
	system("pause");
	return 0;
}
