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
	bool empty;
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
	empty = false;
}

template<class T>
inline T Dynque<T>::dequeue()
{
	if (!empty)
	{
		linkNode* tmp = head;
		T tmpVal = head->value;
		head = head->next;
		delete tmp;
		size--;
		empty = size < 1;
		return tmpVal;
	}
	else
	{
		std::cerr << "Nothing to dequeue" << std::endl;
		exit(17);
	}
}

template<class T>
[[deprecated("Included for consistency.")]] inline void Dynque<T>::dequeue(T& out)
{
	T* tmp = nullptr;
	tmp = dequeue();
	return tmp;
}

template<class T>
inline bool Dynque<T>::isEmpty()
{
	return empty;
}
