#pragma once

template<class T>
class Dynque
{
public:
	Dynque();
	~Dynque();

	void enqueue(T);
	T dequeue();
	void dequeue(T&);
	bool isEmpty();
private:
	struct linkNode
	{
		T value;
		linkNode* next;
	};

	int size;
	linkNode* head;
	linkNode* tail;
};

template<class T>
Dynque<T>::Dynque()
{
	head = nullptr;
	tail = nullptr;
}

template<class T>
Dynque<T>::~Dynque()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

template<class T>
inline void Dynque<T>::enqueue(T obj)
{
	if (head == nullptr)
	{
		head = new linkNode;
		tail = head;
		head->value = obj;
		head->next = nullptr;
	}
	else
	{
		linkNode* tmp = new linkNode;
		tmp->value = obj;
		tail->next = tmp;
		tail = tmp;
	}
	size++;
}

template<class T>
inline T Dynque<T>::dequeue()
{
	if (!isEmpty())
	{
		linkNode* tmp = head;
		T tmpVal = head->value;
		head = head->next;
		delete tmp;
		return tmpVal;
		size--;
	}
}

template<class T>
inline void Dynque<T>::dequeue(T& out)
{
	if (!isEmpty()) 
	{
		linkNode* tmp = new linkNode;
		tmp = head;
		head = head->next;
		out = tmp->value;
		delete tmp;
		size--;
	}
}

template<class T>
inline bool Dynque<T>::isEmpty()
{
	return size < 1;
}
