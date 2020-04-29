#include<iostream> 
using namespace std;
void F1(double* mas, int N)
{
	int a;
	double c;
	int* mas1 = new int[N];
	double* mas2 = new double[N];
	for (int i = 0; i < N; i++)
	{
		c = mas[i];
		a = (int)mas[i];
		c = c - a;
		mas1[i] = a;
		mas2[i] = c;
	}
	for (int i = 0; i < N; i++) {
		cout << "Целая часть:" << mas1[i] << endl;
	}
	for (int i = 0; i < N; i++) {
		cout << "Дробная часть:" << mas2[i] << endl;
	}
}

int main()
{
	int N;
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов массива:" << endl;
	cin >> N;
	double* mas = new double[N];
	cout << "Введите элементы массива" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> mas[i];
	}
	F1(mas, N);
	delete[] mas;
	system("pause");
	return 0;
}