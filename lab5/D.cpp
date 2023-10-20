#include <iostream>
#include <vector>
using namespace std;

struct MinHeap {
    vector<long long> heap;

    long long parent(long long i) {
        return (i - 1) / 2;
    }
    long long left(long long i) {
        return 2 * i + 1;
    }
    long long right(long long i) {
        return 2 * i + 2;
    }

    void insert(long long value) {
        heap.push_back(value);
        long long i = heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        } 
    }
    void heapify(long long i) {
        long long l = this->left(i);
        long long r = this->right(i);
        int smallest = i;
        if (l < this->heap.size() && this->heap[l] < this->heap[i])
            smallest = l;
        if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
            smallest = r;
        if (smallest != i) {
            swap(this->heap[i], this->heap[smallest]);
            this->heapify(smallest);
        }
    }   
    void print(){
        for(long long i = 0; i < heap.size(); i++){
            cout << heap[i] << ' ';
        }
        cout << endl;
    }

    long long extractMin() {
        if (this->heap.size() == 0) return 0;
        if (this->heap.size() == 1) {
            long long root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        long long root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }


    long long answer(int x){
        long long answer = 0;
        while(heap.size() > 1 && heap[0] < x){
            long m1 = extractMin();
            long m2 = extractMin();
            long long dnew = m1+(2*m2);
            insert(dnew);
            answer ++;
        }
        if(heap[0] < x){
            return -1;
        }else return answer;
    }
};


int main(){
    MinHeap heap;
    long long n,m; cin >> n >> m;

    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        heap.insert(x);
    }

    cout << heap.answer(m);

}
