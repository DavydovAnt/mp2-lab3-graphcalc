#pragma once
template <class  T>
class TQueue {
	T *arr;
	int MaxSize;
	int Head, Tail;
	int CurSize;
public:
	TQueue(int _size = 50) {
		MaxSize = _size;
		arr = new T[MaxSize];
		CurSize = 0;
		Head = 0; Tail = -1;
	}
	TQueue(const TQueue<T> &q) {
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
	}
	~TQueue() {
		delete[]arr;
	}

	int GetMaxSize() {
		return MaxSize;
	}
	int GetHead() {
		return Head;
	}
	int GetSize() {
		return CurSize;
	}

	TQueue<T>& operator =(const TQueue<T> &q) {
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
	}
	bool empty() {
		return !CurSize;
	}
	bool full() {
		return CurSize == MaxSize;
	}
	void push(const T &a) {
		if (full()) throw 1;
		if (Tail != MaxSize - 1)
			Tail++;
		else {
			Tail = 0;
		}
		arr[Tail] = a;
		CurSize++;
	}
	T pop() {
		if (empty()) throw 1;
		int pos = Head;
		if (Head != MaxSize - 1)
			Head++;
		else {
			Head = 0;
		}
		CurSize--;
		return arr[pos];
	}
};