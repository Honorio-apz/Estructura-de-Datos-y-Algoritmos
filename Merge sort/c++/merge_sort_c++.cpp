#include<iostream>
#include<fstream>
using namespace std;


void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2]; //arrays temporales
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[],int l,int r){         //funcion merge
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 

void displayarray(int A[], int size){           //funcion de display
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}



int main(){
///////////Lectura de files.txt//////////
	string array[2];
    short x=0;
    string line="";
    string temp="";
    int d[100000]={0};
    int j=0;
    ifstream myfile ("File_100000.txt");

    if (myfile.is_open()){
        while (! myfile.eof() ){
            getline (myfile,line);
            array[x] = line;
            //cout << array[x] << endl;
			x++;
        }
        myfile.close();
    }
    else cout << "Error al abrir";


/////////////////////////////////////////////   
 
   for (int i=0;i<line.length();i++){
   		if(line[i]=='[' ){}
		else{
	    	if(line[i]!=','){
	    		temp += line[i];
			}
			else{
				d[j]=stoi(temp);
				temp="";
				j++;
			}
		}
		
	}
	

	/////////////////////////////////////////////

    int arr_size = sizeof(d) / sizeof(d[0]);
 
    cout << "Datos entrantes: \n";
    displayarray(d, arr_size);
 
    mergeSort(d, 0, arr_size - 1);
 
    cout << "\nDatos ordenados: \n";
    displayarray(d, arr_size);
    return 0;
}
