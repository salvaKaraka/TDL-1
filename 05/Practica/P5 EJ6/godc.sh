#!/bin/bash
programa_nombre="$1"
gcc -o "$programa_nombre.exe" "$programa_nombre.c" && "./$programa_nombre.exe" && rm "$programa_nombre.exe"