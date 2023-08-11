#!/bin/bash

rm /usr/share/sounds/pharmagest/total_end /usr/share/sounds/pharmagest/totalfr /usr/share/sounds/pharmagest/facturefrfarany 2>/dev/null

sleep 2
clear
cd ; mpg123 -q /usr/share/sounds/pharmagest/combienmedfr.mp3 &
read -p "Entrer le nombre de medicament(s) : " n
clear
while [[ ! $n =~ ^[1-9] || $n -eq 0 ]]
do 
	cd ; mpg123 -q /usr/share/sounds/pharmagest/combienmedfr.mp3 &
	read -p "Entrer le nombre de medicament(s) : " n
	clear
done

echo -n '0' > /usr/share/sounds/pharmagest/totalfr
touch /usr/share/sounds/pharmagest/facturefrfarany
cd ; mpg123 -q /usr/share/sounds/pharmagest/svpsaisfr.mp3 &
for ((i=0; i<n; i++))
do	
	read -p "Entrer le nom du médicament : " medoc
	clear
	while [[  $medoc =~ ^[0-9] ]]
	do 
		read -p "Entrer le nom du médicament : " medoc
		clear
	done
	#read -p "Entrer la quantité: " quantite
	
	cd /usr/share/sounds/pharmagest/
	a=$(grep -ic "$medoc" /usr/share/sounds/pharmagest/depotfr)
	if [ $a -gt 0 ]
	
	then
		clear
		read -p "Entrer la quantité: " quantite
		while [[ ! $quantite =~ ^[1-9] || $quantite -eq 0 ]]
		do 
			read -p "Entrer la quantité: " quantite
			clear
		done
		#alaina le chiffre quantite de atao ao amle b
		b=$(grep -i "$medoc" depotfr | cut -f 3 -d ";" | cut -f 2 -d ":")
		#alaina le chiffre prix de atao ao amle c
		c=$(grep -i "$medoc" depotfr | cut -f 2 -d ";" | cut -f 2 -d ":")
		#calcul oe ampy va ilay stoky
		d=$(expr $b - $quantite)
		e="\n"
		if [ $d -lt 0 ]
		then
			echo "stock insuffisant, desolé"
			continue
		fi
		#ny tee miecraser fa tsy manao append
		grep -i "$medoc" depotfr | cut -f 1,2 -d ";" | tee facturefr
		sed -i "s/$/ X ${quantite}/" facturefr
		cat facturefr >> /usr/share/sounds/pharmagest/total_end
		#Manova ny quantite anle fanafody ao anaty depotfr
		sed -i "s/NOM:${medoc};PRIX:${c};QUANTITE:${b}/NOM:${medoc};PRIX:${c};QUANTITE:${d}/g" depotfr
		sed -i "s/NOM:${medoc};PRIX:${c};QUANTITE:${b}/NOM:${medoc};PRIX:${c};QUANTITE:${d}/g" depoteng
		#soloina izay " X $quantite" ho lasa tsy misy n'inoninona
		sed -i "s/ X ${quantite}//" facturefr
		#alaina ilay chiffre eo amle PRIX
		echo -n " + $(cut -f 2 -d ";" facturefr | cut -f 2 -d ":") * ${quantite}" >> totalfr
		sleep 2
	else
		cd ; mpg123 -q /usr/share/sounds/pharmagest/indispfr.mp3 &
		echo "Désolée ce medicament est indisponible"
		sleep 3
	fi
done

clear
affiche=$(cat ~/MrHaga/totalfr)
somme=$(echo "$affiche" | bc)
clear
cd ; mpg123 -q /usr/share/sounds/pharmagest/facturefr.mp3 &
figlet '+									+'
figlet facture
echo "   VOS ACHAT(S) : "
echo " "
cat /usr/share/sounds/pharmagest/total_end
echo " " 
echo MONTANT TOTAL : $somme ARIARY
echo " "
echo "MERCI BEAUCOUP !"
figlet '+									+'
rm /usr/share/sounds/pharmagest/total_end
rm -r /usr/share/sounds/pharmagest/totalfr
rm -r /usr/share/sounds/pharmagest/facturefrfarany
