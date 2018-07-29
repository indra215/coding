#include <iostream>

using namespace std;

struct ListNode{
	int data;
	struct ListNode *next;
};

struct MinHeapNode{
	ListNode *head;
};

struct MinHeap{
	int capacity, count;
	vector<MinHeapNode*> a;
};

void insert_begin(ListNode **head_ref, int val){
	struct ListNode *n = new ListNode;
	n->data = val;
	n->next = *head_ref;
	*head_ref = n;
}

MinHeap* createMinHeap(int N){
	MinHeap *n = new MinHeap;
	n->capacity = N;
	n->count = 0;
	n->a = new MinHeapNode[N];
	return n;
}

void swap(MinHeapNode **a, MinHeapNode **b){
	MinHeapNode *tmp = *a;
	*a = *b;
	*b = tmp;
}

void minheapify(MinHeap *minheap, int index){
	int l,r,smallest;
	l = 2*index+1;
	r = 2*index+2;

	if(l < minheap->capacity && 
			minheap->a[index].head->data > minheap->[l].head->data){
		smallest = l;
	}else{
		smallest = index;
	}
	if(r < minheap->capacity && 
			minheap->a[smallest].head->data > minheap->a[r].head->data)
		smallest = r;
	if(smallest != index){
		swap(&minheap->a[smallest], &minheap->[index]);
		minheapify(minheap, smallest);
	}
}

void buildminheap(MinHeap *minheap){
	int n = minheap->count-1;
	for(int i=(n-1)/2;i>=0;i--){
		minheapify(minheap, i);
	}
}

void populateminHeap(MinHeap *minheap, vector<ListNode*>& v, int N){
	for(int i=0;i<N;i++){
		minheap->a[minheap->count++].head = v[i];
	}
	buildminheap(minheap, v, N);
}

void sortmachina(vector<ListNode*>& v, int N){
	// initialize a min heap
	MinHeap *minheap = createMinHeap(N);

	// build min heap
	populateminHeap(minheap, v, N);

	

}

int main(){

	vector<ListNode*> v(3);
	v[0] = NULL;
	insert_begin(&v[0], 50);
	insert_begin(&v[0], 40);
	insert_begin(&v[0], 30);

	v[1] = NULL;
	insert_begin(&v[1], 45);
	insert_begin(&v[1], 35);

	v[2] = NULL;
	insert_begin(&v[2], 100);
	insert_begin(&v[2], 80);
	insert_begin(&v[2], 70);
	insert_begin(&v[2], 60);
	insert_begin(&v[2], 10);

	sortmachina(v, 3);

	return 0;
}