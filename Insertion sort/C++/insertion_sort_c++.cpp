#include<iostream>
#include<fstream>
using namespace std;



void insertionSort(int a[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}


void displayarray(int a[], int n){
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
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

    int n = sizeof(d) / sizeof(d[0]);
    cout << "Datos entrantes: \n";
	displayarray(d,n);       //Datos entrantes
	
    insertionSort(d, n);	
    
    cout << "\nDatos ordenados: \n";
	displayarray(d,n);		//Datos ordenados
	
	return 0;
}
