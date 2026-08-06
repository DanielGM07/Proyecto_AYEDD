#include <iostream>
#include <string>

#include "../../biblioteca/funciones/millis.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/intro/Fraccion.hpp"
#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte1/Timer.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"
#include "../../biblioteca/tads/tads_propios/BigInt.hpp"
#include "../../principal.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;


int main()
{
    // 1.5.6 TAD BigInt
    // FINISHED

    cout << "Ingrese dos numeros grande (BigInt): " << endl;
    string a = "", b = "";
    cin >> a >> b;
    BigInt bInt1 = bigInt(a);
    BigInt bInt2 = bigInt(b);
    
    cout << "SUMA: " << bigIntSumar(bInt1, bInt2).s << endl;

    cout << "RESTA: " << bigIntRestar(bInt1, bInt2).s << endl;
    return 0;
}