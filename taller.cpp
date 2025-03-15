#include<iostream>
#include <malloc.h>
using namespace std;
struct Producto {
    int id;
    char nombre[40];
    struct Producto* siguiente;
};
// termino bloque de codigo
struct Producto *cab,*aux,*aux2;
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
    int g;
    //string nombr;
    cout << "\nPor favor ingrese el id que desea:\n ";
    cin >> g;
    
    //getline(cin,nombr,'\n');
    // Verificar si el ID ya existe
    //Producto *aux = cab;
    aux=(struct Producto *) malloc (sizeof(struct Producto));
    aux=cab;
    while (aux != NULL) {
        if (aux->id == g) {
            cout << "\nYa este registrado\n";
            return; // Salimos de la función para no duplicar el ID
        }
        aux = aux->siguiente;
    }
    cout << "\nPor favor ingrese el nombre del Producto:\n ";
    // Crear un nuevo nodo
    aux2=(struct Producto *)malloc(sizeof(Producto));
    if (aux2 == NULL) {
        cout << "\nError: No se pudo asignar memoria.\n";
        return;
    }
    cin.ignore();
    cin.getline(aux2->nombre,40);
    aux2->id = g;
    aux2->siguiente = NULL;

    // Insertar en la lista
    if (cab == NULL) {
        cab = aux2; // Si la lista está vacía, el nuevo nodo es la cabeza
    } else {
        aux = cab;
        while (aux->siguiente != NULL) { // Buscar el último nodo
            aux = aux->siguiente;
        }
        aux->siguiente = aux2; // Agregar el nuevo nodo al final
    }

    cout << "\nProducto agregado correctamente.\n";
}
// termino bloque de codigo

int Mostrar(){
    if(cab==NULL){
cout<<"\nvacido Gracia a Dios\n";
    }else{
    for(aux=cab; aux!=NULL; aux=aux->siguiente){
    cout<<"su id es: "<<aux->id<<"\n"<<"su nombre: "<<aux->nombre<<"\n";
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
    if (cab == NULL) {
        cout << "\nNo ha creado nada en estos momentos.\n";
        return 0;
    }

    int b;
    cout << "\nIngrese el ID que desea buscar: ";
    cin >> b;

    aux = cab;
    bool encontrado = false;

    while (aux != NULL) {
        if (b == aux->id) {
            cout << "\nID encontrado: " << aux->id << "\nNombre: " << aux->nombre << "\n";
            encontrado = true;
            break; // Detener la búsqueda si se encuentra el producto
        }
        aux = aux->siguiente;
    }

    if (!encontrado) {
        cout << "\nNo se ha encontrado el producto con ese ID.\n";
    }

    return 0;
}

// termino bloque de codigo
void Eliminar(){

}
//termino bloque de codigo
int Contar(){

return 0;
}
// termino bloque de codigo
void Modificar(){

}
//termino bloque de codigo
int main(){
    int ocp;
    do{
        cout<<"\t *TEAM WAWAWA*\n \t \t G*TT*G*TT*\n\n Selecione su opcion:\n 0.Salir\n 1.Agregar producto \n 2.Mostrar productos \n 3.Buscar producto \n 4.Eliminar producto \n 5.Contar productos \n 6.Modificar productos \n 7.Reclamos\n digite aqui por fabor: ";
        cin>>ocp;
        switch(ocp){
            case 0: cout<<"\n\tEspero que lleves una experiencia agradable hasta la proxima\n"; break;
            case 1:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#1\n"; Agregar();   system("pause");system("cls");break;
            case 2:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#2\n"; Mostrar();   system("pause");system("cls"); break;
            case 3:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#3\n"; Buscar();    system("pause");system("cls");break;
            case 4:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#4\n"; Eliminar();  system("pause");system("cls");break;
            case 5:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#5\n"; Modificar(); system("pause");system("cls");break;
            case 6:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#6\n"; Contar(); system("pause");system("cls");break;
            case 7:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#7\n"; cout<<"solicitu en proceso\n";system("pause");system("cls");break;
            default: cout<<"\n): !!Lo sentimos pero fijate o ah tu peticon para proxima mejora a actualizar :) \n";system("pause");system("cls");break;
        } 
            }while(ocp!=0);
        
    return 0;
}