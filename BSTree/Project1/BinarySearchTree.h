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
	//强制编译器自己生成
	BSTree() = default;

	BSTree(const BSTree<K>& t)
	{
		_root = CopyTree(t._root);
	}

	BSTree<K>& operator=(BSTree<K> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~BSTree()
	{

	}

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
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
			parent->_left = cur;
	}


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
				return true;
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
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//一个孩子--左为空 or 右为空
				//两个孩子--替换法
				if (cur->_left==nullptr)
				{
					if (parent == nullptr)
						_root = cur->_right;
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;
					}
				}
					
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}
				}
				//两个孩子
				else
				{
					Node* minParent = cur;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minParent = minRight;
						minRight = minRight->_left;
					}
					//swap(minRight-> - key, cur->_key);
					cur->_key = minRight->_key;
					//递归过程导致找不到指定数据
					//因为交换后破坏了二叉搜索树的结构
					//return Erase(key);
					if (minParent->_left == minRight)
					{
						minParent->_left = minRight->_right;
					}
					else
						minParent->_right = minRight->_right;
					delete minRight;
				}
				return true;
			}
		}
		return false;
	}



	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	/////////////////////////////////////////////////
	bool FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	bool InsertR(const K& key)
	{
		return _Insert(_root, key);
	}

private:
	bool _Insert(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key < key)
			return _Insert(root->_right);
		else if (root->_key > key)
			retrun _Insert(root->_left);
		else
			return false;
	}

	bool _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
			return false;
		if (root->_key < key)
			return _FindR(root->_right);
		else if (root->_key > key)
			retrun _FindR(root->_left);
		else
			return true;
	}
	Node* CopyTree(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* copyNode = new Node(root->_key);;
		copyNode->_left = CopyTree(root->_left);
		copyNode->_right = CopyTree(root->_right);
		return copyNode;
	}

	void DestoryTree(Node* root)
	{
		if (root == nullptr)
			return;
		DestoryTree(root->_left);
		DestoryTree(root->_right);
		delete root;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	Node* _root = nullptr;
};

void BSTreeTest1()
{
	BSTree<int> bt;
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	for (auto e : a)
	{
		bt.Insert(e);
	}
	bt.InOrder();
	bt.Erase(8);
	bt.InOrder();

}

void BSTreeTest2()
{
	BSTree<int> bt;
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	for (auto e : a)
	{
		bt.Insert(e);
	}
	bt.InOrder();
	BSTree<int> bt1(bt);
	bt1.InOrder();
	BSTree<int> bt2=bt1;
	bt1.InOrder();
}