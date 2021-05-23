#include <iostream>
#include <chrono>

void quicksort(int* a, int p, int r);
int partition(int* a, int &p, int &r);

void heapify(int* a, int heapSize, int index);
void heapSort(int* a, int heapSize);
void buildMaxHeap(int *a, int &heapSize);

void bubbleSort(int arr[], int n);

int main() {
    const int theSize = 100000;
    int newTable[theSize] = {0};
    srand(time(NULL));
    for(int i=0; i<theSize; ++i){
        newTable[i] = rand() % 1000000;
    }



    // Quicksort - sorting the random table
    auto start = std::chrono::high_resolution_clock::now();
    quicksort(newTable, 0, theSize - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << std::endl;
    std::cout << "Quick sort duration for random table: " << duration.count() << std::endl;

    // Quicksort - sorting the sorted table
    start = std::chrono::high_resolution_clock::now();
    quicksort(newTable, 0, theSize - 1);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Quick sort duration for sorted table: " << duration.count() << std::endl;

    // Quicksort - sorting the reversed sorted table
    std::sort(newTable, newTable + theSize, std::greater<int>());
    start = std::chrono::high_resolution_clock::now();
    quicksort(newTable, 0, theSize - 1);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Quick sort duration for reversed sorted table: " << duration.count() << std::endl;



    // Heap sort - sorting the random table
    for(int i=0; i<theSize; ++i){
        newTable[i] = rand() % 1000000;
    }
    int newTableSize = sizeof(newTable)/sizeof(newTable[0]);
    start = std::chrono::high_resolution_clock::now();
    heapSort(newTable, newTableSize);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << std::endl;
    std::cout << "Heap sort duration for random table: " << duration.count() << std::endl;

    // Heap sort - sorting the sorted table
    start = std::chrono::high_resolution_clock::now();
    heapSort(newTable, newTableSize);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Heap sort duration for sorted table: " << duration.count() << std::endl;

    // Heap sort - sorting the reversed sorted table
    std::sort(newTable, newTable + theSize, std::greater<int>());
    start = std::chrono::high_resolution_clock::now();
    heapSort(newTable, newTableSize);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Heap sort duration for reverse sorted table: " << duration.count() << std::endl;



    // Bubble sort - sorting the random table
    for(int i=0; i<theSize; ++i){
        newTable[i] = rand() % 1000000;
    }
    start = std::chrono::high_resolution_clock::now();
    bubbleSort(newTable, newTableSize);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << std::endl;
    std::cout << "Bubble sort duration for random table: " << duration.count() << std::endl;

    // Bubble sort - sorting the sorted table
    start = std::chrono::high_resolution_clock::now();
    bubbleSort(newTable, newTableSize);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Bubble sort duration for sorted table: " << duration.count() << std::endl;

    // Bubble sort - sorting the reversed sorted table
    std::sort(newTable, newTable + theSize, std::greater<int>());
    start = std::chrono::high_resolution_clock::now();
    bubbleSort(newTable, newTableSize);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Bubble sort duration for reverse sorted table: " << duration.count() << std::endl;

}

void quicksort(int* a, int p, int r){
    if (p < r) {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

int partition(int* a, int &p, int &r){
    int pivot = a[r];
    int smaller = p;
    for(int j = p; j <= r - 1; j++) {
        if(a[j] <= pivot) {
            int temp = a[smaller];
            a[smaller] = a[j];
            a[j] = temp;
            ++smaller;
        }
    }
    int temp = a[smaller];
    a[smaller] = a[r];
    a[r] = temp;
    return smaller;
}

void heapify(int* a, int heapSize, int index){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < heapSize && (a[largest] < a[left])){
        largest = left;
    } else {
        largest = index;
    }
    if(right < heapSize && (a[largest] < a[right])){
        largest = right;
    }
    if(index != largest){
        int temp = a[largest];
        a[largest] = a[index];
        a[index] = temp;
        heapify(a, heapSize, largest);
    }
}

void buildMaxHeap(int *a, int &heapSize){
    for(int i=heapSize/2 -1; i>=0; i--){
        heapify(a, heapSize, i);
    }
}

void heapSort(int* a, int heapSize){
    buildMaxHeap(a, heapSize);
    for(int i=heapSize-1; i>=0; i--){
        int temp=a[0];
        a[0] = a[i];
        a[i] = temp;
        heapSize -= 1;
        heapify(a, heapSize, 0);
    }
}

void bubbleSort(int* a, int n){
    int i{0}, j{0};
    for (i = 0; i < n-1; i++)

        for (j = 0; j < n-i-1; j++)
            if (a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}