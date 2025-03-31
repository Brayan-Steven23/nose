#include<iostream>
/*#YEISON ANDRES CASTILLO RISACO<>*
*#CACERES MOSQUERA BRAYAN STEVEN<>*/
using namespace std;
struct Cliente {
    int id;
    char nombre[40];
    int edad;
    char g;
    char genero[10];
    char motivo[50];
    struct Cliente* siguiente;
};

// termino bloque de declarar lo que tiene Producto

struct Cliente *princ,*bus,*agg,*histo;
int m = 0, f = 0, diferencia = 0;

void Agregar_Cliente() {
    //estan son las locales que se usaron para el codigo y mas abajo ahi otra tambien que se nesecito
    char g;

    int numero, edad, sen = 1;
    char veri='n';
//hasta aqui listo no juega
///aqui empieza la magia jajaja
    do {
        //esto es breve cout mostrar cin guarda
        //preguntamos si es mayor en caso de que no pues la magia no fluye jajaja ahi vale ({´_´})
        cout << "Es mayor de edad (s/n): ";
        cin >> veri;
/// hacemos un if para saber que su año solo de espor ojo si lo tocas igual es importante segui la guia igual
        if (veri == 's' || veri == 'S') {
            int naci;
            cout << "Introduzca su fecha de nacimiento (Ej. 2010): ";
            cin >> naci;
// aqui miramos si su nacimiento esta entre 2008 y 1875 pues todavia no exite alguien que viva mas de 150aÑos
            if (naci < 2008 && naci > 1875) {
                cout << "Digite su edad: ";
                cin >> edad;
// ultima verificacion esta si es importante esta la pide el profe la edad la capturamos arriba listo
                if (edad >= 18) {
//aqui pedimos el id en caso que diga el profe que no es asi pues ponemos un contador y era
                    cout << "Ingrese el ID: ";
                    cin >> numero;
///esta parte va servir para hacer la busqueda del id que no se repita listo
                    bus = princ;
                    while (bus != NULL) {
                        if (bus->id == numero) {
                            cout << "ID repetido.\n";
                            free(agg);
                            return;
                        }
                        bus = bus->siguiente;
                    }
///aqui termina 
//aqui ya sabes su genero nada de lgtb no bulto ***Team wawawawa***
                    cout << "Digite su genero (M/F): ";
                    cin >> g;
                    agg = (struct Cliente *) malloc(sizeof(struct Cliente));

///haber aqui hacemos la diferencia, diferencia no me coje asi que por eso uso el or y la otra en fin me cojio sin IA
                    diferencia = m - f;
                    if ((g == 'F' || g == 'f') && (diferencia >= 4 || f >= 4)) {
                        cout << "No se permiten más Mujeres\n";
                        agg=NULL;
                        free(agg);
                        return;
                    } else if ((g == 'M' || g == 'm') && (diferencia <= -4 || m >= 4)) {
                        cout << "No se permiten mas Hombres\n";
                        agg=NULL;
                        free(agg);
                        return;
                    }
                ///termina qui esta parte del bloque
///este te va servir para darle genero listo sea mujer o hombre cero lgtb listo
                    if (g == 'F' || g == 'f') {
                        agg->g=g;
                        const char genero[6] = {'M', 'u', 'j', 'e', 'r', '\0'};
                        for (int i = 0; i < 6; i++) agg->genero[i] = genero[i];
                        f++;
                    } else if(g=='m' or g=='M') {
                        agg->g=g;
                        const char genero[10] = {'M', 'a', 's', 'c', 'u', 'l', 'i', 'n', 'o', '\0'};
                        for (int i = 0; i < 10; i++) agg->genero[i] = genero[i];
                        m++;
///ya sabes que si no se cumple ninguna de las primera entoces es por que digito algo que no es listo
                    }else{
                        cout<<"\n por fabor cuida el sistema '-(-'{'_'}-')-'\n";
                        agg=NULL;
                        free(agg);
                        return;
                    }
                    //termina aqui listo

///te acordad de lo de arriba bueno aqui empezamos hacer la aggregacion no te vas a enredar
                    agg->edad = edad;
                    agg->id = numero;
/// sin el ignore pues se jode esta m**r**d**
                    cout << "Ingrese el nombre: ";
                    cin.ignore();
                    cin.getline(agg->nombre,40);
                    
///aqui ya terminamos de capturar los datos de el
///aqui empieza la captura del motivo por el cual es ingresado
                    cout<<"Digite su motivo por el cual llega: ";
                    cin.getline(agg->motivo,50);
                    agg->siguiente=NULL;
                    ///termino de bloque 
//justamente aqui empezamos hacer la agg aunque siento que falta algo ois ahora vuelvo y miro el codigo viejo por que siento que falta algunos if
//bueno aqui si la cabeza esta basia entoces es null
if (princ == NULL) {
    princ = agg; // Si la lista está vacía, el nuevo nodo es la cabeza
} else {
    bus = princ;
    while (bus->siguiente != NULL) { // Buscar el último nodo
        bus = bus->siguiente;
    }
    bus->siguiente = agg; // Agregar el nuevo nodo al final
}


agg=NULL;
free(agg);
bus=NULL;
free(bus);

//ya aqui termina la magia
                    cout << "\nCliente agregado correctamente.\n";
/// como es algo canso salir y entrar entoces preguntamos 
                    char a;
                    cout << "Desea agregar otro ? (s/n): ";
                    cin >> a;
///solo imagina esto como un if esto se hace en c# y pense por que no un poco de diferente aqui aunque no es lo mejor casi no es legible
//en fin seria asi if(){}else if(){}else{}
                    (a == 's' || a == 'S') ? sen = 1 : (a == 'n' || a == 'N') ? sen = 0 : (cout << "Por favor cuidar el sistema", sen = 0);
                    if(sen==1){
                        cout<<"\nvamos una vez mas\n";
                        system("pause");
                        system("cls");
                    }
//segun lo que diga se sale o no ya que ahi esta la vaina que controla el while listo
// te acordas del if del inicio pues conta 2 bajando y este es la pareja listo o bueno es de la edad
                } else {
                    cout <<"Edad invalida.\n";
                    system("pause");
                    system("cls");
                }
///este es el de 2 listo en caso de la fecha 
            } else {
                cout <<"fecha de nacimiento fuera de rango.\n";
                system("pause");
                system("cls");
            }
    //ahora si aqui esta el de primer if si el da n hasta aqui fue fiel
        } else if (veri == 'n' || veri == 'N') {
            cout <<"Rechazado por edad.\n";
            system("pause");
            system("cls");
            sen = 0;
            ///aqui es en caso de que no ingrese una opcion valida ok
        } else {
            cout <<"Opcion no valida.\n";
            system("pause");
            system("cls");
        }
        ///final mente ya
    } while (sen != 0);
}

// termino bloque de codigo

int Mostrar_Cliente(){
    /*aui van a estar la lista de espera*/
    if(princ==NULL){
cout<<"\n vacido Gracia a Dios ^_^ \n";
    }
cout<<"\t \n **lista de Cliente** \n";
            for(bus=princ; bus!=NULL; bus=bus->siguiente){

                cout << "\nEl ID es: " << bus->id << "\nNombre del Cliente: " << bus->nombre << "\n"
                <<"la edad de el clientes es: "<<bus->edad<<"\n"<<"Genero del Cliente es: "<<bus->genero<<"\n"
                <<"motivo por el cual se ingreso: "<<bus->motivo<<"\n";
        
            }
        
        
    return 0;
}

// termino bloque de codigo

int AtenderCliente() {
    if (princ == NULL) {
        cout << "\nNo se puede realizar la busqueda no hay clientes.\n";
        return 0;
    }
    int s=1;
do{
    char a;
    cout << "Desea atender de forma manual o automatica en orden (M/A)?: ";
    cin >> a;
    

    // Modo Manual (M)
    if (a == 'm' || a == 'M') {
        int buscar;
        cout << "\nIngrese el ID del cliente que desea atender: ";
        cin >> buscar;

        bus = princ;
        struct Cliente *anterior = NULL;
        bool encontrado = false;

        while (bus != NULL) {
            if (buscar == bus->id) {
                cout << "\nCliente atendido:\n";
                cout << "ID: " << bus->id << "\nNombre: " << bus->nombre << "\n"
                     << "Edad: " << bus->edad << "\nGenero: " << bus->genero << "\n"
                     << "Motivo: " << bus->motivo << "\n";

                // Ajustar punteros para eliminar el nodo de la lista
                if (anterior == NULL) {
                    princ = bus->siguiente; // Nodo a eliminar es el primero
                } else {
                    anterior->siguiente = bus->siguiente;
                }

                // Actualizar contadores
                if (bus->g == 'f' || bus->g == 'F'){ f--;}
                else if (bus->g == 'm' || bus->g == 'M'){ m--;}

                // Mover a historial
                bus->siguiente = histo;
                histo = bus;

                encontrado = true;
                break;
            }

            anterior = bus;
            bus = bus->siguiente;
        }
        anterior = NULL;
        free(anterior);
// esta se puede ver mejor asi encontrado==falso;
        if (!encontrado) {
            cout << "\nNo se ha encontrado el Cliente con ese ID.\n";
        }
s=0;
    }
    // Modo Automático (A)
    else if (a == 'a' || a == 'A') {
       struct Cliente *atendido = princ;
        princ = princ->siguiente;

        // Mover a historial
        atendido->siguiente = histo;
        histo = atendido;

        // Actualizar contadores
        if (atendido->g == 'f' || atendido->g == 'F'){ f--;}
        else if (atendido->g == 'm' || atendido->g == 'M') {m--;}

        cout << "\nAtencion automatica completada:\n";
        cout << "ID: " << atendido->id << "\nNombre: " << atendido->nombre << "\n"
             << "Edad: " << atendido->edad << "\nGenero: " << atendido->genero << "\n"
             << "Motivo: " << atendido->motivo << "\n";
        atendido=NULL;
        free(atendido);   
s=0;  
    }
    else {
        cout << "\nOpcion no valida.\n"<<"Desea salir (Y/N); ";
        char d;
        cin>>d;
        d=tolower(d);
        if(d=='y'){
            s=0;
        }else if(d=='n'){
            cout << "\nvolvamos una vez mas\n";
        }else{
            cout << "\nOpcion no valida. chao\n";
            s=0;
        }

        system("pause");
        system("cls");
    }
}while(s!=0);
    return 0;
}


// termino bloque de codigo


int Historial_Cliente() {
    if (histo == NULL) {
        cout << "\nNo hay clientes atendidos.\n";
    } else {
        cout << "\n** Historial de Clientes Atendidos **\n";
        for (bus = histo; bus != NULL; bus = bus->siguiente) {
            cout << "\nID: " << bus->id << "\nNombre: " 
            << bus->nombre << "\nEdad: " << bus->edad 
            << "\nGenero: " << bus->genero << "\nMotivo: " 
            << bus->motivo << "\n";
        }
    }
    return 0;
}
//termino bloque de codigo

int Contar_Cliente(){
    int contador =0;
    if (princ==NULL){
        cout<<"\n ;--no se ah encontrado Clientes para hacer el conteo ;) "<<contador<<"\n";
        return 0;
    }else{ 
    for(bus=princ; bus!=NULL; bus=bus->siguiente){
        contador++;
        } 
    }
return cout<<"\n El numero de Cliente son: "<<contador<<"\n",0;
}

// termino bloque de codigo

void Modificar() {
    // Validar que haya un cliente en el historial
    if (histo == NULL) {
        cout << "No hay atencion para deshacer.\n";
        return;
    }

    // Extraer el primer nodo del historial
    struct Cliente *clienteDeshacer = histo;
    histo = histo->siguiente;

    // Reiniciar el cliente a la cola de atención
    clienteDeshacer->siguiente = NULL;

    // Si la cola está vacía, el cliente se convierte en la cabeza
    if (princ == NULL) {
        princ = clienteDeshacer;
    } else {
        // Buscar el último cliente en la cola
        bus = princ;
        while (bus->siguiente != NULL) {
            bus = bus->siguiente;
        }
        bus->siguiente = clienteDeshacer;
    }

    // Ajuste de contadores
    if (clienteDeshacer->g == 'f' || clienteDeshacer->g == 'F'){ f++;}
    else if (clienteDeshacer->g == 'm' || clienteDeshacer->g == 'M') {m++;}

    cout << "Atencion deshecha y cliente reintegrado a la cola.\n";
}


//termino bloque de codigo

void salir(){
    if(princ!=NULL){
        struct Cliente *liberar;
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
        cout<<"\t***TEAM WAWAWA**\n \t*\t*G*TT*G*TT*\n\n Selecione su opcion:\n 0.Salir\n 1.Agregar Clientes \n 2.Mostrar Clientes \n 3.Contar Clientes \n 4.Atender Clientes \n 5.Historial de Clientes \n 6.Deshacer ultima atencion Clientes \n 7.Reclamos\n digite aqui por fabor: ";
        cin>>ocp;
        switch(ocp){
            case 0: salir();cout<<"\n\tEspero que lleves una experiencia agradable hasta la proxima\n";    system("pause");break;
            case 1:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#1\n"; Agregar_Cliente();  system("pause");system("cls");break;
            case 2:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#2\n"; Mostrar_Cliente();  system("pause");system("cls");break;
            case 3:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#3\n"; Contar_Cliente();   system("pause");system("cls");break;
            case 4:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#4\n"; AtenderCliente();   system("pause");system("cls");break;
            case 5:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#5\n"; Historial_Cliente();system("pause");system("cls");break;
            case 6:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#6\n"; Modificar();        system("pause");system("cls");break;
            case 7:system("pause"); system("cls"); cout<<"\t Bienvenido a la opc#7\n"; cout<<"solicitu en proceso\n";system("pause");system("cls");break;
            default: cout<<"\n): !!Lo sentimos pero fijate o ah tu peticon para proxima mejora a actualizar :) \n";system("pause");system("cls");break;
        } 
            }while(ocp!=0);
        system("cls");
    return 0;
}