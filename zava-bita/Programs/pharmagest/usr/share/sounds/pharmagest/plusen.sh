#!/bin/bash
sleep 5
affiche=$(cat /usr/share/sounds/pharmagest/totalen 2> /dev/null)
somme=$(echo "$affiche" | bc)
clear
cd ; mpg123 -q /usr/share/sounds/pharmagest/factureEn.mp3 &
toilet -f mono9.tlf '+	+'
toilet -f mono9.tlf ' invoice'
echo "			YOUR PURCHASE(S) : "		
echo " "
cat /usr/share/sounds/pharmagest/total_end 2> /dev/null
echo "			 " 
echo "			TOTAL AMOUNT : $somme ARIARY"
echo " "
echo "			THANK YOU VERY MUCH !"
toilet -f mono9.tlf '+	+'
rm -r /usr/share/sounds/pharmagest/total_end 2> /dev/null
rm  -r /usr/share/sounds/pharmagest/totalen 2> /dev/null
sleep 15
pharmagest
