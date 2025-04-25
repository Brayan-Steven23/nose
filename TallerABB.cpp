#include <iostream>
using namespace std;

struct Pelicula{
    char nombre[100];
    int fecha=0;
    char gener[50];
    char genero;
	double dinero=0;
	struct Pelicula*iz;
	struct Pelicula*de;
};
 struct Pelicula *raiz,*bus,*aux;
int contador;
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
    }else{
cout<<"\nerroe en posicionar\n";
 } 
}
 void Agg(){
	
contador++;

    //char genero;
 if (raiz==nullptr){
 		raiz=(struct Pelicula *)malloc(sizeof(struct Pelicula));
 		cin.ignore();
        cout<<"\n Nombre De la Pelicula:";
		cin.getline(raiz->nombre,100);
        cout<<"\n Por Fabor Poner El Year: ";
        cin>>raiz->fecha;
		int c=1;
		char g;
		do{
        cout<<"\n Genero: T=TERROR//S=SUSPENSO//A=ACCION";
		cin>>g;
		g=tolower(g);
		if(g=='t'){
			c=0;
			raiz->genero=g;
			const char gen[7]={'T','E','R','R','O','R','\0'};
			for(int i=0; i<7; i++){raiz->gener[i]=gen[i];}
			
		}else if(g=='s'){
			c=0;
			raiz->genero=g;
			const char gen[9]={'S','U','S','P','E','N','S','O','\0'};
			for(int i=0; i<9; i++){raiz->gener[i]=gen[i];}
		}else if(g=='a'){
			c=0;
			raiz->genero=g;
			const char gen[7]={'A','C','C','I','O','N','\0'};
			for(int i=0; i<7; i++){raiz->gener[i]=gen[i];}
		}else{
			cout<<"POR fabor elige unos de los genero o llamar para agg S/N";char p;cin>>p;
			p=tolower(p);
			if(p=='s'){
				cout<<"\nvamos a continuar\n";
			}else if(p=='n'){
				cout<<"\nListo entoces no podras hacer el registro\n";
				c=0;
				raiz=nullptr;
				free(raiz);
				return;
			}else{
				cout<<"\nCuidar el sistema es lo mas importante\n";
				c=0;
				raiz=nullptr;
				free(raiz);
				return;
			}
		}
		}while(c!=0);
        raiz->de=raiz->iz=nullptr;
        
	}else if(raiz!=nullptr){
		aux=(struct Pelicula *)malloc(sizeof(struct Pelicula));
		cout<<"\n Este sera tu #"<<contador<<" :\n ";
		cin.ignore();
        cout<<"\n Nombre De la Pelicula:";
		cin.getline(aux->nombre,100);
        cout<<"\n Por Fabor Poner El Year: ";
        cin>>aux->fecha;
		int c=1;
		char g;
		do{
        cout<<"\n Genero: T=TERROR//S=SUSPENSO//A=ACCION";
		cin>>g;
		g=tolower(g);
		if(g=='t'){
			c=0;
			raiz->genero=g;
			const char gen[7]={'T','E','R','R','O','R','\0'};
			for(int i=0; i<7; i++){raiz->gener[i]=gen[i];}
			
		}else if(g=='s'){
			c=0;
			raiz->genero=g;
			const char gen[9]={'S','U','S','P','E','N','S','O','\0'};
			for(int i=0; i<9; i++){raiz->gener[i]=gen[i];}
		}else if(g=='a'){
			c=0;
			raiz->genero=g;
			const char gen[7]={'A','C','C','I','O','N','\0'};
			for(int i=0; i<7; i++){raiz->gener[i]=gen[i];}
		}else{
			cout<<"POR fabor elige unos de los genero o llamar para agg S/N";char p;cin>>p;
			p=tolower(p);
			if(p=='s'){
				cout<<"\nvamos a continuar\n";
			}else if(p=='n'){
				cout<<"\nListo entoces no podras hacer el registro\n";
				c=0;
				contador--;
				aux=nullptr;
				free(aux);
				return;
			}else{
				contador--;
				cout<<"\nCuidar el sistema es lo mas importante\n";
				c=0;
				aux=nullptr;
				free(aux);
				return;
			}
		}
		}while(c!=0);
		aux->iz = aux->de = nullptr;
	bus=raiz;

	llenadoRaiz();
	}else{
		cout<<"\nError drastico\n";
	}
	cout<<"\nllenado Exelent\n";
 }

 int corredor(struct Pelicula *bus2){
	cout<<"La Fecha es: "<<bus2->fecha<<"// \n El Nombre es: "<<bus2->nombre<<"// \n El Dinero recaudado fue: "<<bus2->dinero
	<<"// \n El Genero es: "<<bus2->gener<<"// \n\n";
	if(bus2->iz!=NULL){
	corredor(bus2->iz);
	}
	if(bus2->de!=NULL){
	corredor(bus2->de);
	}
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
 
 int corredorin(struct Pelicula *bus2){
	if(bus2->iz!=NULL){
	corredor(bus2->iz);
	}cout<<"La Fecha es:// "<<bus2->fecha<<"\n El Nombre es: //"<<bus2->nombre<<"\n El Dinero recaudado fue: //"<<bus2->dinero
	<<"\n El Genero es: //"<<bus2->gener<<"\n\n";
	if(bus2->de!=NULL){
	corredor(bus2->de);
	}
	cout<<"La Fecha es:// "<<bus2->fecha<<"\n El Nombre es: //"<<bus2->nombre<<"\n El Dinero recaudado fue: //"<<bus2->dinero
	<<"\n El Genero es: //"<<bus2->gener<<"\n";
	
 return 0;
}

 int inorden(){
	if(raiz==nullptr){
        cout<<"\n No ahi que hacer mano\n";
        return 0;
	}else if(raiz!=nullptr) {
     corredorin(raiz);
	} 
	return 0;
 }

int poscorredor(struct Pelicula *bus2){
	if(bus2->iz!=NULL){
		corredor(bus2->iz);
		}
	if(bus2->de!=NULL){
		corredor(bus2->de);
		}
		cout<<"La Fecha es:// "<<bus2->fecha<<"\n El Nombre es: //"<<bus2->nombre<<"\n El Dinero recaudado fue: //"<<bus2->dinero
		<<"\n El Genero es: //"<<bus2->gener<<"\n\n";
	return 0;
}

int posorden(){
	if(raiz==nullptr){
        cout<<"\n No ahi que hacer mano\n";
        return 0;
	}else if(raiz!=nullptr) {
     poscorredor(raiz);
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
 		
 	case 1: system("cls"); do{cout<<"\t Bienvenido Opcion#1\2 \n"; cout<<"\n en esta opcion ahi 3 forma de mostrar \n 1.Preorden\5 \n 2.Inorden\3 \n 3.Posorden \n 4.salir \n selecione opcion: "; cin>>b; switch(b){
		case 1: system("cls"); cout<<"\t Bienvenido Opcio# Preorden\2 \n"; PreMostrar(); break;
		case 2: system("cls"); cout<<"\t Bienvenido Opcio# inorden\2 \n"; inorden(); break; 
		case 3: system("cls"); cout<<"\t Bienvenido Opcio# Posorden\2 \n"; posorden(); break; 
		case 4: cout<<"saliendo \n"; break;
		default: cout<<"\n no se reconoce \6\7 \n"; break;
		
	}
	system("pause");
	system("cls");
}while(b!=4);
break;

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