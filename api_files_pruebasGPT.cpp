#include <iostream>
#include "biblioteca/funciones/files.hpp"

using namespace std;

// C:\vscode\mingw\bin
// Ruta de donde se crean los archivos

int main()
{
    // =========================
    // 1) PRUEBA ARCHIVO BINARIO
    // =========================
    FILE* fb = fopen("test_bin.dat", "w+b");

    write<int>(fb, 100);
    write<int>(fb, 200);
    write<int>(fb, 300);

    cout << "fileSize<int>: " << fileSize<int>(fb) << endl; // 3
    cout << "filePos<int>: " << filePos<int>(fb) << endl;   // 3

    seek<int>(fb, 0);
    cout << "Luego de seek(0), filePos: " << filePos<int>(fb) << endl; // 0

    int a = read<int>(fb);
    cout << "Primer int: " << a << endl; // 100
    cout << "filePos despues de leer: " << filePos<int>(fb) << endl; // 1

    seek<int>(fb, 2);
    int b = read<int>(fb);
    cout << "Tercer int: " << b << endl; // 300

    fclose(fb);


    // =========================
    // 2) PRUEBA WRITE TEXTO
    // =========================
    FILE* ft = fopen("test_text.txt", "w+b");

    writeString(ft, "Hola");
    writeWord(ft, "Mundo");
    writeLine(ft, "Linea uno");
    writeLine(ft, ""); // linea vacia
    writeString(ft, "Ultima sin enter"); // extremo: no termina con '\n'

    fclose(ft);


    // =========================
    // 3) PRUEBA READLINE
    // =========================
    ft = fopen("test_text.txt", "r+b");

    cout << "\n--- readLine ---" << endl;

    string ln;
    bool hayLinea = readLine(ft, ln);

    while (hayLinea)
    {
        cout << "[" << ln << "]" << endl;
        hayLinea = readLine(ft, ln);
    }

    fclose(ft);


    // =========================
    // 4) PRUEBA READWORD NORMAL
    // =========================
    ft = fopen("test_text.txt", "r+b");

    cout << "\n--- readWord normal ---" << endl;

    string w;
    bool hayPalabra = readWord(ft, w);

    while (hayPalabra)
    {
        cout << "[" << w << "]" << endl;
        hayPalabra = readWord(ft, w);
    }

    fclose(ft);


    // =========================
    // 5) PRUEBA READWORD CON ALSOALLOWED
    // =========================
    FILE* fw = fopen("test_words.txt", "w+b");

    writeString(fw, "Juan Perez-2026 codigo_A1 ok? 99.5");

    fclose(fw);

    fw = fopen("test_words.txt", "r+b");

    cout << "\n--- readWord con alsoAllowed = \"-_\" ---" << endl;

    hayPalabra = readWord(fw, w, "-_");

    while (hayPalabra)
    {
        cout << "[" << w << "]" << endl;
        hayPalabra = readWord(fw, w, "-_");
    }

    fclose(fw);

    return 0;
}