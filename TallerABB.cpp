#include <iostream>
#include <locale.h>
using namespace std;

struct Pelicula{
    char nombre[100];
    int fecha=0;
    char genero;
	double dinero=0;
	struct Pelicula*iz;
	struct Pelicula*de;
};
 struct Pelicula *raiz,*bus,*aux;
 //struct Pelicula *bus;
 //struct Pelicula *aux;
 void llenadoRaiz(){
	if(bus->fecha<aux->fecha){
        if(bus->iz==nullptr){
            bus->iz=aux;
            return;
        }
        bus=bus->iz;
        llenadoRaiz();
    }else if(bus->fecha>aux->fecha){
        if(bus->de==nullptr){
            bus->de=aux;
            return;
        }
        bus=bus->de;
        llenadoRaiz();
    }
cout<<"\nerroe en posicionar\n";
 }
 void Agg(){
	int a=1;
    //char genero;
 if (raiz==nullptr){
 		raiz=(struct Pelicula *)malloc(sizeof(struct Pelicula));
 		cin.ignore();
        cout<<"\n Nombre De la Pelicula:";
		cin.getline(raiz->nombre,100);
        cout<<"\n Por Fabor Poner El Year: ";
        cin>>raiz->fecha;
        cout<<"\n Genero: T,S,A";
        cin>>raiz->genero;
        raiz->de=raiz->iz=nullptr;
        //if((genero=='t' or genero=='s')or(gene))
	}else if(raiz!=nullptr){
		a++;
		aux=(struct Pelicula *)malloc(sizeof(struct Pelicula));
		cout<<"\n vale por lo tanto este sera tu #"<<a<<" :\n ";
		cin.ignore();
        cout<<"\n Nombre De la Pelicula:";
		cin.getline(aux->nombre,100);
        cout<<"\n Por Fabor Poner El Year: ";
        cin>>aux->fecha;
        cout<<"\n Genero: T,S,A";
        cin>>aux->genero;
		aux->iz = aux->de = nullptr;
	bus=raiz;

	llenadoRaiz();
	}else{
		cout<<"\nError drastico\n";
	}
 }

 int corredor(struct Pelicula *bus2){
	cout<<"El valor es: "<<bus2->fecha<<"\n";
	if(bus2->iz!=NULL){
	
	corredor(bus2->iz);
	
	}
	if(bus2->de!=NULL){
	 
	corredor(bus2->de);
	}
	cout<<"\nfinalizo el recorrido#\n";
		return 0;
	}

int PreMostrar(){

	if(raiz==NULL){
        cout<<"\n No ahi que hacer mano\n";
        return 0;
    }else if(raiz!=NULL){
        
        corredor(raiz);
    }
 	return 0;
 }
 
 int buscarN(){
 	
 	
 	return 0;
 }
 
 int MostrarG(){
 	
 	return 0;
 }
 int Fracaso(){
 	
	 return 0;
 }
 

main(){
 int a=5;
 int b=0;
 do{
 	cout<<"\t \1 \3 GOTTY \6\6 GOTTY \3 \1 \n \t\t \5TEAM WAWAWA\5 \n 0.Agregar\1 \n 1.Mostrar\2 \n 2.Buscar Por Nombre\3 \n 3.Mostrar Pelicula Por Genero\4 \n 4.Peliculas Fracasadas\26 \n 5.salir\20 \n Digite su Opcion\6: ";cin>>a;
 	switch(a){
 	case 0: system("cls"); cout<<"\t Bienvenido Opcion Principal\1 \n"; Agg(); break;
 		
 	case 1: system("cls"); cout<<"\t Bienvenido Opcion#1\2 \n"; cout<<"\nen esta opcion ahi 3 forma de mostrar \n 1,preorden \n 2.Posorden \n 3.Inorden \n selecione opcion: "; cin>>b; switch(b){
		case 1: PreMostrar(); break;
		case 2:  break; 
		case 3:  break; 
		default: cout<<"no se reconoce"; break;
	}break;

	case 2: system("cls"); cout<<"\t Bienvenido Opcion#2\3 \n"; buscarN(); break;
 	
 	case 3: system("cls"); cout<<"\t Bienvenido Opcion#3\4 \n"; MostrarG(); break;
 	
 	case 4: system("cls"); cout<<"\t Bienvenido Opcion#4\5 \n"; Fracaso(); break;
 	
 	case 5: system("cls"); cout<<" Grasia \6 \n"; break;
 	
 	default:system("cls");cout<<"\7 No se encontro comando"; break;
 }
 system("pause");
 system("cls");
 
}while(a!=5);



}