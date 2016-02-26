#include <iostream>

using namespace std;

int cont=0;
char Laberinto[35][35]; 
int r1[] = {-1,1,0,0}; 
int r2[] = {0,0,-1,1}; 

void floodfill(int r,int c,int filas){
  if (r < 0 || r >= filas || c < 0 || c>= filas) return;
  if (Laberinto[r][c] != '.') return;
  Laberinto[r][c] = 'c';
  for(int i=0;i<4;i++){
    floodfill(r+r1[i],c+r2[i],filas);
  }
  return;
}

int contador = 0;

void contadorL(int filas,string input){
  // cout << input << endl;
  for(int i=0;i<filas;i++){
    Laberinto[contador][i] = input[i];
  }
  contador++;
}

imprimirM(int filas){
  for(int i=0;i<= filas;i++){
    for(int j=0;j<=filas;j++){
      cout << Laberinto[i][j] << ' ' ;
    }
    cout << endl;
  }
}


void imprimir(int filas){
  for(int i=0;i<filas;i++){
    for(int j=0;j<filas;j++){
      if(Laberinto[i][j]=='c'){
        if(Laberinto[i-1][j]!='c'){
	  cont++;
	}
	if(Laberinto[i+1][j]!='c'){
	  cont++;
	}
	if(Laberinto[i][j-1]!='c'){
	  cont++;
	}
	if(Laberinto[i][j+1]!='c'){
	  cont++;
	}
      }
    }
  }
  cout << (cont-4)*9;

}


int main(){
  int filas,columnas =0;
  string input;
  //  for(int i = 0; i < 35; i++)
  //for(int j = 0; j < 35; j++)
  //  Laberinto[i][j] = 'f';
  
  cin >> filas;
  getline(cin,input);
  for(int i=0;i<filas;i++){
    getline(cin,input);
    contadorL(filas,input);
  }
  
  //imprimirM(filas);
  floodfill(0,0,filas);
  floodfill(filas-1,filas-1,filas);
  imprimir(filas);
}

