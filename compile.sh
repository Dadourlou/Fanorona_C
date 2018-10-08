#! /bin/sh
clear

un="1"
deux="2"
trois="3"
quatre="4"
cinq="5"

echo "Si vous voulez un tout petit plateau de taille HAUTEUR = 3 et LARGEUR = 5, tapez 1"
echo "Si vous voulez un petit plateau de taille HAUTEUR = 3 et LARGEUR = 7, tapez 2"
echo "Si vous voulez un plateau standard de taille HAUTEUR = 5 et LARGEUR = 9, tapez 3"
echo "Si vous voulez un grand plateau de taille HAUTEUR = 7 et LARGEUR = 13, tapez 4"
echo "Si vous voulez un plateau immense de taille HAUTEUR = 13 et LARGEUR = 17, tapez 5"

read taille

if [ $taille = $trois ]
then
  gcc -Wall code_final.c
  ./a.out
elif [ $taille = $un ]
then
  sed -i '5 s/5/3/ ;6 s/9/5/' code_final.c
  gcc -Wall code_final.c
  sed -i '5 s/3/5/ ;6 s/5/9/' code_final.c
  ./a.out
elif [ $taille = $deux ]
then
  sed -i '5 s/5/3/ ;6 s/9/7/' code_final.c
  gcc -Wall code_final.c
  sed -i '5 s/3/5/ ;6 s/7/9/' code_final.c
  ./a.out
elif [ $taille = $quatre ]
then
  sed -i '5 s/5/7/ ;6 s/9/13/' code_final.c
  gcc -Wall code_final.c
  sed -i '5 s/7/5/ ;6 s/13/9/' code_final.c
  ./a.out
elif [ $taille = $cinq ]
then
  sed -i '5 s/5/13/ ;6 s/9/17/' code_final.c
  gcc -Wall code_final.c
  sed -i '5 s/13/5/ ;6 s/17/9/' code_final.c
  ./a.out
fi
