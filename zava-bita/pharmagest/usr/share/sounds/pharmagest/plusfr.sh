#!/bin/bash
sleep 4
affiche=$(cat /usr/share/sounds/pharmagest/totalfr 2> /dev/null)
somme=$(echo "$affiche" | bc)
clear
cd ; mpg123 -q /usr/share/sounds/pharmagest/facturefr.mp3 &
toilet -f mono9.tlf '+	+'
toilet -f mono9.tlf ' facture'
echo "   			VOS ACHAT(S) : "
echo " "
cat /usr/share/sounds/pharmagest/total_end 2> /dev/null
echo " " 
echo "			MONTANT TOTAL : $somme ARIARY"
echo " "
echo "			MERCI BEAUCOUP !"
toilet -f mono9.tlf '+	+'
rm  /usr/share/sounds/pharmagest/total_end 2> /dev/null
rm  /usr/share/sounds/pharmagest/totalfr 2> /dev/null
sleep 15
pharmagest

