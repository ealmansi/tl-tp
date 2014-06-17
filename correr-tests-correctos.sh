pushd `dirname $0` > /dev/null && SCRIPTPATH=`pwd` && popd > /dev/null
TESTS_CODIGO=$SCRIPTPATH/tests/codigosDeCurvas
TESTS_PUNTOS=$SCRIPTPATH/tests/puntosObtenidos
TESTS_IMGS=$SCRIPTPATH/tests/imagenesObtenidas
EJECUTABLE=$SCRIPTPATH/mylanga/bin/mylanga_parser

rm -rf TESTS_PUNTOS/*
rm -rf TESTS_IMGS/*

for f in $TESTS_CODIGO/*.cod
do
  printf "Ejecutando $f...\n"
  
  filename=${f%.*}; filename=${filename##*/}
  OUT_FILE=$TESTS_PUNTOS/$filename.cod.out
  PNG_FILE=$TESTS_IMGS/$filename.png
  
  cat $f | $EJECUTABLE > $OUT_FILE && \
    gnuplot -e "set nokey; set terminal png size 550,500 enhanced font 'Helvetica,12'; set output '$PNG_FILE'; plot '$OUT_FILE' using 1:2 with lines"
done