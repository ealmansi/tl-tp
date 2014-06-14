#ifndef MYLANGA_ERROR_H
#define MYLANGA_ERROR_H

#include <cstdlib>
#include <string>
using namespace std;

#define MYLANGA_SYNTAX_ERROR(ln) ("Error sintáctico detectado en la línea " + to_string(ln))

#define MYLANGA_PARSE_ERROR "Error de parseo"

#define MYLANGA_RUNTIME_ERROR "Error en tiempo de ejecución"

#define MYLANGA_INTERNAL_ERROR() \
  do { cerr << "Error interno en la ejecución de mylanga." << endl; MYLANGA_END_ABRUPTLY(); } while (false);

#define MYLANGA_END_ABRUPTLY() \
  do { cerr << "Terminando la ejecución abruptamente ..." << endl; exit(-1); } while (false);

#endif /* MYLANGA_ERROR_H */