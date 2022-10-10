#include <iostream>
#include <stdio.h>
#include <tuple>
#include <stdlib.h>
#include <time.h>
//funciones
void menu();
void generarLista();
void ordenarLista();
void ordenarMayor();
void ordenarMenor();
void busquedaSecuencial();
void busquedaBinaria();
//variables globales
int numerosDesordenados[100];
int numerosOrdenados[100];
int opcionEscogida;
//se que en este caso la tupla no es lo ideal pero estoy aprendiendo a usarlas y queria probarlas
std::tuple<std:: string, std:: string, std:: string, std:: string> menuOpciones;
std::tuple<std:: string, std:: string> opcionesOrdenamiento;
std::string opcionInvalida;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//tupla de las opciones del menu
	std::get<0>(menuOpciones) = "[OPCION 1] Generar lista de 100 numeros aleatorios";
	std::get<1>(menuOpciones) = "[OPCION 2] Ordenar la lista";
	std::get<2>(menuOpciones) = "[OPCION 3] Buscar un numero especifico de forma secuencial";
	std::get<3>(menuOpciones) = "[OPCION 4] Realizar busqueda binaria";
	//tupla de las opciones para ordenar
	std::get<0>(opcionesOrdenamiento) = "[OPCION 1] Ordenar de mayor a menor";
	std::get<1>(opcionesOrdenamiento) = "[OPCION 2] Ordenar de menor a mayor";
	//string default
	opcionInvalida = "[ADVERTENCIA] No ha escogido una opcion valida";
	// interfaz de inicio
	std::cout<<"//////////////////////////////////////////////PROGRAMA ACTIVIDAD 2//////////////////////////////////////////////"<<std::endl<<std::endl;
	std::cout<<"[INICIO] Bienvenido al programa la actividad complementaria 2 de la unidad 3"<<std::endl<<std::endl;
	std::cout<<"[INSTRUCCIONES] Digita el numero de la intruccion que desees realizar (recuerda iniciar por generar la lista ;])"<<std::endl;
	menu();
	
	return 0;
}

void menu (){		
	//interfaz del menu
	std::cout<<"------------------------------------------------------Menu-------------------------------------------------------"<<std::endl<<std::endl;
	//opciones del menu
	std::cout<<std::get<0>(menuOpciones)<<std::endl;
	std::cout<<std::get<1>(menuOpciones)<<std::endl;
	std::cout<<std::get<2>(menuOpciones)<<std::endl;
	std::cout<<std::get<3>(menuOpciones)<<std::endl<<std::endl;
	std::cin>>opcionEscogida;
	//switch para seleccionar las opciones
	switch (opcionEscogida){
		case 1:
			generarLista(); break;
		case 2:
			ordenarLista(); break;
		case 3:
			busquedaSecuencial(); break;
		case 4:
			busquedaBinaria(); break;
		default:
			std::cout<<opcionInvalida; menu(); break;	
	}
}

void generarLista(){
	std::cout<<std::endl<<std::endl;
	//interfaz de la generacion
	std::cout<<"---------------------------------------------Lista de Numeros desordenados-----------------------------------------"<<std::endl<<std::endl;
	//se generan 100 numeros aleatorios del 1 al 200 y se muestran en la terminal junto con la posicion que ocupan
	for(int i  = 0; i<100; i++){
		numerosDesordenados[i] =  (rand() % 200)+1;
		std::cout<<"Posicion "<<i + 1<<" Numero "<<	numerosDesordenados[i]<<std::endl;
	}
	std::cout<<std::endl<<std::endl;
	//se llama al menu principal
	menu();
}
void ordenarLista(){
	//variable de tipo a entero que funcionara como seleccionador de opciones
	int seleccion;
	//menu de ordenamiento
	std::cout<<"--------------------------------------------Ordenamiento de la lista---------------------------------------------"<<std::endl<<std::endl;
	//se comprueba si la lista no se genero validando si el ultimo numero es igual a 0
	if (numerosDesordenados[99] == 0){
		std::cout<<opcionInvalida<<std::endl<<std::endl; 
		std::cout<<"Debe iniciar escogiendo ''"<<std::get<0>(menuOpciones)<<"''"<<std::endl<<std::endl; 
		menu();
	} else {
		std::cout<<"[INSTRUCCIONES] Digita el numero de la instruccion que desees realizar"<<std::endl<<std::endl;
		std::cout<<std::get<0>(opcionesOrdenamiento)<<std::endl;
		std::cout<<std::get<1>(opcionesOrdenamiento)<<std::endl<<std::endl;
		std::cin>>seleccion;
		//switch del menu del seleccion	
		switch (seleccion){
			case 1:				
				ordenarMayor(); break;
			case 2:
				ordenarMenor();break;
			default:
				std::cout<<opcionInvalida<<std::endl; ordenarLista(); break;
		}
	}	
	
}
void ordenarMayor(){
	//variable auxiliar para almacenar temporalmente el valor que se desea intercambiar de lugar
	int y;
	std::cout<<"-----------------------------------Lista de numeros ordenados de mayor a menor----------------------------------"<<std::endl<<std::endl;
	//ciclo para llenar la lista de numeros ordeanados con los numeros generados
	for (int i = 0; i<100; i++){
		numerosOrdenados[i] = numerosDesordenados[i];
	}
	//ciclo para ordenar los numeros
	for (int i=0; i<100; i++){
		for (int j=0; j<100; j++){
			if (numerosOrdenados[j]<numerosOrdenados[j+1]){
				y = numerosOrdenados[j];
				numerosOrdenados[j] = numerosOrdenados[j+1];
				numerosOrdenados[j+1] = y;
			}
		}
	}
	//ciclo para imprimir la lista ya ordenada
	 for (int i=0; i<=99; i++) {
     std::cout<<"Nuevo lugar de la lista: "<<i+1<<" valor "<< numerosOrdenados[i]<<std::endl;
    }
    std::cout<<std::endl;
    menu();
    
}
void ordenarMenor(){
	//variable auxiliar para almacenar temporalmente el valor que se desea intercambiar de lugar
		int y;
	//interfaz de la lista de numeros ordenados de menor a mayor
	std::cout<<"-----------------------------------Lista de numeros ordenados de menor a mayor----------------------------------"<<std::endl<<std::endl;
	//ciclo para llenar la lista de numeros ordeanados con los numeros generados
	for (int i = 0; i<100; i++){
		numerosOrdenados[i] = numerosDesordenados[i];
	}
	//ciclo para ordenar los numeros
	for (int i=0; i<100; i++){
		for (int j=0; j<100; j++){
			if (numerosOrdenados[j]>numerosOrdenados[j+1]){
				y = numerosOrdenados[j];
				numerosOrdenados[j] = numerosOrdenados[j+1];
				numerosOrdenados[j+1] = y;
			}
		}
    }
    //ciclo para imprimir la lista ya ordenada
     for (int i=0; i<=99; i++) {
     std::cout<<"Nuevo lugar de la lista: "<<i+1<<" valor "<< numerosOrdenados[i]<<std::endl;
    }
    std::cout<<std::endl;
    menu();	
}


void busquedaSecuencial(){
	//variable donde se almacena el numero que queremos encontrar
	int numeroBuscado;
	//variable para escoger la lista
	int opcionListas;
	//variable de las veces que se repite el numero en la lista
	int frecuencia = 0;
	
	//interfaz de la busqueda secuencial
	std::cout<<"---------------------------------------------Busqueda secuencial------------------------------------------------"<<std::endl<<std::endl;
	//comprobamos si se generaron numeros
	if (numerosDesordenados[99] == 0){
		std::cout<<opcionInvalida<<std::endl<<std::endl; 
		std::cout<<"Debe iniciar escogiendo ''"<<std::get<0>(menuOpciones)<<"''"<<std::endl<<std::endl; 
		menu();
	} 
	
		//menu de la busqueda secuencial
		std::cout<<"[INSTRUCCIONES] Para escoger la lista en la que desea buscar digite el numero de esta"<<std::endl<<std::endl;
		std::cout<<"[1] Lista de numeros ordenados"<<std::endl;
		std::cout<<"[2] Lista de numeros desordenados"<<std::endl;
		//almacenamos la opcion escogida
		std::cin>>opcionListas;
		std::cout<<""<<std::endl;
		
	//como en esta ocasion no usamos un switch comprobamos la opcion escogida con if
		//comprobamos si se escogió una opcion valida
		if(opcionListas<1 || opcionListas>2){
			std::cout<<opcionInvalida;
			std::cout<<""<<std::endl<<std::endl;
			busquedaSecuencial();
		}	
		if (opcionListas == 1){	
		  //se comprueba si hay una lista de numeros ordenados
		  if (numerosOrdenados[99] != 0){
		  	//se pide el numero a buscar
		  	std::cout<<"[INSTRUCCIONES] Digite el numero que desea buscar"<<std::endl<<std::endl;
		  	//se almacena el numero a buscar
		  	std::cin>>numeroBuscado;
		  	std::cout<<""<<std::endl;
		  	//ciclo que cada que encuentra una concidencia imprime la pocision e incrementa la frecuencia en 1
		  	for(int i = 0; i < 100; i++){
				if (numerosOrdenados[i] == numeroBuscado){
				  		frecuencia += 1;	
						std::cout<<"Numero: "<<numeroBuscado<<" Encontrado en la posicion: "<<i<<" de la lista de numeros ordenados"<<std::endl;
				}
			}
			//se imprime las veces que el numero fue encontrado
			std::cout<<"El numero: "<<numeroBuscado<<" fue encontrado ["<<frecuencia<<"] veces en la lista ordenada"<<std::endl<<std::endl;
			menu();
		  } //en caso de no haber lista ordenada se le pide ordenarla
		  else {std::cout<<"[ADVERTENCIA] Primero necesitas ordenar la lista"<<std::endl; menu(); }	
		}
		
		if (opcionListas == 2){	
		//se pide el numero a buscar porque previamente se comprobo si hay una lista de numeros desordenados
		  	std::cout<<"[INSTRUCCIONES] Digite el numero que desea buscar"<<std::endl<<std::endl;
		  	//se almacena el numero a buscar
		  	std::cin>>numeroBuscado;
		  	std::cout<<""<<std::endl;
		  	//ciclo que cada que encuentra una concidencia imprime la pocision e incrementa la frecuencia en 1
		  	for(int i = 0; i < 100; i++){
				if (numerosDesordenados[i] == numeroBuscado){
				  		frecuencia += 1;	
						std::cout<<"Numero: "<<numeroBuscado<<" Encontrado en la posicion: "<<i+1<<" de la lista de numeros desordenados"<<std::endl;
				}
			}
			//se imprime las veces que el numero fue encontrado
			std::cout<<"El numero: "<<numeroBuscado<<" fue encontrado ["<<frecuencia<<"] veces en la lista ordenada"<<std::endl<<std::endl;
			menu();		
		}
}


void busquedaBinaria(){
	//variable del numero buscado
	int numeroBuscado;
	//variable boleana para notificar si no se encontro el valor
	bool encontrado = false;
	//variables de la lista ordenada ascendente
	int down, top;
	//variables de la lista ordenada descendente
	int down2, top2;
	//variable del valor de la mitad
	int m = 0;
	//variable auxiliar para valor repetido
	int y = 0;
	//comprobamos si hay una lista ordenada
	if (numerosOrdenados[99]==0){
	 std::cout<<"[ADVERTENCIA] Para esta opcion primero necesita ordenar los numeros"<<std::endl<<std::endl;
	 menu();
	}
	//comprobamos si se han generado los numeros aleatorios
	if (numerosDesordenados[99] == 0){
		std::cout<<opcionInvalida<<std::endl<<std::endl; 
		std::cout<<"Debe iniciar escogiendo ''"<<std::get<0>(menuOpciones)<<"''"<<std::endl<<std::endl; 
		menu();
	} 
	//se pide el numero a buscar porque previamente se comprobo si hay una lista de numeros desordenados
	std::cout<<"[INSTRUCCIONES] Digite el numero que desea buscar"<<std::endl<<std::endl;
	//se almacena el numero a buscar
	std::cin>>numeroBuscado;
	std::cout<<""<<std::endl;
	//se establecen los valores de las variables en la lista ordenada ascendente
	down = 0;
	top = 100;
	//se establecen los valores de las variables en la lista ordenada descendente
	down2=0;
	top2 =100;
	//ciclo while para la lista ascendente
	while(down <= top && encontrado == false){
		//se establece la mitad que siempre se establecera de la misma forma
		m = (down+top)/2;
	
		if(numerosOrdenados[m] == numeroBuscado){
			//si el numero en la posicion m corresponde al buscado se imprime que se encontro
			std::cout<<"El numero "<<numeroBuscado<<" fue encontrado"<<std::endl;
			encontrado = true;
			menu();
		}
		
		if (numerosOrdenados[m]>numeroBuscado){
			//si el numero en la posicion m es mayor al buscado el limite superior se vuelve igual a m
			top = m;
		}
		if(numerosOrdenados[m]<numeroBuscado){
			//si el numero en la posicion m es menor al buscado el limite inferior se vuelve igual a m
			down = m;
		}
		if(m == y){
		//si el valor de m es igual al del ciclo pasado significa que le valor no esta en la lista por eso se repite y se rompe el ciclo
			break;
		}
		//se almacena el valor final de m en este ciclo dentro de la variable auxiliar
		y = m;		
			
	}
	//se vuelve y igual a 0 para se utilizada en el ciclo siguiente
	y= 0;
	//ciclo while para la lista descendente
	while(down2 <= top2 && encontrado == false){
	
		if(numerosOrdenados[m] == numeroBuscado){
			//si el numero en la posicion m corresponde al buscado se imprime que se encontro y se llama al menu
			std::cout<<"El numero "<<numeroBuscado<<" fue encontrado"<<std::endl;
			encontrado = true;
			menu();
		}
		
		if (numerosOrdenados[m]<numeroBuscado){
			//si el numero en la posicion m es menor al buscado el limite superior se vuelve igual a m
			top2 = m;
			//si el numero en la posicion m es menor al buscado se resta el valor del limite inferior al del superior para ir bajando en la lista
			m = (top2-down2)/2;
		}
		if(numerosOrdenados[m]>numeroBuscado){
			//si el numero en la posicion m es mayor al buscado el limite inferior se vuelve igual a m
			down2 = m;
			//si el numero en la posicion m es mayor al buscado se suman los valores de ambos limites para ir subiendo en la lista
				m = (top2+down2)/2;
		}
		if(m == y){
			//si el valor de m es igual al del ciclo pasado significa que le valor no esta en la lista por eso se repite y se rompe el ciclo
			break;
		}
		//se almacena el valor final de m en este ciclo dentro de la variable auxiliar
		y = m;			
	}
	if(encontrado == false){
		//si la variable encontrado es igual a false se imprime que el valor no fue encontrado y se llama al menu
			std::cout<<"El numero: "<<numeroBuscado<<" no fue encontrado"<<std::endl<<std::endl;	
			menu();
	}
	
			
}

		




