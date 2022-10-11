#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void jugar();
void jugardos();
void dibujo();

char letra;
string palabras[] = {"cori", "raul", "locro", "pastafrola", "vieja", "estela", "kaladin", "amoladora", "cosarica", "chante"};
string palabra, fallos, palabra2;
bool correcta, completa;
int vida;
int c;

int main(){
	int opcion;
	
	while(true){
		system("cls");
		vida = 6;
		palabra = "";
		fallos = "";
		cout << "\t + + + + + + + + + + A H O R C A O + + + + + + + + + +" << endl;
		cout << "1: 1 player" << endl;
		cout << "2: 2 player" << endl;
		cout << "0: Salir" << endl;
		cout << "Opcion: ";
		
		cin >> opcion;
		
		switch(opcion){
			case 1:
				system("cls");
				jugar();
				break;
			
			case 2:
				system("cls");
				jugardos();
				break;
			
			case 0:
				system("cls");
				exit(1);
				break;
		}
	}
}

void jugar(){
	ifstream archivo;
	string text;
	
	archivo.open("wind.txt");
	
	srand((int)time(NULL));
	c = rand()%10;
	
	for(int i=0;i < (int)palabras[c].size();i++){
		palabra += "-";
	}
	
	while(vida > 0){
		system("cls");
		
		cout << "\t + + + + + + + + + + A H O R C A O + + + + + + + + + +" << endl;
		dibujo();
		cout <<"Fallos: "<< fallos <<" Progreso: " << palabra << endl;
		cout << "Ingrese una letra: ";
		cin >> letra;
		
		correcta = false;
		for(int i=0;i < (int)palabras[c].size();i++){
			if(palabras[c][i] == letra){
				palabra[i] = letra;
				correcta = true;
			}
		}
		
		if(correcta == false){
			vida--;
			fallos += letra;
		}
		
		completa = true;
		for(int i=0;i < (int)palabra.size();i++){
			if(palabra[i] == '-'){
				completa = false;
			}
		}
		
		if(completa == true){
			system("cls");
			cout << "\t + + + + + + + + + + A H O R C A O + + + + + + + + + +" << endl << endl;
			cout << "\t    \\            /          |             |\\   |" << endl;
			cout << "\t     \\    /\\    /           |             | \\  |" << endl;
			cout << "\t      \\  /  \\  /            |             |  \\ |" << endl;
			cout << "\t       \\/    \\/             |             |   \\|" << endl;
			
			dibujo();
			
			cout << "Palabra: " << palabra << endl;
			
			if(palabra == "kaladin"){
			
				while(!archivo.eof()){
					archivo >> text;
					cout << text << endl;
				}
			}
			
			system("pause");
			return;
		}
	}
	system("cls");
	cout << "\t + + + + + + + + + + A H O R C A O + + + + + + + + + +" << endl;
	cout << "    |                  ______                 ____              _____" << endl;
	cout << "    |                 /      \\               /                 |___" << endl;
	cout << "    |                |        |              \\____             |" << endl;
	cout << "    |____             \\______/              \\_____|            |_____" << endl;
	
	dibujo();
			
	cout << "Palabra: " << palabras[c] << endl;
	system("pause");
	return;
}

void jugardos(){
	cout << "  P L A Y E R  1 " << endl;
	cout << "escriba una palabra: ";
	cin >> palabra2;
	
	for(int i=0;i < (int)palabra2.size();i++){
		palabra += "-";
	}
	
	while(vida > 0){
		system("cls");
		
		cout << "\t + + + + + + + + + + A H O R C A O + + + + + + + + + +" << endl;
		cout << "  P L A Y E R  2" << endl;
		dibujo();
		cout <<"Fallos: "<< fallos <<" Progreso: " << palabra << endl;
		cout << "Ingrese una letra: ";
		cin >> letra;
		
		correcta = false;
		for(int i=0;i < (int)palabra2.size();i++){
			if(palabra2[i] == letra){
				palabra[i] = letra;
				correcta = true;
			}
		}
		
		if(correcta == false){
			vida--;
			fallos += letra;
		}
		
		completa = true;
		for(int i=0;i < (int)palabra.size();i++){
			if(palabra[i] == '-'){
				completa = false;
			}
		}
		
		if(completa == true){
			system("cls");
			cout << "\t + + + + + + + + + + A H O R C A O + + + + + + + + + +" << endl << endl;
			cout << "\t                    P L A Y E R   2                    "<< endl << endl;
			cout << "\t    \\            /          |             |\\   |" << endl;
			cout << "\t     \\    /\\    /           |             | \\  |" << endl;
			cout << "\t      \\  /  \\  /            |             |  \\ |" << endl;
			cout << "\t       \\/    \\/             |             |   \\|" << endl;
			
			dibujo();
			
			cout << "Palabra: " << palabra << endl;
			
			system("pause");
			return;
		}
	}
	system("cls");
	cout << "\t + + + + + + + + + + A H O R C A O + + + + + + + + + +" << endl << endl;
	cout << "\t                    P L A Y E R   1                    "<< endl << endl;
	cout << "\t    \\            /          |             |\\   |" << endl;
	cout << "\t     \\    /\\    /           |             | \\  |" << endl;
	cout << "\t      \\  /  \\  /            |             |  \\ |" << endl;
	cout << "\t       \\/    \\/             |             |   \\|" << endl;
	
	dibujo();
			
	cout << "Palabra: " << palabra2 << endl;
	system("pause");
	return;
}

void dibujo(){
	switch(vida){
		case 6:
			cout << "  ----------" << endl;
			cout << "  |        |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << " ---" << endl;
			break;
		
		case 5:
			cout << "  ----------" << endl;
			cout << "  |        |" << endl;
			cout << "  |        O" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << " ---" << endl;
			break;
		
		case 4:
			cout << "  ----------" << endl;
			cout << "  |        |" << endl;
			cout << "  |        O" << endl;
			cout << "  |        |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << " ---" << endl;
			break;
		
		case 3:
			cout << "  ----------" << endl;
			cout << "  |        |" << endl;
			cout << "  |        O" << endl;
			cout << "  |       /|" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << " ---" << endl;
			break;
		
		case 2:
			cout << "  ----------" << endl;
			cout << "  |        |" << endl;
			cout << "  |        O" << endl;
			cout << "  |       /|\\" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << " ---" << endl;
			break;
		
		case 1:
			cout << "  ----------" << endl;
			cout << "  |        |" << endl;
			cout << "  |        O" << endl;
			cout << "  |       /|\\" << endl;
			cout << "  |       /" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << " ---" << endl;
			break;
		
		case 0:
			cout << "  ----------" << endl;
			cout << "  |        |" << endl;
			cout << "  |        O" << endl;
			cout << "  |       /|\\" << endl;
			cout << "  |       / \\" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << " ---" << endl;
			break;
	}
}