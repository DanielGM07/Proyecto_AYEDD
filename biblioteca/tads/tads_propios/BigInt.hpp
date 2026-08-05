#include <iostream>

using std::string;

#include "../../funciones/strings.hpp"

// FINISHED // FINISHED // FINISHED // FINISHED // FINISHED // FINISHED

// 1.5.6. TAD BigInt
// Dificultad: intermedia, Requerido: recomendable.
// Desarrollar y probar el TAD BigInt de acuerdo con la estructura y especificaciones
// de las funciones que se describen a continuación.
// Nombre del TAD: BigInt. Archivo: BigInt.hpp
// Descripción: Representa números enteros muy grandes, sin restricciones de tamaño
// ni cantidad de dígitos.
// struct BigInt
// {
//  string s;
// };

// Prototipo: BigInt bigInt(string n);
// Descripción: Crea (o instancia) un BigInt.
// Parámetro: string n - Cadena que contiene la representación del número.
// Retorna: BigInt - Una instancia de BigInt lista para trabajar con el número n.

// Prototipo: BigInt bigIntSumar(BigInt a,BigInt b);
// Descripción: Retorna una instancia BigInt que contiene la suma de a y b.
// Parámetros:
// • BigInt a - Valor a sumar.
// • BigInt b - Valor a sumar.
// Retorna: BigInt - Una instancia de BigInt que contiene la suma de a y b.

// Prototipo: BigInt bigIntRestar(BigInt a,BigInt b);
// Descripción: Retorna una instancia BigInt que contiene la resta de a y b.
// Parámetros:
// • BigInt a - Minuendo.
// • BigInt b - Sustraendo.
// Retorna: BigInt - Una instancia de BigInt que contiene la resta de a menos b.

struct BigInt
{
    string s;
};

BigInt bigInt(string n){
    BigInt bInt;
    bInt.s = n;
    return bInt;
}

// Mmm... dijo la muda...
// void igualarDigitos(BigInt a, BigInt b){
//     string nroA = a.s;
//     string nroB = b.s; 
//     if(length(nroA) >= length(nroB)){
//         lpad(nroB, length(nroA), '0');
//     }else{
//         lpad(nroA, length(nroB), '0');
//     }
// }

void igualarDigitos(string &a, string &b){
    int largoA = length(a);
    int largoB = length(b);
    if(largoA >= largoB){
        b = lpad(b, largoA, '0');
    }else{
        a = lpad(a, largoB, '0');
    }
}

BigInt bigIntSumar(BigInt a, BigInt b){
    string nroA = a.s;
    string nroB = b.s;
    igualarDigitos(nroA, nroB);

    string sumaTotal = "";
    int sumaEntera = 0;
    int acarreo = 0;

    for(int i = length(nroA) - 1; i >= 0; i--){
        sumaEntera = charToInt(nroA[i]) + charToInt(nroB[i]) + acarreo;
        acarreo = 0;

        if(sumaEntera >= 10){
            sumaEntera = sumaEntera - 10;
            acarreo = 1;
        }
        sumaTotal = intToString(sumaEntera) + sumaTotal;
        sumaEntera = 0;

        if(i == 0 && acarreo == 1){
            sumaTotal = insertAt(sumaTotal, 0, '1');
        }
    }
    BigInt bIntRet;
    bIntRet.s = sumaTotal;
    return bIntRet;
}

BigInt bigIntRestar(BigInt a,BigInt b){
    string nroA = a.s;
    string nroB = b.s;

    string minuendo = "";
    string sustraendo = "";
    string diferencia = "";
    int diferenciaEntera = 0;
    int ayudita = 0;
    // CAPAZ QUE SUENA MAS INTUITIVO PRESTAMO EN VEZ DE AYUDITA
    // int prestamito = 0;
    string signo = "";

    igualarDigitos(nroA, nroB);
    if(nroA >= nroB){
        minuendo = nroA;
        sustraendo = nroB;
    }else{
        minuendo = nroB;
        sustraendo = nroA;
        signo = "-";
    }

    // for(int i = length(nroA) - 1; i >= 0; i--){
    //     // PRIMERA FORMA, ME SALIO MAL
    //     // if(minuendo[i] < sustraendo[i]){
    //     //     ayudita = 10;
    //     //     minuendo[i - 1] = intToChar(charToInt(minuendo[i - 1]) - 1);
    //     //     diferenciaEntera = (charToInt(minuendo[i]) + ayudita) - charToInt(sustraendo[i]);
    //     // }else{
    //     //     diferenciaEntera = charToInt(minuendo[i]) - charToInt(sustraendo[i]);
    //     // }


    // SEGUNDA FORMA, PENSANDOLO DE OTRA MANERA, SOBRE EL ERROR QUE COMETI ANTERIORMENTE, TAMBIEN ME SALIO MAL
    //     int j = 0;
    //     while(minuendo[i] < sustraendo[i]){
    //         j++;
    //         if(minuendo[i-j] >= 1){
    //             ayudita = 10;

    //             // Aca se deberia estar guardando una letra, pero nos importa el valor numerico
    //             minuendo[i] = intToChar(charToInt(minuendo[i]) + ayudita);
    //         }
    //     }
    //     for(j; j > 0; j--){
    //         minuendo[i-j] = intToChar(charToInt(minuendo[i-j]) - 1);
    //     }
    //     diferenciaEntera = charToInt(minuendo[i]) - charToInt(sustraendo[i]);
    //     diferencia = intToString(diferenciaEntera) + diferencia;
    //     ayudita = 0;
    // }

    // Finalmente se lo tuve que pedir a la IA :(, pero bueno, al menos lo entendi y era mas
    // simple de lo que lo estaba intentando
    // La IA no me comento nada (pero si me lo explico)
    // Asi que voy a proceder a comentarlo y explicarlo por mi mismo
    
    // El inicio hasta final del for se queda igual
    // El contador empieza en la ultima posicion de la cadena, que accedemos a ella
    // mediante el largo menos 1, que seria el primer digito del numero
    // Despues vamos bajando hasta llegar a cero, es decir, hasta el digito mas a la izquierda
    for(int i = length(nroA) - 1; i >= 0; i--)
    {
        // Por cada iteracion, vamos a asignar a una variable el valor de cada uno de los 
        // digitos que queremos restar, empezando desde la derecha de todo
        // Ademas, si el digito de la derecha, en la anterior iteracion, necesito una
        // "ayudita", quiere decir que le prestamos uno, por lo tanto en esta iteracion
        // ahora le restamos ese 1 al digito actual. Ej 20 - 01, el 0 necesito prestarse 1 del 2
        // entonces en la siguiente iteracion se le resta 1 al 2.
        // Es una obviedad pero por las dudas recalco que al prestarse 1, se le esta sumando 10
        // al digito de la derecha
        int digitoA = charToInt(minuendo[i]) - ayudita;
        // Tener en cuenta que digitoA va a poder ser negativo, si por ejemplo, tenemos 
        // 100 - 001, en la primera iteracion el primer cero queda como 10, y el segundo cero queda 
        // como -1

        // Aca simplemente nos paramos en la misma posicion del digito que le vamos a restar
        // a nuestro minuendo. Ej, tenemos 123 - 042, nos estamos parando en el 2 del 42 en
        // la primera iteracion, y en la segunda iteracion nos paramos en el 4
        int digitoB = charToInt(sustraendo[i]);

        // Chequeamos si el minuendo es menor que el sustraendo
        if(digitoA < digitoB)
        {
            // Si si es, se presta 1, lo que le va a sumar 10 al minuendo
            digitoA = digitoA + 10;

            // Entonces el prestamo (variable "ayudita") va a ser de 1
            // SIEMPRE QUE HAYA PRESTAMO VA A SER DE 1, NO MAS NI MENOS
            // (Por matematicas basicas, imaginense que tenemos el caso mas extremo
            // 0 - 9, el 0 se presta 1 y queda 10 - 9, prestarse 1 ya fue suficiente)
            ayudita = 1;
        }
        else
        {
            // En caso de que el minuendo no sea menor que el sustraendo,
            // no hace falta ayudita
            ayudita = 0;
        }

        // Calculamos la diferencia entre ambos numeros, y siempre va a quedar
        // un numero menor o igual a 9, el caso mas extremo seria: 8-9, el 8 se presta
        // 1 y queda como 18-9 lo que nos da 9. Ya si fuese 9-9, capaz si somos despistados 
        // pensamos que el minuendo se presta 10 y queda 19-9, pero al ser iguales se resta
        // y queda cero (muy boluda esta explicacion, pero es para dejar todo todo claro)
        diferenciaEntera = digitoA - digitoB;

        // Como nuestra diferencia siempre va a ser de un digito, siempre va a quedar un caracter
        // Aca usamos la funcion de strings.hpp intToString. Tambien podriamos usar intToChar, aunque
        // en este caso es indiferente
        diferencia = intToString(diferenciaEntera) + diferencia;
    }
    // Antes le aniadiamos el signo antes de quitar los ceros, lo que hacia que si un nro negativo
    // quedara con ceros, estos quedaban entre el signo negativo y el primer digito distinto de cero
    // BigInt bIntRet = bigInt(signo + diferencia);
    BigInt bIntRet = bigInt(diferencia);

    // Aca le aniadi que si la primera posicion de la diferencia es un cero (el digito
    // mas a la izquierda), la removemos, ya que, por ej. Tenemos 50000-49999, nos queda 
    // 00001, con el while siguiente nos queda 1
    // Ademas, puse una condicion mas, y es que si ese cero es el ultimo cero
    // (aunque en realidad evalua si el largo de la cadena es 1), entonces ya no borra el cero
    // y lo deja como resultado final. Ej 5000-5000 quedari nada, una cadena vacia, pero con 
    // esta segunda condicion queda un solo 0
    while(indexOf(bIntRet.s, '0') == 0 && length(bIntRet.s) > 1){
        bIntRet.s = removeAt(bIntRet.s, 0);
    }

    // Una vez que ya sacamos los ceros, le aniadimos el respectivo signo
    bIntRet.s = signo + bIntRet.s;
    return bIntRet;
}

// FINISHED TAD BIGINT (lastima que tuve que usar chat gpt para el for de resta pero LOGRE ENTENDERLO)
// FINISHED
// FINISHED
// FINISHED
// FINISHED