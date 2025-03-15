README.md
#include<iostream>
using namespace std;
struct Producto {
    int id;
    char nombre[30];
    struct Producto* siguiente;
};
// termino bloque de codigo
struct producto *cab,*aux,*aux2;
void Agregar(){
// termino bloque de codigo
} 
// termino bloque de codigo
int Mostrar(){
  
    return 0;
}
// termino bloque de codigo
int Buscar(){

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