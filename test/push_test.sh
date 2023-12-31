testps () {
    COUNT=$3
    LIMIT=$4
    ARG=`seq $COUNT | shuf | paste -sd " "`
    tot=`$1 $ARG | wc -l`
    check=`$1 $ARG | $2 $ARG`
    out=""
    if [ $check != "OK" ];
    then
        out="Checker: KO\n $ARG"
    else
        out="Checker: OK"
    fi
    if [ $tot -gt $LIMIT ];
    then
        echo -e "$out\nOver $LIMIT - Total: $tot - exceeded by: $(( $tot - $LIMIT )) - Args: $ARG"
    else
        echo -e "$out\nOK"
    fi
}

for i in {1..700000};
do
    testps $1 $2 $3 $4 &
done

wait
