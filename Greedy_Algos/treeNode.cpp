#include<iostream>
using namespace std;
template <class Object,class T>
class TreeNode
{
	private:
		Object* object;
		T* obj;
		TreeNode* left;
		TreeNode* right;
		Object height;
	public:
		TreeNode()
		{
			this->obj = NULL;
			this->object=NULL;
			this->left=this->right=NULL;
		}
		TreeNode(Object* object,T* obj)
		{
			this->object=object;
			this->obj = obj;
			this->left=this->right=NULL;
		}
		Object* getInfo()
		{
			return this->object;
		}
		void setInfo(Object* object,T* obj)
		{
			this->object=object;
			this->obj = obj;
		}
		TreeNode* getLeft()
		{
			return this->left;
		}
		TreeNode* getRight()
		{
			return this->right;
		}
		void setRight(TreeNode* rightNode)
		{
			this->right=rightNode;
		}
		void setLeft(TreeNode* leftNode)
		{
			this->left=leftNode;
		}
		int isLeaf()
		{
			if(this->left==NULL && this->right==NULL)
				return 1;
			else
				return 0;
		}
		void setHeight(Object h)
		{
			height=h;
		}
		Object getHeight()
		{
			return height;
		}
};
