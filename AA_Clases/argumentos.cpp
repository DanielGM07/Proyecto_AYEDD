#include "../biblioteca/funciones/millis.hpp"
#include "../biblioteca/funciones/files.hpp"
#include "../biblioteca/funciones/strings.hpp"
#include "../biblioteca/funciones/tokens.hpp"

#include "../biblioteca/tads/parte1/Fecha.hpp"
#include "../biblioteca/tads/parte1/Timer.hpp"
#include "../biblioteca/tads/parte1/Coll.hpp"

#include "../biblioteca/tads/parte2/Array.hpp"
#include "../biblioteca/tads/parte2/List.hpp"
#include "../biblioteca/tads/parte2/Map.hpp"
#include "../biblioteca/tads/parte2/Queue.hpp"
#include "../biblioteca/tads/parte2/Stack.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

int main(int argc, char** argv)
{
    // argc siginfica argumento count, que es basicamente el largo
    // argv es el array de argumentos, significa argumento vector. Este contiene los argumentos que le pasamos

    for(int i = 1; i < argc; i++){
        string s = argv[i];
        cout << i << ": [ " << s << " ] " << endl;
    }
    
    return 0;
}