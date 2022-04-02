#pragma once
#include <xmemory>
#include <xutility>
#include <iostream>

template<class T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();
	int getSize();
	T& at(int);
	const T& at(int) const;
	void clear();
	void add(T, int);
	void push_back(T);
	void remove(int);
	

private:
	T* array;
	int size;
};

template<class T>
inline DynamicArray<T>::DynamicArray()
{
	size = 0;
	array = nullptr;
}

template<class T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] array;
}

template<class T>
inline int DynamicArray<T>::getSize()
{
	return size;
}

template<class T>
inline T& DynamicArray<T>::at(int index)
{
	T& tmpVal = array[index];
	if ((index >= 0) && (index < size))
		return tmpVal;
	else
		exit(EXIT_FAILURE);
}

template<class T>
inline const T& DynamicArray<T>::at(int index) const
{
	T& tmpVal = array[index];
	if ((index >= 0) && (index < size))
		return tmpVal;
	else
		exit(EXIT_FAILURE);
}

template<class T>
inline void DynamicArray<T>::clear()
{
	delete[] array;
	size = 0;
	array = nullptr;
}

template<class T>
inline void DynamicArray<T>::add(T obj, int index)
{
	if (array == nullptr)
	{
		array = new T[1];
		array[0] = obj;
	}
	else
	{
		T* tmpArray = new T[size + 1];
		int ogArrayIt = 0;
		for (int i = 0; i <= size; i++)
		{
			if (i == index)
			{ 
				tmpArray[i] = obj;
			}
			else
			{ 
				tmpArray[i] = array[ogArrayIt];
				ogArrayIt++;
			}
			
		}
		delete[] array;
		array = tmpArray;
	}
	size++;
}

template<class T>
inline void DynamicArray<T>::push_back(T obj)
{
	if (array == nullptr)
	{
		array = new T[1];
		array[0] = obj;
	}
	else
	{
		T* tmpArray = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmpArray[i] = array[i];
		}
		tmpArray[size] = obj;
		delete[] array;
		array = tmpArray;
	}
	size++;
}

template<class T>
inline void DynamicArray<T>::remove(int index)
{
	T* tmpArray;
	if (size <= 1) 
	{
		tmpArray = nullptr;
	}
	else 
	{
		if ((index > 0) && (index < size))
		{
			tmpArray = new T[size - 1];
			int ogArrayIt = 0;
			for (int i = 0; i <= size; i++)
			{
				if (i == index - 1)
				{
					tmpArray[i] = array[ogArrayIt];
					ogArrayIt += 2;
				}
				else
				{
					tmpArray[i] = array[ogArrayIt];
					ogArrayIt++;
				}
			}
			delete[] array;
			array = tmpArray;
			size--;
		}
	}
}

