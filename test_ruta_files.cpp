#include <iostream>
#include <direct.h>

using namespace std;

int main()
{
    char path[500];
    _getcwd(path, 500);

    cout << "Carpeta de ejecucion: " << path << endl;

    FILE* f = fopen("test_text.txt", "w+b");
    fclose(f);

    return 0;
}