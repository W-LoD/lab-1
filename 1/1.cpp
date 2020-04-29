#include<iostream> 
using namespace std;

struct list
{
	float value;
	list* next;
	list()
	{
		value = 0;
		next = NULL;
	}
};
void F1(list* p, int i, int n);
void F2(list* p, int i, int n);
int main()
{
	int n;
	float z;
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов списка: " << endl;
	cin >> n;
	cout << "Введите элементы списка: " << endl;
	list* first = new list();
	list* p = first;
	int i = 0;
	while (i < n)
	{
		cin >> z;
		p->value = z;
		//cout<<first->value<<endl;
		if (i != n)
		{
			p->next = new list();
			p = p->next;
		}
		i++;
	}
	i = 0;
	F1(first, i, n);
	i = 0;
	F2(first, i, n);
	system("pause");
	return 0;
}
void F1(list* p, int i, int n)
{
	list* do_z = new list();
	int b;
	float c;
	while (i < n)
	{
		b = (int)p->value;
		c = p->value;
		c -= b;
		do_z->value = b;
		cout << do_z->value << endl;
		p = p->next;
		if (i != n - 1)
		{
			do_z->next = new list();
			do_z = do_z->next;
		}
		i++;
	}
}
void F2(list* p, int i, int n) {
	list* po_z = new list();
	int b;
	float c;
	while (i < n)
	{
		b = (int)p->value;
		c = p->value;
		c -= b;
		po_z->value = c;
		cout << po_z->value << endl;
		p = p->next;
		if (i != n - 1)
		{
			po_z->next = new list();
			po_z = po_z->next;
		}
		i++;
	}
}