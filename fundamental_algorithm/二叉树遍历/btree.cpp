#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;

struct node{
	int value;
	struct node* left;
	struct node* right;
	node(int v, struct node* l, struct node* r){
		value = v;
		left = l;
		right = r;
	};
};

class BTree{
	private:
		struct node* root;

		void visit(struct node* npt){
			fflush(stdout);
			cout << npt->value << "\t";
		}

		bool has_key(int v){
			struct node *cur = root, *parent=NULL;
			while(cur){
				if(cur->value==v) return true;
				else{
					parent = cur;
					if(cur->value>v) cur=cur->left;
					else cur=cur->right;
				}
			}
			/** if BTree not empty **/
			if(parent) {
				cur=new node(v,NULL,NULL);
				if(v < parent->value) parent->left=cur;
				else parent->right=cur;
		//		cout << parent->value << "add\n";
				return false;
			}
			/** if BTree empty **/
			else {root=new node(v,NULL,NULL);return false;}
		}
	public:
		BTree(){
			ifstream fin("in.txt");
			int v;
			root = NULL;
			while(!fin.eof()){
				fin >> v;
				cout << v << endl;
				has_key(v);
			}
		}
		void preoder_traverse(){
			if(!root) {cout<<"empty tree\n";return;}
			vector <node*> stack;
			node* cur=root;
			stack.push_back(cur);
			while(stack.size()>0){
				/** visit the node **/
				cur = stack.back();
				stack.pop_back();
				visit(cur);
				if(cur->right!=NULL) stack.push_back(cur->right);
				if(cur->left!=NULL) stack.push_back(cur->left);
			}
			cout << endl;
		}
		void inOrder_traverse(){
			if(!root) {cout<<"empty tree\n";return;}
			node* cur=root;
			vector <node*> stack;
			do{
				while(cur!=NULL){
					stack.push_back(cur);
					cur = cur->left;
				}
				if(stack.size()>0){
					cur = stack.back();stack.pop_back();
					visit(cur);
					cur = cur-> right;
				}
			}while(cur!=NULL||stack.size()>0);
			cout << endl;
		}

		void postOrder(){
			if(!root) {cout <<"empty tree\n";return;}
			node *cur = root,*pre=NULL;
			vector<node*> stack;
			stack.push_back(cur);
			while(stack.size()>0){
				cur = stack.back();
				/** can we visit this node? **/
				if((cur->right==NULL&&cur->left==NULL)
						||(pre!=NULL&&(pre==cur->right||pre==cur->left))){
					visit(cur);
					stack.pop_back();
					pre = cur;
				}
				/** deal with the node which is not allowed to visit **/
				else{
					if(cur->right!=NULL) stack.push_back(cur->right);
					if(cur->left!=NULL) stack.push_back(cur->left);
				}
			}
			cout << endl;
		}
};

int main(){
	BTree* bt= new BTree();
	int n;
	do{
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "0.exit\n1.preoder_nonRecursive\n2.midorder_nonRecursive\n"
			<<"3.postOrder_nonRecursive\n";
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "ENTER YOUR CHOICE:";
		scanf("%d",&n);
		switch(n){
			case 0: return 0;
			case 1: {bt->preoder_traverse();break;}
			case 2: {bt->inOrder_traverse();break;}
			case 3: {bt->postOrder();break;}
		}
	}while(n);
	return 0;
}
