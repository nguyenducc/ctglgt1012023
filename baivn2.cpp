//Xây dựng một template class BinaryTree cho phép chứa các phần tửcó kiểu khác nhau của cây nhịphân.
//Đồng thời nó có cài đặt các thao tác sau : 
//–InitBTree() : Khởi tạo một cây rỗng
//–InsertParent(type x, PNode P) : bổsung phần tửx trở thành nút cha của nút P trong cây
//–InsertLeftChild(type x, PNode P) : bổsung phần tửx trởt hành nút con trái của nút P trong cây
//–InsertRightChild(type x, PNode P) : bổsung phần tửx trở thành nút con phải của nút P trong cây
//–PNode FindNode(type x) : tìm một nút có giá trịbằng x trong cây, hàm trả về con trỏ trỏvào nút tìm thấy, trái lại trả về NULL
//–DeleteCurrentNode(PNode P) : xóa nút hiện trỏ bởi P trong cây 
//–DeleteLeftChild(PNode P) : xóa nút con trái của P
//–DeleteRightChild(PNode P) : xóa nút con phải của P
//–GetSize() : trảvềkích thước của cây
#include <iostream>
using namespace std;
template <class T>
class BinaryTree
{
	struct node 
	{
		T value;
		struct node* right;
		struct node* left;
	};

public:
	BinaryTree();
	~BinaryTree();
	void add(T val);
	int size();
	bool FindNode(T val);

private:
	struct node* root;
	int GetSize;
	void add(struct node** node, T val);
	bool FindNode(struct node* node, T val);
	node* InitTree();
	void InsertParent(T x, struct node* P);
	void InsertLeftChild(T x, struct node* P);
	void InsertRightChild(T x, struct node* P);
	void deleteTree(struct node* node);
	void DeleteCurrentNode(struct node* node);
	void DeleteLeftChild(struct node* node);
	void DeleteRightChild(struct node* node);
};

//template <class T>
//BinaryTree<T>::InitTree()
//{
//	
//	return p;
//}

template <class T>
BinaryTree<T>::BinaryTree() 
{
	this->root = NULL;
	this->GetSize = 0;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
	deleteTree(this->root);
}

template <class T>
int BinaryTree<T>::size() 
{
	return this->GetSize;
}

template <class T>
void BinaryTree<T>::add(T val) 
{
	add(&(this->root), val);
}

template <class T>
void BinaryTree<T>::add(struct node** node, T val) 
{
	if (*node == NULL) 
	{
		struct node* tmp = new struct node;
		tmp->value = val;
		tmp->left = NULL;
		tmp->right = NULL;
		*node = tmp;
		this->GetSize++;
	}
	else 
	{
		if (val > (*node)->value)
		{
			add(&(*node)->right, val);
		}
		else 
		{
			add(&(*node)->left, val);
		}
	}
}

template <class T>
void BinaryTree<T>::deleteTree(struct node* node) 
{
	if (node != NULL) 
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template <class T>
bool BinaryTree<T>::FindNode(T val) 
{
	return FindNode(this->root, val);
}

template <class T>
bool BinaryTree<T>::FindNode(struct node* node, T val) 
{
	if (node == NULL) 
	{
		return false;
	}
	else 
	{
		if (val == node->value) 
		{
			return true;
		}

		if (val > node->value) 
		{
			return FindNode(node->right, val);
		}
		else 
		{
			return FindNode(node->left, val);
		}
	}

}

int main() {

	BinaryTree<int> tree1;
	tree1.add(5);
	tree1.add(4);
	tree1.add(7);
	tree1.add(10);
	tree1.add(1);
	tree1.add(2);
	std::cout << "tree1 size: " << tree1.size() << std::endl;
	BinaryTree<char> tree2;
	tree2.add('z');
	tree2.add('0');
	tree2.add('9');
	tree2.add('a');
	tree2.add('A');
	tree2.add('Z');
	std::cout << "Contains 9? : " << ((tree2.FindNode('9')) ? "true" : "false") << std::endl;
	std::cout << "Tree size: " << tree2.size() << std::endl;
}