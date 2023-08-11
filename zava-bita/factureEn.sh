#!/bin/bash
cd /usr/share/sounds/pharmagest/
rm /usr/share/sounds/pharmagest/total_end /usr/share/sounds/pharmagest/totalen /usr/share/sounds/pharmagest/factureEnfarany 2>/dev/null
sleep 2
clear
mpg123 -q /usr/share/sounds/pharmagest/combmeden.mp3 &
read -p "Enter the number of drug(s) : " n
clear
while [[ ! $n =~ ^[0-9]$ || $n -eq 0 ]]
do 
	mpg123 -q /usr/share/sounds/pharmagest/combmeden.mp3 &
	read -p "Enter the number of drug(s) : " n
	clear
done

echo -n "0" > /usr/share/sounds/pharmagest/totalen
touch /usr/share/sounds/pharmagest/factureEnfarany
mpg123 -q /usr/share/sounds/pharmagest/svpsaisen.mp3 &
for ((i=0; i<n; i++))
do	
	read -p "Enter the name of drug : " medoc
	clear
	while [[  $medoc =~ ^[0-9] ]]
	do 
		read -p "Enter the name of drug : " medoc
		clear
	done
	cd /usr/share/sounds/pharmagest/
	a=$(grep -c "$medoc" /usr/share/sounds/pharmagest/depoteng)
	
	if [ $a -gt 0 ]
	then
		clear
		read -p "Enter the quantity: " quantite
		while [[ ! $quantite =~ ^[1-9] || $quantite -eq 0 ]]
		do 
			read -p "Enter the quantity: " quantite
			clear
		done
		#alaina le chiffre quantite de atao ao amle b
		b=$(grep -i "$medoc" /usr/share/sounds/pharmagest/depoteng | cut -f 3 -d ";" | cut -f 2 -d ":")
		#alaina le chiffre prix de atao ao amle c
		c=$(grep -i "$medoc" /usr/share/sounds/pharmagest/depoteng | cut -f 2 -d ";" | cut -f 2 -d ":")
		#calcul oe ampy va ilay stoky
		d=$(expr $b - $quantite)
		
		if [ $d -lt 0 ]
		then
			echo "sorry this drug is out of stock"
			continue
		fi
		#ny tee miecraser fa tsy manao append
		grep -i "$medoc" /usr/share/sounds/pharmagest/depoteng | cut -f 1,2 -d ";" | tee factureEn
		sed -i "s/$/ X ${quantite}/" /usr/share/sounds/pharmagest/factureEn
		cat factureEn >> /usr/share/sounds/pharmagest/total_end
		#Manova ny quantite anle fanafody ao anaty depotfr
		sed -i "s/NOM:${medoc};PRIX:${c};QUANTITE:${b}/NOM:${medoc};PRIX:${c};QUANTITE:${d}/g" /usr/share/sounds/pharmagest/depoteng
		sed -i "s/NOM:${medoc};PRIX:${c};QUANTITE:${b}/NOM:${medoc};PRIX:${c};QUANTITE:${d}/g" /usr/share/sounds/pharmagest/depotfr
		#soloina izay " X $quantite" ho lasa tsy misy n'inoninona
		sed -i "s/ X ${quantite}//" /usr/share/sounds/pharmagest/factureEn
		#alaina ilay chiffre eo amle PRIX
		echo -n " + $(cut -f 2 -d ";" factureEn | cut -f 2 -d ":") * ${quantite}" >> /usr/share/sounds/pharmagest/totalen
		sleep 2
	else
		mpg123 -q /usr/share/sounds/pharmagest/indispEng.mp3 &
		echo "Sorry this medicine is unavailable"
		sleep 2
	fi
done
clear
affiche=$(cat /usr/share/sounds/pharmagest/totalen)
somme=$(echo "$affiche" | bc)
clear
mpg123 -q /usr/share/sounds/pharmagest/factureEn.mp3 &
toilet -f mono9.tlf '+	+'
toilet -f mono9.tlf ' invoice'
echo "			YOUR PURCHASE(S) : "		
echo " "
cat /usr/share/sounds/pharmagest/total_end
echo "			 " 
echo "			TOTAL AMOUNT : $somme ARIARY"
echo " "
echo "			THANK YOU VERY MUCH !"
toilet -f mono9.tlf '+	+'
sleep 5
rm /usr/share/sounds/pharmagest/total_end
rm -r /usr/share/sounds/pharmagest/totalen
rm -r /usr/share/sounds/pharmagest/factureEnfarany
