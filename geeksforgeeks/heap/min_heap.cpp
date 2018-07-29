#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Minheap
{
private:
	vector<int> harr;
	int capacity;
	int heap_size;
public:
	Minheap(int capacity);
	void Minheapify(int k);
	int parent(int i);
	int left(int i);
	int right(int i);
	int getMin();
	int extractMin();
	void decreaseKey(int i, int new_val);
	void deleteKey(int i);
	void insertKey(int i);
};

Minheap::Minheap(int cap)
{
	harr.resize(cap);
	capacity = cap;
	heap_size = 0;
}

int Minheap::parent(int i)
{
	return (i-1)/2;
}

int Minheap::left(int i)
{
	return (2*i + 1);
}

int Minheap::right(int i)
{
	return (2*i + 2);
}

int Minheap::getMin()
{
	return harr[0];
}

void Minheap::Minheapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < heap_size && harr[l] < harr[i])
		smallest = l;
	if(r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if(smallest != i){
		swap(harr[i], harr[smallest]);
		Minheapify(smallest);
	}
}

int Minheap::extractMin()
{
	if(heap_size <= 0)
		return INT_MAX;
	if(heap_size == 1){
		heap_size--;
		return harr[0];
	}
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	Minheapify(0);
	return root;
}

void Minheap::insertKey(int k)
{
	if(heap_size == capacity){
		cout << "Heap Overflow \n";
		return;
	}
	heap_size++;
	int i = heap_size-1;
	harr[i] = k;
	while(i != 0 && harr[parent(i)] > harr[i]){
		swap(harr[parent(i)], harr[i]);
		i = parent(i);
	}
}

void Minheap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while(i != 0 && harr[parent(i)] > harr[i]){
		swap(harr[parent(i)], harr[i]);
		i = parent(i);
	}
}

void Minheap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

int main()
{
	Minheap mh(10);
	mh.insertKey(3);
    mh.insertKey(2);
    mh.deleteKey(1);
    mh.insertKey(15);
    mh.insertKey(5);
    mh.insertKey(4);
    mh.insertKey(45);
    cout << mh.extractMin() << "\n";
    cout << mh.getMin() << "\n";
    mh.decreaseKey(2, 1);
    cout << mh.getMin() << "\n";

	return 0;
}