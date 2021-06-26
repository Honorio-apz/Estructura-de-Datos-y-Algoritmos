#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;
unsigned t0, t1;

void print(int a[], int sz) {
	for (int i = 0; i < sz;  i++ ) cout << a[i] << " ";
		cout << endl;
}




void bubbleSort(int a[], int n)
{
    int i, j,temp,pass=0;
    for(i = 0; i<n; i++)
	 {
   		for(j = i+1; j<n; j++)
   		{
      		if(a[j] < a[i]) {
         	temp = a[i];
         	a[i] = a[j];
         	a[j] = temp;
      		}
   		}
		pass++;
	}
}




int main(){
///////////Lectura de files.txt//////////
	int cc=0;
    int con=0;
    float numeros[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    string f="File_";
    string e=".txt";
    string concat;
    cc=100;
    int b=0;
    while (cc<=500) {
		con=cc;
		concat=f+to_string(con)+e;
        cout<<concat<<endl;
        string array[2];
        short x=0;
		string line="";
		string temp="";
		int d[con]={0};
		int j=0;
		ifstream myfile (concat);

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

	   for (int i=0;i<line.length();i++)
	   {
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
		///////
		cout << "Datos entrantes: \n";
		//print(d,n);       //Datos entrantes
		t0=clock();
		//se ejecuta algoritmo de ordenamiento	
		bubbleSort(d, n);
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "tiempo de ejecucion: " << time << endl;		
			
		numeros[b]=time;
		b++;
		cout << "\nDatos ordenados: \n";
		//print(d,n);		//Datos ordenados
		
		
        
        cc=cc+400;
    }
    
    
    cc=1000;
    while (cc<=100000) {
		con=cc;
		concat=f+to_string(con)+e;
        cout<<concat<<endl;
        
        string array[2];
        short x=0;
		string line="";
		string temp="";
		int d[con]={0};
		int j=0;
		ifstream myfile (concat);

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

	   for (int i=0;i<line.length();i++)
	   {
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
		
		///////
		cout << "Datos entrantes: \n";
		//print(d,n);       //Datos entrantes
		t0=clock();
		//se ejecuta algoritmo de ordenamiento	
		bubbleSort(d, n);
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "tiempo de ejecucion: " << time << endl;		
			
		numeros[b]=time;
		b++;
		cout << "\nDatos ordenados: \n";
		//print(d,n);		//Datos ordenados
		
		  
        if (cc>=1000 and cc<10000){
			cc=cc+1000;
		}
		else if (cc>=10000 and cc<=100000){
			cc=cc+10000;
		}
    }
    cout << "\nTIEMPO DE EJECUCION: bubbleSort \n";
    for(unsigned int i = 0; i < 21; i++){
		
		cout<<numeros[i]<<",";
	}
     
    return 0;
    
}
