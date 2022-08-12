#pragma once
#include<assert.h>
template<class K,class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	//������-�������ĸ߶Ȳ�
	//AVL��û�й涨�������ƽ������
	//ֻ��һ��ʵ�ֵ�ѡ�񷽱����ƽ��
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
		//1.�������������
		//2.���Ƿ�Υ��ƽ��������Υ������Ҫ����--->��ת
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

		//1.�����²���ڵ����ȵ�ƽ������
		//2.û��Υ������ͽ�����Υ������ƽ�����ת
		//��������·������
		//1.�����ĸ߶Ȳ��䣬��������
		//2.�����߶ȱ��ˣ���������ϸ���
		//3.����Υ������ֹͣ���¡���ת����


		//parent->_bf==1
		//parent���������߶ȱ仯���������£�˵���ұ߱��
		//parent->_bf==-1
		//parent���������߶ȱ仯���������£�˵����߱��
		//parent->_bf==0
		//parent���������߶Ȳ��䣬˵��ԭ����1����-1���ڱ��0��֮ǰһ�߸�һ�߰���ֻ�������˰����Ǳ�
		

		//.....
		//����ƽ������
		while (parent)//��ԶҪ���¸�
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			//�Ƿ��������
			if (parent->_bf == 0)//ֹͣ����
			{
				//���½���
				break;
			}
			else if (parent->_bf==1 || parent->_bf==-1)
			{
				//�����߶ȱ��ˣ�������������
				cur = cur->_parent;
				parent = parent->_parent;
			}

			//��תԭ��
			//1.�����������Ĺ���
			//2.������ƽ��
			//�ұ߸�--->����ת
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//-1 or 1---> 2 or -2 ����ڵ㵼�±����ߵ�һ���ָ���
				//������ƽ��--->��Ҫ��ת
				if (parent->_bf == 2 && cur->_bf == 1)//����
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)//�ҵ���
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)//�ҵ���
				{
					RotateLR(parent);
				}

				break;
			}
			else
			{
				//����֮ǰAVL�ʹ��ڲ�ƽ����������|ƽ������|>=2�Ľڵ�
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

		//����ƽ������
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
			subLR->_parent = parent;//subLR����Ϊ��

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
			//subLR->_bf��תǰ��������
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