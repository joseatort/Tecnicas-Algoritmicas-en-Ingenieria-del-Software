
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>

using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "Problema.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
    int V;
    cin >> V;
   if (!std::cin)  // fin de la entrada
      return false;

   GrafoValorado<int> gv (V);

   int A;
   cin >> A;
   
   int u, v, valor;
   for (int i = 0; i < A; ++i) {
       cin >> u >> v >> valor;
       gv.ponArista({ u - 1, v - 1, valor });
   }
      
   // resolver el caso posiblemente llamando a otras funciones
   Camiones sol(gv);

   int C;
   cin >> C;

   int inicio, fin, tam;
   for (int i = 0; i < C; i++)
   {
       cin >> inicio >> fin >> tam;
       if (sol.consulta(inicio - 1, fin - 1, tam))
           cout << "SI\n";
       else
           cout << "NO\n";
   }

   // escribir la solución

   return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("1.in");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}