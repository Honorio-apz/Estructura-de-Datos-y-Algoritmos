#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
unsigned t01, t1;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
void displaydata(int *a, int n) {
    for (int i = 0; i < n; i++)
        cout << "\t" << *(a + i);
    cout << endl;
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

int main()
{
    cout<<"HEAP SORT"<<endl;
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
    heapSort(input, n);
    t1=clock();
    cout << "After sorting: " << endl;
    displaydata(input, n);


    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Time: " <<time<< endl;
    return 0;   
}
