#include<iostream>
#include<malloc.h>
using namespace std;
struct Producto {
    int id;
    char nombre[40];
    struct Producto* siguiente;
};
// termino bloque de declarar lo que tiene Producto
struct Producto *princ,*bus,*agg;

void Agregar() {
    int numero;
    agg=(struct Producto *) malloc (sizeof(struct Producto));
        cout << "\nPor favor ingrese el id que desea: ";
        cin >> numero;
        if(princ!=NULL){
            bus=princ;
            while(bus!=NULL){
            if(bus->id==numero){
                cout<<"\n (•‿•) no se puede hacer (•‿•) \n";
                free(bus);
                free(agg);
                return;
            }
            bus=bus->siguiente;
        }
free(bus);
    }
       
        agg->id=numero;
        cout << "\nPor favor ingrese el Nombre que desea: ";
        cin.ignore();
        cin.getline(agg->nombre,40);
        if(princ==NULL){
        princ=agg;
        princ->siguiente=NULL;
        
        }else{
            agg->siguiente=princ;
            princ=agg;
           
        }
        agg=NULL;
    free(agg);
 
    cout << "\n Producto agregado correctamente -_- \n";
}

// termino bloque de codigo

int Mostrar(){
    if(princ==NULL){

cout<<"\n vacido Gracia a Dios ^_^ \n";

    }else{

    for(bus=princ;bus!=NULL;bus=bus->siguiente){

    cout<<"su id es: "<<bus->id<<"\n"<<"su nombre: "<<bus->nombre<<"\n";

    }
  }
    return 0;
}

// termino bloque de codigo

int Buscar() {
    if (princ == NULL) {
        cout << "\nNo se puede realizar la busqueda *'_'*\n";
        return 0;
    }

    int buscar;
    cout << "\nIngrese el ID que desea buscar: ";
    cin >> buscar;

    bus = princ;
    bool encontrado = false;

    while (bus != NULL) {
        if (buscar == bus->id) {
            cout << "\nID encontrado: " << bus->id << "\nNombre: " << bus->nombre << "\n";
            encontrado = true;
            break; // Detener la búsqueda si se encuentra el producto
        }
        bus = bus->siguiente;
    }
//forma abrebiada que encontre fue (!encontrado)
    if (encontrado==false) {
        cout << "\nNo se ha encontrado el producto con ese ID.\n";
    }

    return 0;
}

// termino bloque de codigo

void Eliminar() {
    if (princ == NULL) {
        cout << "\nNo hay productos registrados.\n";
        return;
    }

    int numero;
    cout << "\nIngrese el ID del producto a eliminar: ";
    cin >> numero;
    
  struct Producto *auxbor=princ, *auxatras = NULL;

    while (auxbor != NULL) {
        if (auxbor->id == numero) {  
            // Si es el primer nodo de la lista
            if (auxatras == NULL) {
                princ = auxbor->siguiente;
            } else {
                auxatras->siguiente = auxbor->siguiente;
            }
            
            free(auxbor);  // Liberar la memoria correctamente
            cout << "\nProducto eliminado correctamente.\n";
            return;
        }
        auxatras = auxbor;
        auxbor = auxbor->siguiente;
    }

    cout << "\nProducto no encontrado.\n";
}

//termino bloque de codigo

int Contar(){
    int contador =0;
    if (princ==NULL){
        cout<<"\n ;--no se ah encontrado Producto para hacer el conteo ;) "<<contador<<"\n";
        return 0;
    }else{ 
    for(bus=princ; bus!=NULL; bus=bus->siguiente){
        contador++;
        } 
    }
return cout<<"\n El numero de Producto son: "<<contador<<"\n",0;
}

// termino bloque de codigo

void Modificar(){
    if (princ == NULL) {
        cout << "\n:--No ha creado nada en estos momentos para modoficar:)\n";
        return;
    }
    bus=princ;
    int numero;
    cout<<"ingrese el ID ";cin>>numero;
    
while(bus!=NULL){
    if(bus->id==numero){
        bus->id=numero;
        char nombre='n';
        cout<<"De sea cambiar el nombre s or n: ";
        cin>>nombre;
        if (nombre =='s' or nombre == 'S' ){
            cout<<"ingresa el nuevo: ";cin.ignore(); cin.getline(bus->nombre,40);
        }else if (nombre!='n' || nombre== 'N' ){
        cout<<" por fabor cuida el sistema";
        }else{
            cout<<"\n Vale entiendo \n";
        }
       
        cout<<"\nse hizo el cambio correcto\n";
        break;
    }
    bus=bus->siguiente;
}
}

//termino bloque de codigo

void salir(){
    if(princ!=NULL){
        struct Producto *liberar;
while (princ!=NULL){
    liberar=princ;
    princ=princ->siguiente;
    free(liberar);
}
liberar=NULL;
free(liberar);
    }
    princ=NULL;
    free(princ);
    bus=NULL;
    free(bus);
    agg=NULL;
    free(agg);
}
//termino bloque de codigo

int main(){
    int ocp;
    do{
        cout<<"\t***TEAM WAWAWA**\n \t*\t*G*TT*G*TT*\n\n Selecione su opcion:\n 0.Salir\n 1.Agregar producto \n 2.Mostrar productos \n 3.Buscar producto \n 4.Eliminar producto \n 5.Contar productos \n 6.Modificar productos \n 7.Reclamos\n digite aqui por fabor: ";
        cin>>ocp;
        switch(ocp){
            case 0: salir();cout<<"\n\tEspero que lleves una experiencia agradable hasta la proxima\n"; system("pause");break;
            case 1:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#1\n"; Agregar();   system("pause");system("cls");break;
            case 2:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#2\n"; Mostrar();   system("pause");system("cls");break;
            case 3:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#3\n"; Buscar();    system("pause");system("cls");break;
            case 4:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#4\n"; Eliminar();  system("pause");system("cls");break;
            case 5:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#5\n"; Contar();    system("pause");system("cls");break;
            case 6:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#6\n"; Modificar(); system("pause");system("cls");break;
            case 7:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#7\n"; cout<<"solicitu en proceso\n";system("pause");system("cls");break;
            default: cout<<"\n): !!Lo sentimos pero fijate o ah tu peticon para proxima mejora a actualizar :) \n";system("pause");system("cls");break;
        } 
            }while(ocp!=0);
        system("cls");
    return 0;
}