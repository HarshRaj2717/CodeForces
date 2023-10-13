// Learnt from : https://youtu.be/B31LgI4Y4DQ?si=Yk2m8YuHZHYJHTph&t=18648
// Notes available in NB also
#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data = 0;
	Node *left = NULL;
	Node *right = NULL;
} *root;

Node *createNewNode(int data)
{
	Node *created_node = new Node;
	created_node->data = data;
	return created_node;
}

void inserter(int data, Node **ptr = &root)
{
	if (!root)
	{
		root = createNewNode(data);
		ptr = &root;
		return;
	}
	if (!(*ptr))
	{
		*ptr = createNewNode(data);
		return;
	}

	if ((*ptr)->data > data)
	{
		if ((*ptr)->left)
			return inserter(data, &((*ptr)->left));
		else
		{
			Node *new_node = createNewNode(data);
			(*ptr)->left = new_node;
			return;
		}
	}
	else
	{
		if ((*ptr)->right)
			return inserter(data, &((*ptr)->right));
		else
		{
			Node *new_node = createNewNode(data);
			(*ptr)->right = new_node;
			return;
		}
	}
}

void searcher(int data, Node **ptr = &root)
{
	if (!(*ptr))
	{
		cout << "Node not found" << endl;
		return;
	}

	if ((*ptr)->data == data)
	{
		cout << "Node found" << endl;
		return;
	}
	else if ((*ptr)->data > data)
		return searcher(data, &((*ptr)->left));
	else
		return searcher(data, &((*ptr)->right));
}

int findMin(Node **ptr = &root)
{
	assert(root != NULL); // Check if tree isn't empty.

	if (!((*ptr)->left))
		return (*ptr)->data;
	return findMin(&((*ptr)->left));
}

int findMax(Node **ptr = &root)
{
	assert(root != NULL); // Check if tree isn't empty.
	if (!((*ptr)->right))
		return (*ptr)->data;
	return findMin(&((*ptr)->right));
}

int findHeightOfTree(Node **ptr = &root)
{
	// Height of tree is the length of longest path from root to a leaf node
	// For empty tree, height = -1
	// For a tree with only one (root) node, height = 0
	if (!(*ptr))
		return -1;
	return 1 + max(findHeightOfTree(&((*ptr)->left)), findHeightOfTree(&((*ptr)->right)));
}

void levelOrderTraversal(queue<Node **> &cur_nodes, Node **ptr = &root)
{
	if (!(*ptr))
		return;
	if (cur_nodes.empty())
	{
		// starting case
		cur_nodes.push(ptr);
	}
	Node **cur = cur_nodes.front();
	cout << (*cur)->data << ' ';
	cur_nodes.pop();
	if ((*cur)->left)
		cur_nodes.push(&((*cur)->left));
	if ((*cur)->right)
		cur_nodes.push(&((*cur)->right));
	if (!cur_nodes.empty())
		levelOrderTraversal(cur_nodes, cur_nodes.front());
}

void preOrderTraversal(Node **ptr = &root)
{
	if (!(*ptr))
		return;
	cout << (*ptr)->data << ' ';
	preOrderTraversal(&((*ptr)->left));
	preOrderTraversal(&((*ptr)->right));
}

void inOrderTraversal(Node **ptr = &root)
{
	if (!(*ptr))
		return;
	inOrderTraversal(&((*ptr)->left));
	cout << (*ptr)->data << ' ';
	inOrderTraversal(&((*ptr)->right));
}

void postOrderTraversal(Node **ptr = &root)
{
	if (!(*ptr))
		return;
	postOrderTraversal(&((*ptr)->left));
	postOrderTraversal(&((*ptr)->right));
	cout << (*ptr)->data << ' ';
}

bool checkIfBinaryTreeIsBST(Node **ptr = &root, int prev_data = INT_MIN)
{
	if (!(*ptr))
		return true;
	bool check = checkIfBinaryTreeIsBST(&((*ptr)->left), prev_data);
	if (!check)
		return false;
	if ((prev_data > (*ptr)->data) || ((*ptr)->left && (*ptr)->left->data > (*ptr)->data))
		return false;
	prev_data = (*ptr)->data;
	return checkIfBinaryTreeIsBST(&((*ptr)->right), prev_data);
}

Node **findMinNode(Node **ptr)
{
	assert(root != NULL); // Check if tree isn't empty.

	if (!(*ptr)->left)
		return ptr;
	return findMinNode(&((*ptr)->left));
}

void deleteNode(int data, Node **ptr = &root, Node **prev = NULL)
{
	// Searching
	if (!(*ptr))
	{
		cout << "Node not found" << endl;
		return;
	}
	if ((*ptr)->data > data)
	{
		return deleteNode(data, &((*ptr)->left), ptr);
	}
	else if ((*ptr)->data < data)
	{
		return deleteNode(data, &((*ptr)->right), ptr);
	}

	// Deleting

	// Case-1 : Deleting leaf node
	if (!((*ptr)->left) && !((*ptr)->right))
	{
		if (prev)
			(*prev)->left == (*ptr) ? (*prev)->left = NULL : (*prev)->right = NULL;
		if ((*ptr) == root)
			root = NULL;
		delete (*ptr);
		cout << "Node deleted" << endl;
		return;
	}

	// Case-2 : Deleting node with only 1 child
	if (!((*ptr)->left))
	{
		Node *save = (*ptr)->right;
		(*ptr)->data = save->data;
		(*ptr)->right = save->right;
		(*ptr)->left = save->left;
		delete save;
		cout << "Node deleted" << endl;
		return;
	}
	if (!((*ptr)->right))
	{
		Node *save = (*ptr)->left;
		(*ptr)->data = save->data;
		(*ptr)->left = save->left;
		(*ptr)->right = save->right;
		delete save;
		cout << "Node deleted" << endl;
		return;
	}

	// Case-3 : Deleting node with 2 childs
	Node *save = *findMinNode(&(*ptr)->right);
	(*ptr)->data = save->data;
	deleteNode(save->data, &save, ptr);
}

int inorderSuccessor(int data, Node **ptr = &root, Node **last_left = NULL)
{
	// Searching
	if (!(*ptr))
	{
		throw std::invalid_argument("Node not found in tree");
	}
	if ((*ptr)->data > data)
	{
		return inorderSuccessor(data, &((*ptr)->left), ptr);
	}
	else if ((*ptr)->data < data)
	{
		return inorderSuccessor(data, &((*ptr)->right), last_left);
	}

	// Finding successor
	if ((*ptr)->right)
		return (*findMinNode(&((*ptr)->right)))->data;

	if (!last_left || !(*last_left))
		return INT_MIN;
	return (*last_left)->data;
}

void deleteTree(Node **ptr = &root)
{
	if (!(*ptr))
		return;
	deleteTree(&((*ptr)->left));
	deleteTree(&((*ptr)->right));
	delete *ptr;
}

int main()
{
	inserter(40);
	inserter(20);
	inserter(10);
	inserter(30);
	inserter(30);
	inserter(35);
	inserter(35);
	inserter(30);
	inserter(50);
	inserter(39);
	searcher(30);
	cout << "Min: " << findMin() << endl;
	cout << "Max: " << findMax() << endl;
	cout << "Height of Tree: " << findHeightOfTree() << endl;
	queue<Node **> cur_nodes;
	cout << "Level order traversal: ";
	levelOrderTraversal(cur_nodes);
	cout << endl;
	cout << "Pre-order traversal: ";
	preOrderTraversal();
	cout << endl;
	cout << "In-order traversal: ";
	inOrderTraversal();
	cout << endl;
	cout << "Post-order traversal: ";
	postOrderTraversal();
	cout << endl;
	cout << "Is BST ?: ";
	checkIfBinaryTreeIsBST() ? cout << "Yes" : cout << "No";
	cout << endl;
	deleteNode(40);
	cout << "In-order traversal: ";
	inOrderTraversal();
	cout << endl;
	cout << "In-order successor: ";
	cout << inorderSuccessor(20);
	cout << endl;
	deleteTree();
	return 0;
}
