#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
using namespace std;
#include "lista.h"
#include "persona.h"


// UTILITY FUNCTIONS
// Function to print an LinkedList
void printArray(int A[], int size) { 
  for (auto i = 0; i < size; i++)
    cout << A[i] << " ";
}  

// Driver code
template <typename Persona>
int binarySerch(LinkedList<Persona> &listilla_bomnita, string busqueda, int l, int h) {
   if(h>=l){
   
    int mid = l + (h - l) / 2;

    Persona middValue = listilla_bomnita.get(mid);

    if(middValue.getLastName() == busqueda){
    
      return mid;
    }

    if (middValue.getLastName() > busqueda){
      return binarySerch(listilla_bomnita, busqueda, l, mid - 1);
    }

    else{
      return binarySerch(listilla_bomnita, busqueda, mid + 1, h);
    }
  }
   
    return -1;
}
template<typename Persona>
void merge(LinkedList<Persona>&lista, int low, int high, int mid)
{

  int n1 = high - low + 1;
  int n2 = mid - high;

  Persona L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = lista.get(low + i);
  for (int j = 0; j < n2; j++)
    M[j] = lista.get(high + 1 + j);

 
  int i, j, k;
  i = 0;
  j = 0;
  k = low;


  while (i < n1 && j < n2) {
    if (L[i] > M[j]) {
      lista.set(k,L[i]);
      i++;
    } else {
      lista.set(k,M[j]);
      j++;
    }
    k++;
  }

  while (i < n1) {
    lista.set(k,L[i]);
    i++;
    k++;
  }

  while (j < n2) {
    lista.set(k,M[j]);
    j++;
    k++;
  
  }
  return;
}


template<typename T>
void mergeSort(LinkedList<T> &lista, int low, int high)
 {
  if (low < high) {

    int m = low + (high - low) / 2;

    mergeSort<T>(lista, low, m);
    mergeSort<T>(lista, m + 1, high);
    merge<Persona>(lista, low, m, high);
  }

}


int main() {
  LinkedList<Persona> listilla_bomnita;
  ifstream archivo;             // O(1)
  archivo.open("bitacora.csv"); // O(1)
  string line;                  // O(1)
  getline(archivo, line);

  while (getline(archivo, line)) {

    string first_name, last_name, city, id, ZIP;
    // O(1)

    // getline(archivo, , , delimitador); //O(1)
    id = line.substr(0, line.find(','));
    line = line.substr(line.find(',') + 1, line.size());
    first_name = line.substr(0, line.find(','));
    line = line.substr(line.find(',') + 1, line.size());
    last_name = line.substr(0, line.find(','));
    line = line.substr(line.find(',') + 1, line.size());
    ZIP = line.substr(0, line.find(','));
    line = line.substr(line.find(',') + 1, line.size());
    city = line.substr(0, line.find(','));
    line = line.substr(line.find(',') + 1, line.size());

    stringstream ss;
    int id_;
    int zip_;
    ss << id;
    ss >> id_;
    stringstream ds;
    ds << ZIP;
    ds >> zip_;
    listilla_bomnita.addLast(Persona(id_, zip_, first_name, last_name, city));
    // Persona persona = Persona(id_,zip_,first_name,last_name,city);
    // listilla_bomnita.addLast(persona);
    // cout<<persona<<endl;
  }
  archivo.close();
  int opcion;
  cout << "Hola, bienvenido!" << endl;
  cout << "\n Escoge la pregunta que sea de tu agrado, nosotros te la "
          "responderemos :)"
       << endl;
  cout << "\n1. Las cinco ciudades más pobladas";
  cout << "\n2. ¿Con que frecuencia se repite un nombre?";
  cout << "\n3. La cantidad de habitantes en todas las ciudades";
  cout << "\n4.Ver la lista ligada ordenada por apellido";
  cout << "\n5. Búsqueda por apellido" << endl;

  cin >> opcion;

  if (opcion == 1) {
    // count por ciudad e imprimirlas
    cout << "5 Ciudades más pobladas  " << endl;
    LinkedList<string> cities;
    LinkedList<int> habit;
    string ciudadtemporal;

    for (int i = 0; i < listilla_bomnita.size(); i++) {
      ciudadtemporal = listilla_bomnita.get(i).getCity();
      if (cities.contains(ciudadtemporal)) {
        habit[cities.encuentra(ciudadtemporal)]++;

      }

      else {
        cities.addLast(ciudadtemporal);
        habit.addLast(1);
      }
    }

    int mayor = 0, indice_tempol = 0, poblacion;
    for (int i = 0; i < 5; i++) {
      mayor = habit[0];
      for (int j = 0; j < cities.size(); j++) {
        if (mayor < habit[j]) {
          mayor = habit[j];
          indice_tempol = j;
        }
      }
      ciudadtemporal = cities.remove(indice_tempol);
      poblacion = habit.remove(indice_tempol);
      cout << i + 1 << " " << ciudadtemporal << " " << poblacion << endl;
    }
    
  }
  

  else if (opcion == 2) {
    // Busqueda booleana, if == 'x' count +1
    string nombre;
    cout << "Inserta el nombre: ";
    cin >> nombre;
    int contador = 0;
    for (int i = 0; i < listilla_bomnita.size(); i++) {
      if (listilla_bomnita.get(i).getFirstName() == nombre) {
        contador += 1;
      }
    }
    cout << "El nombre '" << nombre << "' se repite " << contador << " veces"
         << endl;
  }
  

  else if (opcion == 3) {
    // imprime el count de habitantes de la ciudad
    string ciudad;
    LinkedList<string> cities;
    LinkedList<int> habit;
    string ciudadtemporal;
    /*cout << "Inserta la ciudad deseada" << endl;
    cin.clear();
    cin.ignore();
    getline(cin, ciudad);*/

    for (int i = 0; i < listilla_bomnita.size(); i++) {
      ciudadtemporal = listilla_bomnita.get(i).getCity();
      if (cities.contains(ciudadtemporal)) {
        habit[cities.encuentra(ciudadtemporal)]++;

      }

      else {
        cities.addLast(ciudadtemporal);
        habit.addLast(1);
      }
    }

    int mayor = 0, indice_tempol = 0, poblacion;
    for (int i = 0; i < cities.size(); i++) {
      mayor = habit[0];

      ciudadtemporal = cities.remove(indice_tempol);
      poblacion = habit.remove(indice_tempol);
      cout << i + 1 << " " << ciudadtemporal << " " << poblacion << endl;
    }
  }

  else if (opcion == 4) {
    mergeSort(listilla_bomnita, 0, listilla_bomnita.size() - 1);
    listilla_bomnita.print();

  }

  else if (opcion == 5) {
    string last_name_5;
    
    cout << "\nIngresa el apellido que deseas buscar: ";
    cin >> last_name_5;
    mergeSort(listilla_bomnita,0,listilla_bomnita.size() - 1);
    int size5 = listilla_bomnita.size();
    int result =  binarySerch(listilla_bomnita,last_name_5,0,size5-1);
    cout << listilla_bomnita.get(result) << endl;
    
    // if x == last name; cout << la persona que busca es tal
    /* string apellido;
     cout <<"Inserta un apellido"<<endl;
     cin>>apellido;*/

  }

  else {
    cout << "Inserta una opción válida papi" << endl;
  }

  cout << "finito" << endl;
}

/*
busqueda lineal desordenado
busqueda binaria oordenado

*/




