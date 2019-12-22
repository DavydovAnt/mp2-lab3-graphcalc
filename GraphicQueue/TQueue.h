#pragma once
template <class  T>
class TQueue {
	T *arr;
	int MaxSize;
	int Head, Tail;  //индекс первого и последнего элемента
	int CurSize;     //размер очереди
public:
	TQueue(int _size = 10);
	TQueue(const TQueue<T> &q);
	~TQueue();

	int GetMaxSize() { return MaxSize; }
	int GetHead() { return Head; }
	int GetSize() { return CurSize; }

	TQueue<T>& operator =(const TQueue<T> &q);
	
	bool empty();				//проверка на пустоту
	bool full();				//проверка на заполненость
	void push(const T &a);		//добавить элемент в очередь
	T pop();					//изъ€ть элемент из очереди
};

template <class  T>
TQueue<T>::TQueue(int _size){
		MaxSize = _size;
		arr = new T[MaxSize];
		CurSize = 0;
		Head = 0; Tail = -1;
}/*-------------------------------------------------------------------------*/

template <class  T>
TQueue<T>::TQueue(const TQueue<T> &q) {
	MaxSize = q.MaxSize;
	Head = q.Head;
	CurSize = q.CurSize;
	Tail = q.Tail;
	arr = new T[MaxSize];
	if (Head <= Tail) {
		for (int i = Head; i <= Tail; i++)
			arr[i] = q.arr[i];
	}
	else
	{
		for (int i = Head; i < MaxSize; i++)
			arr[i] = q.arr[i];
		for (int i = 0; i <= Tail; i++)
			arr[i] = q.arr[i];
	}
}/*-------------------------------------------------------------------------*/

template <class  T>
TQueue<T>::~TQueue()
{ 
	delete []arr;
}/*-------------------------------------------------------------------------*/

template <class  T>
TQueue<T>& TQueue<T>::operator =(const TQueue<T> &q) {
	if (this != &q) {
		if (MaxSize != q.MaxSize) {
			MaxSize = q.MaxSize;
			delete[]arr;
			arr = new T[MaxSize];
		}
		Head = q.Head;
		CurSize = q.CurSize;
		Tail = q.Tail;
		if (Head <= Tail) {
			for (int i = Head; i <= Tail; i++)
				arr[i] = q.arr[i];
		}
		else
		{
			for (int i = Head; i < MaxSize; i++)
				arr[i] = q.arr[i];
			for (int i = 0; i <= Tail; i++)
				arr[i] = q.arr[i];
		}
	}
	return *this;
}/*-------------------------------------------------------------------------*/

template <class  T>
bool TQueue<T>::empty() {
	return !CurSize;
}/*-------------------------------------------------------------------------*/

template <class  T>
bool TQueue<T>::full() {
	return CurSize==MaxSize;
}/*-------------------------------------------------------------------------*/

template <class  T>
void TQueue<T>::push(const T &a) {
	if (full()) throw "Queue is full";
	if (Tail != MaxSize - 1)
		Tail++;
	else {Tail = 0;
	}
	arr[Tail] = a;
	CurSize++;
}/*-------------------------------------------------------------------------*/

template <class  T>
T TQueue<T>::pop() {
	if (empty()) throw "Queue is empty";
	int pos = Head;
	if (Head != MaxSize - 1)
		Head++;
	else { Head = 0;
	}
	CurSize--;
	return arr[pos];
}/*-------------------------------------------------------------------------*/