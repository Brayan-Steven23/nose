#include <iostream>
#include <malloc.h>
using namespace std;

struct nodo{
 int numero;
 nodo *sig;
};

struct nodo *prin,*seg,*crd;

void add(){
    int n;
    // Se reserva memoria para un nuevo nodo
    seg = (struct nodo *) malloc(sizeof(struct nodo));

    // Se verifica si la memoria fue asignada correctamente
    if (seg == NULL) {
        cout << "Error: no se pudo asignar memoria." << endl;
    }

    // Solicita al usuario el valor a guardar
    // hace una verificacion
    cout << "\n Registre el valor del nodo: ";
   if(!(cin >> n)){
    cout << "Error: Debes ingresar un numero valido.\n";
   }else{
    cout << "Ingresaste el numero: " << n << endl;
    seg->numero=n;
   }

    // El nuevo nodo apunta a NULL (fin de lista)
    seg->sig = NULL;

    // Si la lista está vacía, el nuevo nodo será la cabeza
    if (prin == NULL) {
        prin = seg;
    } else {
        // Se recorre la lista hasta el último nodo
        crd= prin;
        while (crd->sig != NULL) {
            crd = crd->sig;
        }
        // Se enlaza el nuevo nodo al final
        crd->sig = seg;
    }
    seg =  crd = NULL; // Se limpian los punteros auxiliares
    free(seg);          // Se libera la memoria de aux
    free(crd);   
}

void viewnodo(){
   int i=1;
   int id=200;
   if(prin == NULL){
    cout<<"\n nodo vacido Gracia a Dios\n";
   }
    for(seg=prin; seg!=NULL; seg=seg->sig){
        cout<<"\n numero ingresado#"<<i<<"\tsu id es: "<<id<<"\tdel nodo:"<< seg->numero<<"\n";
        i++;
        id++;
        }
    
}
int contador(){
    int contador = 0;
    
for(seg=prin; seg!=NULL; seg=seg->sig){
contador++;

}
return cout<<"estan: ",contador;
}

int promedio(){
return 0;
}
int nodomenor(){
return 0;
}

int main(){
 int ocp;
    do{
cout<<"\t *TEAM WAWAWA*\n \t \t G*TT*G*TT*\n\n Selecione su opcion:\n 0.Salir\n 1.Agraga\n 2.mostrar \n 3.Calcular promedio\n 4.Calcular nodo menores al digitado\n 5.mostra nodo pero sin numero \n 6.Reclamos\n digite aqui por fabor: ";
cin>>ocp;
switch(ocp){
    case 0: cout<<"\n\tEspero que lleves una experiencia agradable hasta la proxima\n"; break;
    case 1:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#1"; add(); system("pause");system("cls");break;
    case 2:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#2"; viewnodo(); system("pause");system("cls"); break;
    case 3: promedio();break;
    case 4: nodomenor();break;
    case 5:  contador(); system("pause");break;
    case 6:system("pause"); system("cls"); cout<<"solicitu en proceso\n";system("pause");system("cls");break;
    default: cout<<"\n): !!Lo sentimos pero fijate o ah tu peticon para proxima mejora a actualizar :) \n";system("pause");system("cls");break;
} 
    }while(ocp!=0);

    return 0;
}