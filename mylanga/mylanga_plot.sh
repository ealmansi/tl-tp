pushd `dirname $0` > /dev/null && SCRIPTPATH=`pwd` && popd > /dev/null
EXE=$SCRIPTPATH/bin/mylanga_parser
TMP_FILE=$(mktemp)

if (( $# != 2 )); then
    printf "Modo de uso:\n"
    printf "\t$0 <path/al/programa.my> <path/al/archivo_salida.png>\n"
    printf "\n"
    printf "Ejemplo: $0 mis_programas_mylanga/circulo.my donde/guardo/los/plots/circulo.png\n"
    exit 0
fi

cat $1 | $EXE > $TMP_FILE && \
  gnuplot -e "set nokey; set terminal png size 550,500 enhanced font 'Helvetica,12'; set output '$2'; plot '$TMP_FILE'" && \
  (eog $2 &)

rm -f $TMP_FILE