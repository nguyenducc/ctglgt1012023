#include<iostream>
#include<string>
using namespace std;

struct Node
{
	int sbd; // So bao danh
	string hoTen; // Ho ten sinh vien
	Node* left; // Con tro toi nut con trai
	Node* right; // Con tro toi nutcon phai
	// Ham tao.
	Node(int s, string h, Node * l=NULL, Node * r=NULL) 
	{ 
		sbd = s;
		hoTen = h;
		left = l;
		right = r;
	}
};
// Lop cay nhi phan tim kiem.
class BSTree
{
public:
	// Ham tao (ban dau cay rong).
	BSTree() 
	{ 
		root = NULL;
	}
	// Ham huy (xoa het cac nut tren cay).
	~BSTree() 
	{ 
		makeEmpty(root);
	}
	// Kiem tra cay co ronghay khong.
	bool isEmpty() // 1 cây rỗng, 0 cây không rỗng
	{ 
		return root == NULL;
	}
	// Xoa het cac nut tren cay.
	void makeEmpty()
	{
		makeEmpty(root);
	}
	// Chen mot sinh vien moi vao cay.
	void insert(int sbd, string hoTen) 
	{ 
		insert(sbd, hoTen, root);
	}
	// Tim sinh vien theo so bao danh.
	Node * search(int sbd) 
	{ 
		search(sbd, root);
	}
	// Cac ham duyet cay viet them o day...
	private:
		Node * root; 
	// Con tro toi nut goc cua cay
	// Xoa rong cay (viet theo kieu de quy).
	void makeEmpty(Node * & t) 
	{ 
		if (t == NULL) {
			return;
		}
		else {
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
	}
	// Chen mot sinh vien moi vao cay (viet theo kieu de quy).
	void insert(int sbd, string hoTen, Node * & t) 
	{ 
		if (t == NULL)
		{
			t = new Node (sbd,"hoTen");
			return;
		}
		if (t->sbd > sbd)
		{
			insert(sbd, hoTen, t->left);
		}
			
		if (t->sbd < sbd)
		{
			insert(sbd, hoTen, t->right);
		}
			
	}
	// Tim sinh vien theo so bao danh (viet theo kieu de quy)
	Node * search(int sbd, Node * t)
	{ 
		if (t == NULL) 
		{
			return NULL;
		}
		if (t->sbd == sbd) 
		{
			return t;
		}
		else if (sbd> t->sbd) 
		{
			return search(sbd, t->right);
		}
		else if (sbd < t->sbd) 
		{
			return search(sbd, t->left);
		}
	}
};
void Duyettruoc(Node* t) 
{
	if (t != NULL) 
	{
		cout << t->sbd << " "<< " : "<<t->hoTen;
		Duyettruoc(t->left);
		Duyettruoc(t->right);
	}
}
void Duyetgiua(Node* t) 
{
	if (t != NULL) 
	{
		Duyetgiua(t->left);
		cout << t->sbd << " " << " : " << t->hoTen;
		Duyetgiua(t->right);
	}
}
void Duyetsau(Node* t) 
{
	if (t != NULL) 
	{
		Duyetsau(t->left);
		Duyetsau(t->right);
		cout << t->sbd << " " << " : " << t->hoTen;
	}
}
int main()
{
	BSTree bst;// Chen mot so sinh vien moi vao cay.
	bst.insert(5, "Tuan");
	bst.insert(6, "Lan");
	bst.insert(3, "Cong");
	bst.insert(8, "Huong");
	bst.insert(7, "Binh");
	bst.insert(4, "Hai");
	bst.insert(2, "Son");
	// Tim hai sinh vien co so bao danh 4 va 9.
	Node * n1 = bst.search(4);
	Node * n2 = bst.search(9);
	// In ket qua tim kiem
	if (n1 != NULL)cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl;
	if (n2 == NULL)cout << "Khong tim thay sinh vien voi SBD=9" << endl;
	// Lam rong cay.
	bst.makeEmpty(); 
	if (bst.isEmpty())cout << "Cay da bi xoa rong" << endl; 
	return 0;
}