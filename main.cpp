#include <iostream>

using namespace std;

#include <stdlib.h>
#include "Trabajador.h"
#include "Lista.h"
#include "Nodo.h"

///PROGRAMACIÓN III - FREDY ALEXANDER CAMPOS FIGUEROA

int menu(){
    char op;
    cout << "MENU DE OPCIONES\n";
    cout << "\n\t1. Agregar trabajador\n";
    cout << "\t2. Eliminar trabajador\n";
    cout << "\t3. Modificar datos del trabajador\n";
    cout << "\t4. Mostrar planilla\n";
    cout << "\t5. Salir\n";
    cout << "\nDigite la opcion -> ";
    cin >> op;
    return op;
}

Trabajador *agregarTrabajador(){
    Trabajador *tb = NULL;
    int id;
    string n,a;
    float sm;
    cout << "\nDigite el id del trabajador : ";
    cin >> id;
    cout << "Digite el nombre : ";
    cin >> n;
    cout << "Digite el apellido : ";
    cin >> a;
    cout << "Digite el sueldo mensual : ";
    cin >> sm;

    tb = new Trabajador(id, n,a, sm);

    return tb;
}

Trabajador *modificarTrabajador(){
    Trabajador *tb = NULL;

    string n, a;
    float sm;

    cout << "Modifique los datos del trabajador : \n";
    cout << "\nDigite el nombre : ";
    cin >> n;
    cout << "Digite el apellido : ";
    cin >> a;
    cout << "Digite el sueldo mensual : ";
    cin >> sm;

    tb = new Trabajador(0, n, a, sm);

    return tb;
}

int main(){
    char opc, ord;
    int id;
    Lista planilla;
    Trabajador *tb;

    do{
        system("cls");
        opc = menu();
        switch (opc){
            case '1':
                ///AGREGAR TRABAJADOR
                system("cls");
                tb = agregarTrabajador();
                if (tb){
                    cout << "\nOrden de la lista de trabajadores : " << endl;
                    cout << "\t1. Al inicio \n";
                    cout << "\t2. Al medio antes \n";
                    cout << "\t3. Al medio despues \n";
                    cout << "\t4. Al final \n";
                    cout << "\n -> "; cin >> ord;
                    switch(ord){
                        case '1':
                            planilla.InsertarAlInicio(tb);
                            break;
                        case '2':
                            cout << "\nAntes de la ID : "; cin >> id;
                            planilla.InsertarEnMedioAntes(tb, id);
                            break;
                        case '3':
                            cout << "\nDespues de la ID : "; cin >> id;
                            planilla.InsertarEnMedioDespues(tb, id);
                            break;
                        case '4':
                            planilla.InsertarAlFinal(tb);
                            break;
                        default:
                            cout << "\nOpcion invalida, se añadira al final." << endl;
                            planilla.InsertarAlFinal(tb);
                            break;
                    }
                    cout << "\nEl trabajador se agrego con exito\n";
                }else{
                    cout << "\nEl trabajador no se agrego\n";
                }
                break;
            case '2':
                ///ELIMINAR TRABAJADOR
                system("cls");
                cout << "Digite la ID del cliente a eliminar : "; cin >> id;
                if(planilla.eliminarTrabajador(id)){
                    cout << "Trabajador eliminado con exito." << endl;
                }else{
                    cout << "No se ha podido eliminar el trabajador." << endl;
                }
                break;
            case '3':
                ///MODIFICAR DATOS DEL TRABAJADOR
                system("cls");
                cout << "Digite la ID del cliente a modificar : "; cin >> id;
                tb = modificarTrabajador();

                if(planilla.modificarTrabajador(tb, id)){
                    cout << "Se modifico el trabajador con ID " << id << " exitosamente! " << endl;
                }else{
                    cout << "No existe un trabajador con la ID " << id << " verificar. " << endl;
                }
                break;
            case '4':
                ///MOSTRAR PLANILLA
                planilla.Mostrar();
                break;
            case '5':

                break;
            default:
                cout << "Error, opcion no definida\n";
                break;
        }
        system("pause");
    }while (opc != '5');

    return 0;
}
