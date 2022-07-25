#pragma once

template<class K>
//struct BinarySearchTreeNode
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;

	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}

	//const Node* Find(const K& key)
	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//一个孩子---左为空or右为空
				//两个孩子---替换法
				if (cur->_left == nullptr)
				{
					if (cur == parent->_left)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
				else if (cur->_right == nullptr)
				{
					if (cur == parent->_left)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_left = cur->_left;
					}

				}
			}
		}
		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr;
};

void TestBSTree()
{
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();

	t.Insert(16);
	t.Insert(9);

	t.InOrder();
}


void TestBSTree2()
{
	BSTree<int> t;
	int a[] = { 8,7,9,12,5,19,20,30 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}