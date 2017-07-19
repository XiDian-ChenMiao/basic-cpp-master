#ifndef _QUEUE_H
#define _QUEUE_H
template<typename TYPE>
class Queue
{
public:
	Queue();
	~Queue();
	bool isEmpty() const;//判断队列是否为空
	const TYPE& getFront() const;//获取队首元素
	void enqueue(const TYPE &element);//入队操作
	TYPE dequeue();//出队操作
	void makeEmpty();//清空队列
	void displayAllElements() const;//显示队列中所有元素操作
private:
	struct Node
	{
		TYPE element;
		Node *next;
		Node(const TYPE &_element,Node *_next = 0) : element(_element),next(_next) {}
	};
	Node *front;
	Node *tail;
};
/*构造函数操作*/
template<typename TYPE>
Queue<TYPE>::Queue()
{
	front = tail = 0;
}
/*析构函数操作*/
template<typename TYPE>
Queue<TYPE>::~Queue()
{
	makeEmpty();
}
/*清空队列操作*/
template<typename TYPE>
void Queue<TYPE>::makeEmpty()
{
	while(!isEmpty())
		dequeue();
}
/*判断为空操作*/
template<typename TYPE>
bool Queue<TYPE>::isEmpty() const
{
	return front == 0;
}
/*获取队首操作*/
template<typename TYPE>
const TYPE& Queue<TYPE>::getFront() const
{
	if(isEmpty())
		throw "Queue is empty.";
	return front->element;
}
/*入队操作*/
template<typename TYPE>
void Queue<TYPE>::enqueue(const TYPE &element)
{
	if(isEmpty())
		tail = front = new Node(element);
	else
		tail = tail->next = new Node(element);
}
/*出队操作*/
template<typename TYPE>
TYPE Queue<TYPE>::dequeue()
{
	TYPE frontElement = getFront();
	Node *oldFrontPosition = front;
	front = front->next;
	delete oldFrontPosition;
	return frontElement;
}
/*显示队列中所有元素的操作*/
template<typename TYPE>
void Queue<TYPE>::displayAllElements() const
{
	Node *position = front;
	while(position)
	{
		cout << position->element << ' ';
		position = position->next;
	}
	cout << endl;
}
#endif
