#!/bin/sh

if [ -z "$1" ]
then TIMEOUT="0"
else TIMEOUT="$1"
fi

TMPFILE="$(mktemp -q -t "$(basename "$0")")"
exec 3<"$TMPFILE"
exec 4>"$TMPFILE"
rm -f "$TMPFILE"

HEIGHT=0
IFS="\n"
while read -r LINE
do
    WIDTH=0
    HEXLINE=$(printf "%s" "$LINE" | hexdump -v -e '1/1 "%.2x"')

    while [ -n "$HEXLINE" ]
    do
        REST="${HEXLINE#??}"
        SYMBOL="${HEXLINE%"$REST"}"

        printf "%u %u %s\n" $HEIGHT $WIDTH $SYMBOL >&4

        WIDTH=$((WIDTH + 1))
        HEXLINE=$REST
    done

    HEIGHT=$((HEIGHT + 1))
done

exec 4>&-
IFS=" "
tput clear
cat <&3 | shuf | while read -r HEIGHT WIDTH SYMBOL
do
    tput cup $HEIGHT $WIDTH
    printf "\\$(printf "%o" "0x$SYMBOL")"
    sleep $TIMEOUT
done
exec 3<&-

tput cup $(tput lines) $(tput cols)
while true
do
    sleep $TIMEOUT
done
