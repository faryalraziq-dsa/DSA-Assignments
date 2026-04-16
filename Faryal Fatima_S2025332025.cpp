/*
    Name: Faryal Fatima
    ID: S2025332025
    Data Structures and Algorithms
	Assignment # 1
*/
#include <iostream>
using namespace std;

/* =========================================================
   Q1 – ARRAYS & SEARCHING
   ========================================================= */

// Q1.A.1
// Contiguous memory allocation means storing elements in adjacent memory locations.
// Arrays use it so we can directly access any element using index.
// This gives O(1) access time because address is calculated instantly.

// Q1.A.2
// Memory leak happens when allocated memory is not freed.
// Example: using new to create an array but forgetting delete[].
// This wastes memory.

// Q1.A.3
// Static array has fixed size at compile time.
// Dynamic array size is decided at runtime.
// Fixed size matters because it cannot grow or shrink.

// Q1.A.4
// Array access is O(1) because elements are in continuous memory.
// Linked list is not O(1) because we must traverse nodes one by one.

/* ---------- Q1.B ---------- */

int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

void findMinMax(int arr[], int size, int &minVal, int &maxVal) {
    minVal = arr[0];
    maxVal = arr[0];

    for(int i = 1; i < size; i++) {
        if(arr[i] < minVal) minVal = arr[i];
        if(arr[i] > maxVal) maxVal = arr[i];
    }
}

/* =========================================================
   Q2 – BUBBLE SORT
   ========================================================= */

// Q2.A.1
// Bubble sort compares adjacent elements and swaps if needed.
// Largest element "bubbles" to the end in each pass.

// Q2.A.2
// Best: O(n), Average: O(n^2), Worst: O(n^2)
// If already sorted and optimization used ? O(n)

// Q2.A.3
// Selection sort makes fewer swaps.
// Bubble sort is simpler but slower in general.

void bubbleSort(int arr[], int size, int &swapCount) {
    for(int i = 0; i < size - 1; i++) {
        bool swapped = false;

        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapCount++;
                swapped = true;
            }
        }

        cout << "After pass " << i+1 << ": ";
        for(int k = 0; k < size; k++)
            cout << arr[k] << " ";
        cout << endl;

        if(!swapped) break;
    }
}

/* =========================================================
   Q3 – BINARY SEARCH
   ========================================================= */

// Q3.A.1
// Array must be sorted for binary search.

// Q3.A.2
// Dry run for key=23:
// low=0 high=7 mid=3 ? 12
// low=4 high=7 mid=5 ? 23 (found)

// Q3.A.3
// Linear Search: O(n)
// Binary Search: O(log n)
// Binary is faster because it halves the search space.

int binarySearch(int arr[], int size, int key, int &iterations) {
    int low = 0, high = size - 1;

    while(low <= high) {
        iterations++;
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/* =========================================================
   Q4 – COMPLEXITY ANALYSIS
   ========================================================= */

// Q4.A.1
// Big O describes worst-case performance.
// It ignores machine speed and focuses on growth rate.

// Q4.A.2
// Big O = worst case
// Omega = best case
// Theta = exact bound

// Q4.A.3
// Fastest ? Slowest:
// O(1), O(log n), O(n), O(n log n), O(n^2)

// Q4.A.4
// Space complexity = memory used.
// If array of size n created ? O(n)

// Q4.A.5
// Wrong. Faster computer doesn’t beat algorithm efficiency for large n.

// Q4.B.1
// Nested loop ? O(n^2)
void nestedLoop(int arr[], int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout << arr[i] << " ";
}

// Single loop ? O(n)
void singleLoop(int arr[], int n) {
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}

// Q4.B.2
// Checking all elements ? O(n^2)
bool checkArrays(int A[], int B[], int n) {
    for(int i=0;i<n;i++) {
        bool found = false;
        for(int j=0;j<n;j++) {
            if(A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}

// Better approach: use sorting or hashing ? O(n log n) or O(n)

/* =========================================================
   Q5 – LINKED LIST
   ========================================================= */

// Q5.A.1
// Linked list is a collection of nodes connected via pointers.
// Unlike arrays, memory is not contiguous.

// Q5.A.2
// Insert head: O(1)
// Insert tail: O(n)
// Delete: O(n)

// Q5.A.3
// Not deleting node causes memory leak.

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteByValue(int val) {
        if(head == NULL) return;

        // delete head
        if(head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << val << endl;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL && temp->next->data != val)
            temp = temp->next;

        if(temp->next == NULL) {
            cout << "Value not found\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Deleted " << val << endl;
    }
};

/* =========================================================
   MAIN FUNCTION
   ========================================================= */

int main() {

    // Q1
    int arr[10] = {4,15,7,23,1,9,42,18,6,30};
    int index = linearSearch(arr, 10, 42);

    if(index != -1)
        cout << "42 found at index: " << index << endl;
    else
        cout << "Not found\n";

    int minVal, maxVal;
    findMinMax(arr, 10, minVal, maxVal);
    cout << "Min: " << minVal << " Max: " << maxVal << endl;

    // Q2
    int arr2[7] = {64,34,25,12,22,11,90};
    int swaps = 0;

    cout << "\nBefore Sorting: ";
    for(int i=0;i<7;i++) cout<<arr2[i]<<" ";
    cout<<endl;

    bubbleSort(arr2, 7, swaps);
    cout << "Total swaps: " << swaps << endl;

    // Q3
    int arr3[10] = {2,5,8,12,16,23,38,45,56,72};
    int iterations = 0;

    int res = binarySearch(arr3, 10, 56, iterations);
    cout << "Binary Search index: " << res << endl;
    cout << "Iterations: " << iterations << endl;

    // Q5
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "\nLinked List: ";
    list.display();

    list.deleteByValue(20);
    list.deleteByValue(100);

    cout << "After deletion: ";
    list.display();

    return 0;
}

// https://github.com/faryalraziq-dsa/DSA-Assignments/upload/main
