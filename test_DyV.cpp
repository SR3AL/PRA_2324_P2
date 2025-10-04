#include <iostream>
#include <vector>
#include <chrono>
#include "DyV.h"
using namespace std;

int main(){
    srand(time(NULL));
    
    // Vectores para búsqueda
    vector<int> numeros_ordenados{1,2,3,4,5,6,7,8,9,10};
    vector<int> numeros_invertidos{10,9,8,7,6,5,4,3,2,1};
    
    int numero_buscar;
    cout << "Ingresa el numero que deseas buscar: ";
    cin >> numero_buscar;
    
    // Búsqueda en orden ascendente
    int resultado_asc = busquedaBinaria(numero_buscar, numeros_ordenados, 0, numeros_ordenados.size());
    if(resultado_asc != -1){
        cout << "Posicion(Busqueda Binaria Ascendente): " << resultado_asc << endl;
    } else {
        cout << "No se ha encontrado el numero." << endl;
    }
    
    // Búsqueda en orden descendente
    int resultado_desc = busquedaBinariaInversa(numero_buscar, numeros_invertidos, 0, numeros_invertidos.size());
    if(resultado_desc != -1){
        cout << "Posicion(Busqueda Binaria Descendente): " << resultado_desc << endl;
    } else {
        cout << "No se ha encontrado el numero." << endl;
    }
    
    cout << "\n=== ORDENAMIENTO CON QUICKSORT ===" << endl;
    
    // Vector mezclado original
    vector<int> v_random{3, 7, 1, 2, 4, 5, 9, 6, 8, 10};
    
    // Crear copias del vector mezclado para cada método
    vector<int> p_ultimo = v_random;
    vector<int> p_primero = v_random;
    vector<int> p_centro = v_random;
    vector<int> p_random = v_random;
    
    // QuickSort con pivote en ultima posición
    auto inicio = chrono::system_clock::now();
    QuickSort(p_ultimo, 0, p_ultimo.size() - 1);
    auto fin = chrono::system_clock::now();
    chrono::duration<float, milli> duracion = fin - inicio;
    
    cout << "\nQuickSort ult (pivote último): " << duracion.count() << " ms" << endl;
    cout << "Resultado: ";
    for(int j = 0; j < p_ultimo.size(); j++){
        cout << p_ultimo[j] << " ";
    }
    cout << endl;
    
    // QuickSort con pivote en primera posición
    inicio = chrono::system_clock::now();
    QuickSort_Primero(p_primero, 0, p_primero.size() - 1);
    fin = chrono::system_clock::now();
    duracion = fin - inicio;
    
    cout << "\nQuickSort (pivote primero): " << duracion.count() << " ms" << endl;
    cout << "Resultado: ";
    for(int j = 0; j < p_primero.size(); j++){
        cout << p_primero[j] << " ";
    }
    cout << endl;
    
    // QuickSort con pivote en el medio
    inicio = chrono::system_clock::now();
    QuickSort_Centro(p_centro, 0, p_centro.size() - 1);
    fin = chrono::system_clock::now();
    duracion = fin - inicio;
    
    cout << "\nQuickSort (pivote central): " << duracion.count() << " ms" << endl;
    cout << "Resultado: ";
    for(int j = 0; j < p_centro.size(); j++){
        cout << p_centro[j] << " ";
    }
    cout << endl;
    
    // QuickSort con pivote aleatorio
    inicio = chrono::system_clock::now();
    QuickSort_Random(p_random, 0, p_random.size() - 1);
    fin = chrono::system_clock::now();
    duracion = fin - inicio;
    
    cout << "\nQuickSort (pivote aleatorio): " << duracion.count() << " ms" << endl;
    cout << "Resultado: ";
    for(int j = 0; j < p_random.size(); j++){
        cout << p_random[j] << " ";
    }
    cout << endl;
    
    return 0;
}