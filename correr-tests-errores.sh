pushd `dirname $0` > /dev/null && SCRIPTPATH=`pwd` && popd > /dev/null
TESTS_ERRORES=$SCRIPTPATH/tests/EjemplosDeErrores
EJECUTABLE=$SCRIPTPATH/mylanga/bin/mylanga_parser

for f in $TESTS_ERRORES/*.cod
do
  printf "Ejecutando $f...\n"
  cat $f | $EJECUTABLE > /dev/null
  printf "\n"
done