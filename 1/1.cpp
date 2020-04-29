#include <iostream>
using namespace std;
struct TreeElement
{
	int value;
	TreeElement* right;
	TreeElement* left;
	TreeElement()
	{
		value = -1;
		right = NULL;
		left = NULL;
	}
};
struct List
{
	int value;
	List* next;
	List()
	{
		value = -1;
		next = NULL;
	}
};
inline void Input(TreeElement*& el, int v);
inline void Output(TreeElement* el);
inline void Detach(TreeElement* root, TreeElement* el);
inline void Remove(TreeElement* el);
inline TreeElement* Find(TreeElement* el, int v);
void Tree_to_List(List*& first, TreeElement* el, List*& f);
void OutputList(List* f);

int main()
{
	setlocale(LC_ALL, "rus");
	int n = 0, z = 0;
	TreeElement* root = NULL;
	cout << "Введите количество элементов дерева:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент дерева:" << endl;
		cin >> z;
		Input(root, z);
	}
	Output(root);
	cout << endl;
	cout << "Введите элемент, который нужно удалить:" << endl;
	cin >> z;
	TreeElement* e = Find(root, z);
	Detach(root, e);
	Remove(e);
	cout << "Дерево после удаления:" << endl;
	Output(root);
	List* f = NULL;
	List* first = NULL;
	cout <<endl<< "Преобразование в список:" << endl;
	Tree_to_List(first, root, f);
	OutputList(first);
	system("pause");
}
inline void Input(TreeElement*& el, int v)
{
	if (el == NULL)
	{
		el = new TreeElement();
		el->value = v;
	}
	else if (el->value > v)
	{
		Input(el->left, v);
	}
	else if (el->value < v)
	{
		Input(el->right, v);
	}
}
inline void Output(TreeElement* el)
{
	if (el != NULL)
	{
		Output(el->left);
		cout << el->value << " ";
		Output(el->right);
	}
}
inline void Detach(TreeElement* root, TreeElement* el)
{
	if (root == NULL || el == NULL) { return; }
	else if (root->left == el) { root->left = NULL; }
	else if (root->right == el) { root->right = NULL; }
	{

		Detach(root->left, el);
		Detach(root->right, el);
	}
}
inline void Remove(TreeElement* el)
{
	if (el != NULL)
	{
		Remove(el->left);
		Remove(el->right);
		delete el;
	}
}
inline TreeElement* Find(TreeElement* el, int v)
{
	TreeElement* result = NULL;
	if (el == NULL) { result = NULL; }
	else if (el->value == v) { result = el; }
	else
	{
		result = Find(el->left, v);
		if (result == NULL) { result = Find(el->right, v); }
	}
	return result;
}
void Tree_to_List(List*& first, TreeElement* el, List*& f)
{
	if (el)
	{
		Tree_to_List(first, el->left, f);
		List* p1 = new List();
		p1->value = el->value;
		if (f == NULL)
		{
			first = p1;
			f = p1;
		}
		else
		{
			f->next = p1;
			f = p1;
		}
		Tree_to_List(first, el->right, f);
	}
}

void OutputList(List* f) {
	while (f != NULL) {
		cout << f->value << " ";
		f = f->next;
	}
	cout << endl;
}
