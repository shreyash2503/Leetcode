// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    vector<int> heap;
    int leftChild(int index){
        return 2 * index + 1;
    }
    int rightChild(int index){
        return 2 * index + 2;
    }
    int parent(int index){
        return (index - 1) / 2;
    }

    void heapifyUp(int index){
        int current = index;
        while(current > 0 && heap[parent(current)] < heap[current]){
            swap(heap[parent(current)], heap[current]);
            current = parent(current);
        }
    }

    void heapifyDown(int index){
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;
        if(left < heap.size() && heap[left] > heap[largest]){
            largest = left;

        }
        if(right < heap.size() && heap[right] > heap[largest]){
            largest = right;
        }

        if(largest != index){
            swap(heap[largest], heap[index]);
            heapifyDown(largest);
        }
    }


    void insert(int value){
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMax(){
        if(heap.size() == 0){
            return -1;
        }
        int element = heap[0];
        int value = heap.back();
        heap.pop_back();
        heap[0] = value;
        heapifyDown(0);
        return element;
    }

    void printHeap() {
        int level = 0;
        int count = 0;
        for (int i = 0; i < heap.size(); i++) {
            if (i == count) {
                cout << "\nLevel " << level << ": ";
                count = count * 2 + 1;
                level++;
            }
            cout << heap[i] << " ";
        }
        cout << endl;
    }


    int findKthLargest(vector<int>& nums, int k) {

        for(int i=0;i<nums.size();i++){
            insert(nums[i]);
        }
        printHeap();
        int ele = 0;
        int count = 0;
        while(count < k){
            ele = getMax();
            cout<<ele<<endl;
            count++;
        }

        return ele;

        
    }
};