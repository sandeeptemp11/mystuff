#include <iostream>
#include <random>
#include <chrono> // For getting the current time

// quick sort
int partition(vector <int>& arr, int low, int high){

    // Use the current time to seed the random number engine
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);

    // Define the distribution range
    std::uniform_int_distribution<int> distr(low, high);

    // Generate a random number
    int random_number = distr(eng);

    int pivot_index = random_number;
    int pivot = arr[pivot_index];
    while(true){
        while(low <= high && arr[low] <= pivot) low++;
        while(high >= low && arr[high] > pivot) high--;
        if(low < high){
            if(high == pivot_index) pivot_index = low;
            swap(arr[low++], arr[high--]);
        }else break;
    }
    swap(arr[low-1], arr[pivot_index]);
    return low - 1;
}

void quick_sort(vector <int>& arr, int low, int high){
    if(low < high){
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index-1);
        quick_sort(arr, partition_index + 1, high);
    }
}

vector<int> sortArray(vector<int>& arr) {
    quick_sort(arr, 0, arr.size() - 1);
    return arr;
}
