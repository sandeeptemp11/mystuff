#include <bits/stdc++.h>
using namespace std;

class min_pq{
    public:
    vector <int> arr;
    int high = -1;

    void insert(int data);
    void insert_helper(int);
    int getMin();
    void removeMin();
    void min_heapify(int);
    bool isEmpty(){
        return high == -1;
    }
};

void min_pq::insert_helper(int i){
    if(i == 0) return;
    int p = (i-1)/2;
    if(arr[p] > arr[i]){
        swap(arr[p], arr[i]);
        insert_helper(p);
    }
}

void min_pq::insert(int data){
    arr.push_back(data);
    high++;
    insert_helper(high);
}

int min_pq::getMin(){
    if(high == -1) return -1;
    return arr[0];
}


void min_pq::min_heapify(int i){
    int left_index = 2*i+1;
    int right_index = 2*i+2;
    int min_index = i;
    if(left_index <= high && arr[left_index] < arr[min_index]) min_index = left_index;
    if(right_index <= high && arr[right_index] < arr[min_index]) min_index = right_index;
    if(min_index != i){
        swap(arr[min_index], arr[i]);
        min_heapify(min_index);
    }
}

void min_pq::removeMin(){
    if(high == -1) return;
    swap(arr[0], arr[high--]);
    arr.pop_back();
    min_heapify(0);
}

int main(){
    int arr[] = {3, 2, 8, 8, 1, 2};
    min_pq pq;
    for(auto ele: arr){
        pq.insert(ele);
    }

    while(!pq.isEmpty()){
        cout << pq.getMin() << " ";
        pq.removeMin();
    }
    cout << "\n";
}
