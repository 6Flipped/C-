#pragma once
#include<assert.h>
template<class K,class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	//右子树-左子树的高度差
	//AVL树没有规定必须设计平衡因子
	//只是一个实现的选择方便控制平衡
	int _bf;//balance factor
	AVLTreeNode(const pair<K,V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
	
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//1.搜索树规则插入
		//2.看是否违反平衡规则，如果违反就需要处理--->旋转
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;

		//1.更新新插入节点祖先的平衡因子
		//2.没有违反规则就结束，违反规则不平衡就旋转
		//沿着祖先路径更新
		//1.子树的高度不变，则更新完成
		//2.子树高度变了，则继续往上更新
		//3.子树违反规则，停止更新。旋转子树


		//parent->_bf==1
		//parent所在子树高度变化，继续更新，说明右边变高
		//parent->_bf==-1
		//parent所在子树高度变化，继续更新，说明左边变高
		//parent->_bf==0
		//parent所在子树高度不变，说明原来是1或者-1现在变成0，之前一边高一边矮，只有填上了矮的那边
		

		//.....
		//更新平衡因子
		while (parent)//最远要更新跟
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			//是否继续更新
			if (parent->_bf == 0)//停止更新
			{
				//更新结束
				break;
			}
			else if (parent->_bf==1 || parent->_bf==-1)
			{
				//子树高度变了，继续更新祖先
				cur = cur->_parent;
				parent = parent->_parent;
			}

			//旋转原则：
			//1.保持搜索树的规则
			//2.子树变平衡
			//右边高--->左旋转
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//-1 or 1---> 2 or -2 插入节点导致本来高的一边又高了
				//子树不平衡--->需要旋转
				if (parent->_bf == 2 && cur->_bf == 1)//左单旋
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)//右单旋
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)//右单旋
				{
					RotateLR(parent);
				}

				break;
			}
			else
			{
				//插入之前AVL就存在不平衡子树，即|平衡因子|>=2的节点
				assert(false);
			}

		}
		
		return true;
	}


private:
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL; 
		if(subRL)
			subRL->_parent = parent;

		Node* ppNode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parent == ppNode-> _left)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = subR;
			}
			subR->_parent = ppNode;
		}

		//更新平衡因子
		parent->_bf = 0;
		subR->_bf = 0;

	}

	void RotateR(Node* parent)
	{
		/*Node* pparent = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subLR->_parent = parent;
		parent->_left = subLR;

		subL->_right = parent;
		parent->_parent = subL;
		subL->_parent = pparent;*/

		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if(subLR)
			subLR->_parent = parent;//subLR可能为空

		Node* pparent = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;
		
		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (pparent ->_left == parent)
				pparent->_left = subL;
			if (pparent->_right == parent)
				pparent->_right = subL;
			subL->_parent = pparent;
		}
		subL->_bf = parent->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 0)
		{
			parent->_bf = subL->_bf = subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			//subLR->_bf旋转前就有问题
			assert(false);
		}
	}

private:
	Node* _root=nullptr;
};

void test_AVLTree1()
{
	int a[] = { 1,2,3,4,5,6,7,8 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
}