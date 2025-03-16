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
/*void Agregar(){
    int g;
    //for()
     cout<<"\n Por fabor ingresar el id que desea: ";
        cin>>g;
    if(cab==NULL){
        cab = (struct Producto *) malloc (sizeof(struct Producto));
        cab->id=g;
      
        cab->nombre=g[40];/
        cab->siguiente=NULL;
         }else if(cab!=NULL){
            for(aux=cab; aux!=NULL; aux=aux->siguiente){
                if(g==aux->id){
                      cout<<"\nya esta registrado\n";
                }    }

}else if(){
                        aux = (struct Producto *) malloc (sizeof(struct Producto));
                        aux->id=g;
                        aux->siguiente=NULL;
                        cab->siguiente=aux;
                        aux=NULL;
                        free(aux);
                     cout<<"EL";
         }
}*/
void Agregar() {
    int numero;
    //string nombr;
    cout << "\nPor favor ingrese el id que desea: ";
    cin >> numero;
    


    bus=(struct Producto *) malloc (sizeof(struct Producto));
    bus=princ;
    while (bus != NULL) {
        if (bus->id == numero) {
            cout << "\nYa este registrado ^~^ \n";
            return; // Salimos de la función para no duplicar el ID
        }
        bus = bus->siguiente;
    }
    cout << "\nPor favor ingrese el nombre del Producto: ";
    // Crear un nuevo nodo
    agg=(struct Producto *)malloc(sizeof(Producto));
    if (agg == NULL) {
        cout << "\nError: No se pudo asignar memoria.\n";
        return;
    }
    cin.ignore();
    cin.getline(agg->nombre,40);
    agg->id = numero;
    agg->siguiente = NULL;

    // Insertar en la lista
    if (princ == NULL) {
        princ = agg; // Si la lista está vacía, el nuevo nodo es la cabeza
    } else {
        bus = princ;
        while (bus->siguiente != NULL) { // Buscar el último nodo
            bus = bus->siguiente;
        }
        bus->siguiente = agg; // Agregar el nuevo nodo al final
    }

    cout << "\nProducto agregado correctamente -_-\n";
}
// termino bloque de codigo

int Mostrar(){
    if(princ==NULL){
cout<<"\nvacido Gracia a Dios ^_^\n";
    }else{
    for(bus=princ; bus!=NULL; bus=bus->siguiente){
    cout<<"su id es: "<<bus->id<<"\n"<<"su nombre: "<<bus->nombre<<"\n";
    }
  }
    return 0;
}
// termino bloque de codigo
/*int Buscar(){ 


    bool encontrado = false;
    if(cab==NULL){
        cout<<"\nno a creado nada en estos momentos\n";
            }else{
                int b;
                cout<<"\ningrese el id que desea buscar:"; cin>>b;
            for(aux=cab; aux!=NULL; aux=aux->siguiente){
                if(b==aux->id){
            cout<<"\nsu id es: "<<aux->id<<"\n"<<"su nombre: "<<aux->nombre<<"\n";
            aux=aux2->siguiente=NULL;

            }else{
                 cout<<"\nno se ah encontrado\n";
            }
           
        }
        }

return 0;
}*/
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
        cout<<"cambiar ID: ";
        cin>>numero;
        bus->id=numero;
        char nombre='n';
        cout<<"De sea cambiar el nombre s or n: ";
        cin>>nombre;
        if (nombre =='s'){
            cout<<"ingresa el nuevo: ";cin.ignore(); cin.getline(bus->nombre,40);
        }else if (nombre!='n'){
        cout<<" por fabor cuida el sistema";
        }else{
            cout<<"\n entiendo \n";
        }
       
        cout<<"\nse hizo el cambio correcto\n";
        break;
    }
    bus=bus->siguiente;
}
}

//termino bloque de codigo

int main(){
    int ocp;
    do{
        cout<<"\t***TEAM WAWAWA**\n \t*\t*G*TT*G*TT*\n\n Selecione su opcion:\n 0.Salir\n 1.Agregar producto \n 2.Mostrar productos \n 3.Buscar producto \n 4.Eliminar producto \n 5.Contar productos \n 6.Modificar productos \n 7.Reclamos\n digite aqui por fabor: ";
        cin>>ocp;
        switch(ocp){
            case 0: cout<<"\n\tEspero que lleves una experiencia agradable hasta la proxima\n"; system("pause");break;
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
    return cout<<"\nsaludo desde la pricion\n",0;
}