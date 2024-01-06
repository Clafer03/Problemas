#include <iostream>
#include <vector>
#include <ctype.h>
#include <cstdlib>
using namespace std;


// Usted debe escribir un programa que toma una lista de cadenas que contienen números enteros y
// palabras y devuelve una versión ordenada de la lista. La salida debe mantener las posiciones de Strings
// y números como aparecieron en la cadena original (Véase el ejemplo 4 abajo).
// El objetivo es ordenar esta lista de manera tal que todas las palabras terminen en orden alfabético, y
// todos los enteros terminen en orden numérico. Por otra parte, si el elemento enésimo en la lista es un
// número entero debe seguir siendo un entero, y si se trata de una palabra que debe seguir siendo una
// palabra.

// Input:
// El Input contendrá una sola (posiblemente vacía) línea que contiene una lista separada por espacios de
// Strings para ordenarse. Las palabras no contienen espacios, contendrán sólo las letras minúsculas az.
// Los enteros estarán en el rango [999.999, 999.999]. La línea será como máximo de 1000 caracteres de
// longitud.

// Output:
// El output debe ser la lista de cadenas, ordenados por los requisitos anteriores. Los Strings deben estar
// separados por un solo espacio, sin espacio al principio de la línea o final de la línea.

// Restricciones:

// El código que usted envíe debe tomar la entrada de la entrada estándar (stdin) y producir una salida a la
// salida estándar (stdout) como se especifica anteriormente. No se permite ninguna otra salida. Se puede
// suponer la entrada será válida. Siéntase libre de utilizar las bibliotecas estándar para ayudar en la
// clasificación.
// En los siguientes ejemplos, el texto "Input:" y "Output" no son parte de el Ouput esperado, y tampoco
// lo son las líneas en blanco.                                                                                   
//Ejemplo 1:
// Input:
// 1
// Output:
// 1

// Ejemplo 2:
// Input:
// car truck bus
// Output:
// bus car truck

// Ejemplo 3:
// Input:
// 8 4 6 1 2 9 5
// Output:
// 2 1 4 5 6 8 9

// Ejemplo 4:
// Input:
// car truck 8 4 bus 6 1
// Output:
// bus car 1 4 truck 6 8

/*
car truck 8 4 bus 6 1
---
Separar las palabras
car truck bus
8 4 6 1
---
Llenar las palabras en arreglos y ordenarlos 
strArr[] -> bus car truck
numArr[] -> 1 4 6 8
---
Rellenar la cadena nuevamente según el tipo de dato dado 
(1)
for (?)
    if string : fill -> bus 
||
(2)
fillFunc()
    while string : fill -> str str num num str num num 
        bus car ... stop
        while num : fill -> str str num num str num num 
            1 4 ...stop
    fillFunc() (...?)
*/


int main()
{
    vector<string> numeros;
    vector<string> palabras;

    //char cadena[1000];
    string cadena;
    string numero;
    string palabra;

    cout << "->";
    //cin >> cadena;
    getline(cin,cadena,'\n'); // captura los espacios en blanco

    //cout << cadena << endl;

    for(int i = 0; i < cadena.length(); i++)
    {
        if(isalpha(cadena[i]))
        {
            palabra = palabra + cadena[i];
        }
        if((isalpha(cadena[i]) && cadena[i+1] == ' ') || (isalpha(cadena[i]) && cadena[i+1] == '\0'))
        {
            palabras.push_back(palabra);
            palabra = " ";
        }

        if(isdigit(cadena[i]))
        {
            numero = numero + cadena[i];
        }
        if((isdigit(cadena[i]) && cadena[i+1] == ' ') || (isdigit(cadena[i]) && cadena[i+1] == '\0'))
        {
            numeros.push_back(numero);
            numero = " ";
        }
    }

    for(int i = 0; i < palabras.size(); i++)
    {
        cout << palabras[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < numeros.size(); i++)
    {
        cout << numeros[i] << ' ';
    }
}




// if(cadena[i] == ' ')
        // {
        //     int k = 0;
        //     k = i - 1;
        //     for(int j = 0; j < i; j++)
        //     {
        //         if(isalpha(cadena[j]))
        //         {
        //             palabras.push_back(cadena[j]);
        //         }
        //         else{
        //             numeros.push_back((int)cadena[j]);
        //         }
        //     }
        //}

         // if(isalpha(cadena[i]) && cadena[i+1] == ' ')
        // {
        //     palabras.push_back(" ");
        // }
        
        // if(isdigit(cadena[i]))
        // {
        //     numeros.push_back(cadena[i]);
        // }

        // if(isalpha(cadena[i]) && cadena[i+1] == ' ')
        // {
        //     palabras.push_back(' ');
        // }
        // if(isdigit(cadena[i]) && cadena[i+1] == ' ')
        // {
        //     numeros.push_back(' ');
        // }
