#include <iostream>

using namespace std;

static char tablero[3][3]={{'-','-x','-'},{'-','-','-'},{'-','-','-'}};

bool comprobar_posicion(int x, int y){
	if(tablero[x][y]!='-'){
		cout<<"casilla ocupada"<<endl;
		return false;
	}
	return true;
}

void mostrar_tablero(){
	for(int i = 0; i<3;i++){
		for(int j=0; j<3; j++){
			cout<<tablero[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int validar(){
	int valor=0;
	cin>>valor;
	while(valor<1|| valor>3){
		cout<<"Valor fuera de rango\nIngresa uno entre 1 y 3: ";
		cin>>valor;
	}
	return valor;
}

void ingresar(char valor){
	int x, y;
	cout<<"Ingresa los valores que se te pidan (1-3)"<<endl;
	cout<<"Ingresa la posicion en x: ";
	x=validar();
	x-=1;
	cout<<"Ingresa la posicion en y: ";
	y=validar();
	y-=1;
	while(!comprobar_posicion(x,y)){
		cout<<"Ingresa la posicion en x: ";
		x=validar();
		x-=1;
		cout<<"Ingresa la posicion en y: ";
		y=validar();
		y-=1;
	}
	tablero[x][y]=valor;
}

void entrada_jugador(int numero_jugada){
	if((numero_jugada%2)!=0){
		cout<<"Turno jugador: O"<<endl;
		ingresar('O');
	}
	else{
		cout<<"Turno jugador: X"<<endl;
		ingresar('X');
	}
	system("clear");
	mostrar_tablero();
}

bool comprobar_tablero(){
	char chars[2]={'X','O'};
	int act, i, j;
	bool flag;
	for(act=0;act<2;act++){
		flag=true;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(tablero[i][j]==chars[act]){
					flag=true;
				}
				else{
					flag=false;
					break;
				}
			}
			if(flag){
				cout<<"Ganador "<<chars[act]<<endl;
				return true;
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(tablero[j][i]==chars[act]){
					flag=true;
				}
				else{
					flag=false;
					break;
				}
			}
			if(flag){
				cout<<"Ganador "<<chars[act]<<endl;
				return true;
			}
		}
		for(i=0;i<3;i++){
			if(tablero[i][i]==chars[act]){
				flag=true;
			}
			else{
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<"Ganador "<<chars[act]<<endl;
			return true;
		}
		for(i=0;i<3;i++){
			if(tablero[i][2-i]==chars[act]){
				flag=true;
			}
			else{
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<"Ganador "<<chars[act]<<endl;
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[]) {
	for(int i=1;i<=9;i++){
		entrada_jugador(i);
		if(comprobar_tablero()){
			break;
		}
	}
	return 0;
}
