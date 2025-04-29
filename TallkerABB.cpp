#include <iostream>
#include <cstring> //o string.h // Para usar strcpy y strcmp toy boy jajajaj suave

using namespace std;

struct Pelicula {
    char nombre[100];
    int anio;
    char genero[50];
    char letra_genero;
    double dinero=0;
    struct Pelicula* iz;
    struct Pelicula* de;
};

struct Pelicula* raiz = nullptr;
int contador = 0;

void insertar(Pelicula*& nodo, Pelicula* nueva) {
    if (nodo == nullptr) {
        nodo = nueva;
    } else if (nueva->anio < nodo->anio) {
        insertar(nodo->iz, nueva);
    } else {
        insertar(nodo->de, nueva);
    }
}

void agregar() {
    struct Pelicula* nueva = (struct Pelicula*)malloc(sizeof(Pelicula));
    if (!nueva) {
        cout << "Error de memoria.\n";
        return;
    }

    cout << "\nNombre de la pelicula: ";
    cin.ignore();
    cin.getline(nueva->nombre, 100);

    cout << "Year de realizacion: ";
    cin >> nueva->anio;

    cout << "Dinero recaudado (en millones): ";
    cin >> nueva->dinero;
    char opcion;
int c=0;
    do{
    cout << "Genero (T: Terror, S: Suspenso, A: Accion): ";
    cin >> opcion;
    opcion = tolower(opcion);
    c=0;
    if (opcion == 't') {
        strcpy(nueva->genero, "TERROR");
    } else if (opcion == 's') {
        strcpy(nueva->genero, "SUSPENSO");
    } else if (opcion == 'a') {
        strcpy(nueva->genero, "ACCION");
    } else {
        cout << "Genero invalido.\nDesea volver(S/N)\n";char o;cin>>o;o=tolower(o);
        if(o=='s'){
            cout<<"\nOK Vamos\n";
        c=1;
        }else if(o=='n'){
            cout<<"\nLo siento no se realizo el llenado\n";
        free(nueva);
        return;
        }else{
            cout<<"\nCuida El Sistema Por Fabor\n\7";
        free(nueva);
        return;

        }
    }
    }while(c!=0);
    nueva->letra_genero = opcion;
    nueva->iz = nueva->de = nullptr;

    insertar(raiz, nueva);
    
    cout << "\nPelicula agregada con exito.\n";
}

// Recorridos
void preorden(struct Pelicula* nodo) {
    if (nodo == nullptr){return;}
    cout << "Nombre: " << nodo->nombre << ", Year: " << nodo->anio
         << ", Genero: " << nodo->genero << ", Dinero: $" << nodo->dinero << "M\n";
    preorden(nodo->iz);
    preorden(nodo->de);
}

void inorden(struct Pelicula* nodo) {
    if (nodo == nullptr){return;}
    inorden(nodo->iz);
    cout << "Nombre: " << nodo->nombre << ", Year: " << nodo->anio
         << ", Genero: " << nodo->genero << ", Dinero: $" << nodo->dinero << "M\n";
    inorden(nodo->de);
}

void posorden(struct Pelicula* nodo) {
    if (nodo == nullptr) {return;}
    posorden(nodo->iz);
    posorden(nodo->de);
    cout << "Nombre: " << nodo->nombre << ", Year: " << nodo->anio
         << ", Genero: " << nodo->genero << ", Dinero: $" << nodo->dinero << "M\n";
}

// Buscar pelicula por nombre
void buscar_nombre(struct Pelicula* nodo, const char* nombre) {
    if (nodo == nullptr) {return;}
    if (strcmp(nodo->nombre, nombre) == 0) {
        cout << "\nEncontrado: " << nodo->nombre << ", Year: " << nodo->anio
             << ", Genero: " << nodo->genero << ", Dinero: $" << nodo->dinero << "M\n";
        return;
    }
    buscar_nombre(nodo->iz, nombre);
    buscar_nombre(nodo->de, nombre);
}

// Mostrar peliculas de un genero
void buscar_genero(struct Pelicula* nodo, char genero) {
    if (nodo == nullptr) {return;}
    buscar_genero(nodo->iz, genero);
    if (nodo->letra_genero == genero) {
        cout << "Nombre: " << nodo->nombre << ", Year: " << nodo->anio
             << ", Genero: " << nodo->genero << ", Dinero: $" << nodo->dinero << "M\n";
    }
    buscar_genero(nodo->de, genero);
}

// Mostrar 3 peliculas fracasadas (menor dinero recaudado)
void buscar_fracasos(struct Pelicula* nodo, Pelicula* lista[], int &n) {
    if (nodo == nullptr) {return;}
    buscar_fracasos(nodo->iz, lista, n);
    if (n < 3) {
        lista[n++] = nodo;
    } else {
        // Buscar la de mayor dinero entre los 3 fracasos
        int idx_mayor = 0;
        for (int i = 1; i < 3; ++i) {
            if (lista[i]->dinero > lista[idx_mayor]->dinero) {
                idx_mayor = i;
            }
        }
        // Si el actual tiene menos dinero, reemplazar
        if (nodo->dinero < lista[idx_mayor]->dinero) {
            lista[idx_mayor] = nodo;
        }
    }
    buscar_fracasos(nodo->de, lista, n);
}

void mostrar_fracasos() {
    if(!raiz){return ;}
    struct Pelicula* fracasos[3] = {nullptr, nullptr, nullptr};
    int n = 0;
    buscar_fracasos(raiz, fracasos, n);

    cout << "\n--- Top 3 peliculas fracasadas ---\n";
    for (int i = 0; i < n; ++i) {
        cout << "Nombre: " << fracasos[i]->nombre << ", Year: " << fracasos[i]->anio
             << ", Dinero: $" << fracasos[i]->dinero << "M\n";
    }
}

// Liberar memoria 10pt
void liberar(Pelicula* nodo) {
    if (nodo == nullptr) {return;}
    liberar(nodo->iz);
    liberar(nodo->de);
    free(nodo);
}
// Menu principal descubri que se puede sin el int 
main() {
    int opcion;
    do {if(contador!=0){system("pause");}
    contador++;
        system("cls");
        cout << "\t\n---\1 \3 GOTTY \6\6 GOTTY \3 \1 \n \t \5TEAM WAWAWA\5---\n";
        cout << "0. Agregar pelicula\n";
        cout << "1. Mostrar peliculas\n";
        cout << "2. Buscar por genero\n";
        cout << "3. Buscar por nombre\n";
        cout << "4. Mostrar 3 fracasos\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 0:
            system("cls");
            cout<<"\t Bienvenido Opcion Principal\1 \n";
                agregar();
                break;
            case 1: {
                int c=0;
                do{
                    c=0;
                system("cls");
                cout<<"\t Bienvenido Opcion#1\2 \n";
                int tipo;
                cout << "\n Tenemos 3 Tipo: \n1. Preorden\n2. Inorden\n3. Posorden\n4. Salir\nTipo: ";
                cin >> tipo;
                if (tipo == 1) {preorden(raiz);
                }else if (tipo == 2){ inorden(raiz);
                }else if (tipo == 3){ posorden(raiz);
                }else if (tipo == 4){ cout<<"\nsaliendo\n";
                }else {cout << "Tipo invalido.\n";
                    cout << "\nDesea volver(S/N)\n";char o;cin>>o;o=tolower(o);
                    if(o=='s'){
                        cout<<"\nOK Vamos\n";
                    c=1;
                    }else if(o=='n'){
                        cout<<"\nLo siento no se realizo el recorrido\n";
                        system("pause");
                    system("cls");
                    break;
                    }else{
                        cout<<"\nCuida El Sistema Por Fabor\n\7";
                        system("pause");
                    system("cls");
                    break;}
                }
                }while(c!=0);
                break;
            }
            case 2: {
                system("cls");
                if(!raiz){ cout <<"\nNo esta la Raiz\n";break;}
                char g;
                cout << "\nIngrese genero (T/S/A): ";
                cin >> g;
                buscar_genero(raiz, tolower(g));
                break;
            }
            case 3: {
                system("cls");
                if(!raiz){ cout <<"\nNo esta la Raiz\n";break;}
                char nombre[100];
                cout << "\nIngrese nombre exacto: ";
                cin.ignore();
                cin.getline(nombre, 100);
                buscar_nombre(raiz, nombre);
                break;
            }
            case 4:system("cls");
                mostrar_fracasos();
                break;
            case 5:system("cls");
                liberar(raiz);
                cout << "Hasta luego.\n";
                break;
            default:
                cout << "\7Opcion invalida.\n";
                break;
        }
    } while (opcion != 5);
}