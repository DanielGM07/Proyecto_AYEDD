#include "../../biblioteca/funciones/millis.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/funciones/arrays.hpp"
#include "../../biblioteca/funciones/lists.hpp"
#include "../../biblioteca/tads/intro/Fraccion.hpp"
#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte1/Timer.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"
#include "../../biblioteca/tads/parte1/BitWriter.hpp"
#include "../../biblioteca/tads/parte1/BitReader.hpp"
#include "../../principal.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

int main(int argc, char** argv){
    cout << "Recibimos " << argc << " argumentos" << endl;
    for (int i = 0; i < argc; i++){
        cout << "Este es el argumento n " << i << ": " << argv[i] << endl;
    }
    return 0;
}