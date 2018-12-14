#! /bin/bash

inc_path=(\
    "/usr/lib/gcc/x86_64-linux-gnu/7/include/" \
    "/usr/local/include/" \
    "/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/" \
    "/usr/include/x86_64-linux-gnu/" \
    "/usr/include/")

i=1

if [ $# -eq 1 ]; then
    for v in "${inc_path[@]}"
    do
        echo "$i.$v"
        ls "$v" 2>/dev/null | grep "$1"
        let i++
    done
elif [ $# -eq 2 ]; then
    for v in "${inc_path[@]}"
    do
        echo "$i.$v$1/"
        ls "$v$1/" 2>/dev/null | grep "$2"
        let i++
    done
else
    for v in "${inc_path[@]}"
    do
        echo "$i.$v"
        let i++
    done
fi
