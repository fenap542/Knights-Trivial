#include <bits/stdc++.h>

using namespace std;
//class node for queue using - linked list

template <typename T>
class Node
{
public:
	T data;
	Node<T> *next;

	Node(T data)
	{
		this->data = data;
		next = NULL;
	}
};

// class for queue functions
// getsize()--- returns the size of queue
// empty()---returns the bool value if the queue is empty or not
// push()---enqueue function add a new pair at the ed of queue
// front()--- returns the front pair of the queue
// pop()--- delete the front element of the queue

template <typename T>
class Queue
{
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	Queue()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	int getSize()
	{
		return size;
	}

	bool empty()
	{
		return size == 0;
	}

	void push(T element)
	{
		Node<T> *newNode = new Node<T>(element);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	T front()
	{
		if (empty())
		{
			return {0, 0};
		}
		return head->data;
	}

	void pop()
	{
		if (empty())
		{
		}
		Node<T> *temp = head;
		head = head->next;
		delete temp;
		size--;
	}
};

// node structure for generic tree using linked list
typedef struct node
{
	pair<int, int> data;
	vector<node *> child;
};
// global variables

int n; //size of the chess board

int arr[100][100];		  //2-d array for bfs
int ed[2];				  //ed co-ordinates
int start[2];			  //start co-ordinates
Queue< pair<int, int> > q;  //queue for bfs
vector< pair<int, int> > v; //vector for storing the moves

//for inserting an element in tree
//p1 parent node
//p2 child node
void insert(node **root, pair<int, int> p1, pair<int, int> p2)
{
	node *ne = new node();
	ne->data = p2;
	if ((*root)->data == p1)
	{
		(*root)->child.push_back(ne);
		return;
	}
	else if ((*root)->child.size() == 0)
	{
		return;
	}
	else
	{
		for (int i = 0; i < (*root)->child.size(); i++)
		{
			insert(&((*root)->child[i]), p1, p2);
		}
	}
}

//for printing the final answer
bool print(node *root, pair<int, int> p)
{
	if (root->child.size() == NULL)
	{
		if (root->data == p)
		{
			v.push_back(root->data);
			return true;
		}

		else
			return false;
	}
	else
	{

		for (int i = 0; i < root->child.size(); i++)
		{
			if (print(root->child[i], p))
			{
				v.push_back(root->data);
				return true;
			}
		}
	}
}

// for checking if the given co-ordinates are inside the chess board and
// if the co-ordinates are are previously visited or not
bool isvalid(int x, int y)
{
	if ((x > 0 && x <= n) && (y > 0 && y <= n) && arr[x][y] == 0)
		return true;
	return false;
}

// checking for all 8 possible moves for a given co-ordinates until it reaches the ed co-ordinates

void moves(node **root)
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if (isvalid(x + 1, y + 2))
		{
			q.push({x + 1, y + 2});
			arr[x + 1][y + 2] = arr[x][y] + 1;
			insert(root, {x, y}, {x + 1, y + 2});

			if (x + 1 == ed[0] && y + 2 == ed[1])
			{
				return;
			}
		}

		if (isvalid(x - 1, y + 2))
		{

			q.push({x - 1, y + 2});
			arr[x - 1][y + 2] = arr[x][y] + 1;
			insert(root, {x, y}, {x - 1, y + 2});

			if (x - 1 == ed[0] && y + 2 == ed[1])
			{
				return;
			}
		}

		if (isvalid(x + 1, y - 2))
		{

			q.push({x + 1, y - 2});
			arr[x + 1][y - 2] = arr[x][y] + 1;
			insert(root, {x, y}, {x + 1, y - 2});

			if (x + 1 == ed[0] && y - 2 == ed[1])
			{
				return;
			}
		}

		if (isvalid(x - 1, y - 2))
		{

			q.push({x - 1, y - 2});
			arr[x - 1][y - 2] = arr[x][y] + 1;
			insert(root, {x, y}, {x - 1, y - 2});

			if (x - 1 == ed[0] && y - 2 == ed[1])
			{
				return;
			}
		}

		if (isvalid(x + 2, y + 1))
		{

			q.push({x + 2, y + 1});
			arr[x + 2][y + 1] = arr[x][y] + 1;
			insert(root, {x, y}, {x + 2, y + 1});

			if (x + 2 == ed[0] && y + 1 == ed[1])
			{
				return;
			}
		}

		if (isvalid(x - 2, y + 1))
		{

			q.push({x - 2, y + 1});
			arr[x - 2][y + 1] = arr[x][y] + 1;
			insert(root, {x, y}, {x - 2, y + 1});

			if (x - 2 == ed[0] && y + 1 == ed[1])
			{
				return;
			}
		}

		if (isvalid(x - 2, y - 1))
		{
			q.push({x - 2, y - 1});
			arr[x - 2][y - 1] = arr[x][y] + 1;
			insert(root, {x, y}, {x - 2, y - 1});

			if (x - 2 == ed[0] && y - 1 == ed[1])
			{
				return;
			}
		}

		if (isvalid(x + 2, y - 1))
		{

			q.push({x + 2, y - 1});
			arr[x + 2][y - 1] = arr[x][y] + 1;
			insert(root, {x, y}, {x + 2, y - 1});

			if (x + 2 == ed[0] && y - 1 == ed[1])
			{
				return;
			}
		}
	}
}

// for taking inputs
void input()
{
	cout << endl
		 << "enter the size of board ";
	cin >> n;
	if (n <= 0)
	{
		cout << endl
			 << "invalid input " << endl
			 << flush;
		system("PAUSE");
		system("cls");
		input();
	}
	cout << endl
		 << "enter the initial co-ordinates ";
	cin >> start[0] >> start[1];
	if (!isvalid(start[0], start[1]))
	{
		cout << endl
			 << "invalid input " << endl
			 << flush;
		system("PAUSE");
		system("cls");
		input();
	}
	cout << endl
		 << "enter the final co-ordinates ";
	cin >> ed[0] >> ed[1];
	if (!isvalid(ed[0], ed[1]))
	{
		cout << endl
			 << "invalid input " << endl
			 << flush;
		system("PAUSE");
		system("cls");
		input();
	}
}

//main function
int main()
{
	input();

	q.push({start[0], start[1]});

	//initializing every element of the array to 0
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			arr[i][j] = 0;
		}
		
	}
	arr[start[0]][start[1]] = 1;
	node *root = new node();
	root->data = {start[0], start[1]};
	moves(&root);
	cout << endl;
	if (arr[ed[0]][ed[1]] == 0)
	{
		cout << "no possible path to reach the given point" << endl;
	}
	else
	{
		cout << endl
			 << "number of steps to reach {" << ed[0] << "," << ed[1] << "} are - " << arr[ed[0]][ed[1]] - 1 << endl;
		bool a = print(root, {ed[0], ed[1]});
		cout << endl;
		for (int i = v.size() - 1; i > 0; i--)
		{
			cout << "{" << v[i].first << "," << v[i].second << "} -> ";
		}
		cout << "{" << v[0].first << "," << v[0].second << "}" << endl;
	}
}
