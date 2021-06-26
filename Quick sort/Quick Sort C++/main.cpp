#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
unsigned t0, t1;

using namespace std;

void sort(int *a, int n);
void quicksort(int *a, int left, int right);
int partition(int *a, int left, int right);
void swap(int *a, int sourcepos, int destpos);
void displaydata(int *a, int n);
int readInputFromFile(int *input);

int main() {
    cout<<"QUICK SORT"<<endl;
    const int size = 100000;
    int input[size];
    cout << "Reading input: ";
    int n = readInputFromFile(input);
    if (n > 0) {
        cout  << n << " items" << endl;
    } else {
        cout << "Zero items!" << endl;
        exit(1);
    }
    t0=clock();
    cout << "Before sorting: " << endl;
    displaydata(input, n);
    sort(input, n);
    t1=clock();
    cout << "After sorting: " << endl;
    displaydata(input, n);


    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Time: " <<time<< endl;
    return 0;
}
void sort(int *a, int n) {
    quicksort(a, 0, n - 1);
}
void quicksort(int *a, int left, int right) {
    if (left < right) {
        int pivotpos = partition(a, left, right);
        quicksort(a, left, pivotpos - 1);
        quicksort(a, pivotpos + 1, right);
    }
}
int partition(int *a, int left, int right) {

    int pivotpos = left;
    int store = left;
    swap(a, pivotpos, right);

    for (int i = left; i < right; i++) {
        if (*(a + i) <= *(a + right)) {
            swap(a, i, store);
            store++;
        }
    }

    swap(a, store, right);

    return store;
}

void displaydata(int *a, int n) {
    for (int i = 0; i < n; i++)
        cout << "\t" << *(a + i);
    cout << endl;
}


void swap(int *a, int sourcepos, int destpos) {
    int temp = *(a + sourcepos);
    *(a + sourcepos) = *(a + destpos);
    *(a + destpos) = temp;
}

int readInputFromFile(int *input) {
    const char* inputFilePath = "File_100.txt";
    ifstream in(inputFilePath);
    if (in.fail()) {
        cerr << "Failed to open the file: " << inputFilePath << "!" << endl;
        exit(1);
    }
    int value, count = 0;
    while (in >> value) {
        if (in.fail()) {
            cerr << "Input source failed after reading " << count << " items!"
                    << endl;
            in.close();
            exit(1);
        } else {
            *(input + count) = value;
            count++;
        }
    }
    in.close();
    return count;
}
