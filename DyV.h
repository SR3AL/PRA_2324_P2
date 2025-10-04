#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// DyV - 1a Parte - Busqueda Binaria

//Busqueda Binaria Normal
template <typename T>

T busquedaBinaria(T X, vector<T>& V, int ini, int fin) {
    if (ini > fin) {
        return -1;
    }
    int medio = (ini + fin) / 2;
    if (V[medio] == X) {
        return medio;
    } else if (V[medio] > X) {
        return busquedaBinaria(X, V, ini, medio - 1);
    } else {
        return busquedaBinaria(X, V, medio + 1, fin);
    }
}

//Busqueda Binaria Inversa
template <typename T>

T busquedaBinariaInversa(T X, vector<T>& V, int ini, int fin) {
    if (ini > fin) {
        return -1;
    }
    int medio = (ini + fin) / 2;
    if (V[medio] == X) {
        return medio;
    } else if (V[medio] < X) {
        return busquedaBinariaInversa(X, V, ini, medio - 1);
    } else {
        return busquedaBinariaInversa(X, V, medio + 1, fin);
    }
}

// DyV - 2a Parte - QuickSort
template<typename T>
int Particion(vector<T>& vec, int inicio, int final){
    T pivote = vec[final];
    int indice = inicio;
    for(int k = inicio; k < final; k++){
        if(vec[k] <= pivote){
            swap(vec[indice], vec[k]);
            indice++;
        }
    }
    swap(vec[indice], vec[final]);
    return indice;
}

template <typename T>
void QuickSort(vector<T>& arr, int inicio, int final){
    if (inicio < final){
        int pos_pivote = Particion(arr, inicio, final);
        QuickSort(arr, inicio, pos_pivote - 1);
        QuickSort(arr, pos_pivote + 1, final);
    }
}

template <typename T>
void QuickSort_Primero(vector<T>& arr, int inicio, int final){
    if (inicio < final){
        swap(arr[inicio], arr[final]);
        int pos_pivote = Particion(arr, inicio, final);
        QuickSort_Primero(arr, inicio, pos_pivote - 1);
        QuickSort_Primero(arr, pos_pivote + 1, final);
    }
}

template <typename T>
void QuickSort_Centro(vector<T>& arr, int inicio, int final){
    if (inicio < final){
        int mitad = inicio + (final - inicio) / 2;
        swap(arr[mitad], arr[final]);
        int pos_pivote = Particion(arr, inicio, final);
        QuickSort_Centro(arr, inicio, pos_pivote - 1);
        QuickSort_Centro(arr, pos_pivote + 1, final);
    }
}

template <typename T>
void QuickSort_Random(vector<T>& arr, int inicio, int final){
    if (inicio < final){
        int aleatorio = inicio + rand() % (final - inicio + 1);
        swap(arr[aleatorio], arr[final]);
        int pos_pivote = Particion(arr, inicio, final);
        QuickSort_Random(arr, inicio, pos_pivote - 1);
        QuickSort_Random(arr, pos_pivote + 1, final);
    }
}