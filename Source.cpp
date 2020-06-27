#include <iostream>
using namespace std;

template<class T1, class T2>
class Tree
{
	struct Node
	{

		T1 key;
		T2 data;
		Node* left;
		Node* right;

		Node(T1 key, T2 data, Node* left = nullptr, Node* right = nullptr)
			: key(key), data(data), left(left), right(right)
		{ }
	};

	Node* root;

	void Add(T1 key, T2 data, Node*& root)
	{
		if (root == nullptr)
		{
			root = new Node(key, data);
			return;
		}

		if (key > root->key)
			Add(key, data, root->right);
		else
			Add(key, data, root->left);
	}

	void PrintKLP(Node* elem) const
	{
		if (elem != nullptr)
		{

			cout << elem->key << ":" << elem->data << " ";

			PrintKLP(elem->left);

			PrintKLP(elem->right);
		}
	}

	void PrintLKP(Node* elem) const
	{
		if (elem != nullptr)
		{

			PrintLKP(elem->left);

			cout << elem->key << ":" << elem->data << " ";

			PrintLKP(elem->right);
		}
	}

	void PrintPKL(Node* elem) const
	{
		if (elem != nullptr)
		{

			PrintPKL(elem->right);

			cout << elem->key << ":" << elem->data << " ";

			PrintPKL(elem->left);
		}
	}

	T1 Find(T1 key, Node* root) const
	{
		if (root == nullptr) return 0;

		if (key > root->key)
			Find(key, root->right);
		else if (key < root->key)
			Find(key, root->left);
		else
			return root->data;
	}

	void delete_subtree(Node* node) {
		if (!node) return;
		delete_subtree(node->left);
		delete_subtree(node->right);
		delete node;
	}

	void Copy(Node* other)
	{
		if (other != nullptr)
		{
			Add(other->key, other->data);
			Copy(other->left);
			Copy(other->right);
		}
	}

public:

	Tree() : root(nullptr) { }

	void Add(T1 key, T2 data)
	{
		Add(key, data, root);
	}

	T1 Find(T1 key) const
	{
		return Find(key, root);
	}

	void PrintKLP() const
	{
		PrintKLP(root);
	}
	void PrintLKP() const
	{
		PrintLKP(root);
	}
	void PrintPKL() const
	{

		PrintPKL(root);
	}

	void GetMin(Node* root)
	{
		if (root->left != nullptr)
		{
			return GetMin(root->left);
		}
		else return  root->key;
	}

	void GetMax()
	{
		if (root->right != nullptr)
		{
			return GetMin(root->right);
		}
		else return  root->key;
	}

	void Replace(T1 dataOld, T1 dataNew, Node* root)
	{
		if (root == nullptr) return;

		if (root->data == dataOld)
		{
			root->data = dataNew;
		}
		Replace(dataOld, dataNew, root->left);

		Replace(dataOld, dataNew, root->right);
	}
	~Tree()
	{
		delete_subtree(root);
	}

	Tree(const Tree& other)
	{
		Copy(other.root);
	}
};

int main()
{

	system("pause");
	return 0;
}