#!/bin/bash
echo "" > /usr/share/sounds/pharmagest/facturefr
clear
mpg123 -q /usr/share/sounds/pharmagest/combienmedfr.mp3 &
figlet client
read -p "Entrer le nombre de medicament(s) : " n
while [[ ! $n =~ ^[1-9]$ || $n -eq 0 ]]
do 
	figlet client
	mpg123 -q /usr/share/sounds/pharmagest/combienmedfr.mp3 &
	read -p "Entrer le nombre de medicament(s) : " n
	clear
done
clear
echo -n '0' > /usr/share/sounds/pharmagest/totalfr
touch /usr/share/sounds/pharmagest/facturefrfarany
mpg123 -q /usr/share/sounds/pharmagest/svpsaisfr.mp3 &
for ((i=0; i<n; i++))
do	
	figlet client
	read -p "Entrer le nom du médicament : " medoc
	clear
	while [[  $medoc =~ ^[0-9] || $medoc == "" ]]
	do 
		read -p "Entrer le nom du médicament : " medoc
		clear
	done
	#read -p "Entrer la quantité: " quantite
	clear
	#cd /usr/share/sounds/pharmagest/
	a=$(grep -ic "$medoc" /usr/share/sounds/pharmagest/depotfr)
	if [ $a -gt 0 ]
	then
		clear
		figlet client
		read -p "Entrer la quantité: " quantite
		clear
		while [[ ! $quantite =~ ^[1-9] || $quantite -eq 0 ]]
		do 
			figlet client
			read -p "Entrer la quantité: " quantite
			clear
		done
		#alaina le chiffre quantite de atao ao amle b
		b=$(grep -i "$medoc" /usr/share/sounds/pharmagest/depotfr | cut -f 3 -d ";" | cut -f 2 -d ":")
		#alaina le chiffre prix de atao ao amle c
		c=$(grep -i "$medoc" /usr/share/sounds/pharmagest/depotfr | cut -f 2 -d ";" | cut -f 2 -d ":")
		#calcul oe ampy va ilay stoky
		d=$(expr $b - $quantite)
		e="\n"
		if [ $d -lt 0 ]
		then
			mpg123 -q /usr/share/sounds/pharmagest/insuffisant.mp3 &
			echo "stock insuffisant, desolé"
			continue
		fi
		#ny tee miecraser fa tsy manao append
		grep -i "$medoc" /usr/share/sounds/pharmagest/depotfr | cut -f 1,2 -d ";" | tee /usr/share/sounds/pharmagest/facturefr
		sed -i "s/$/ X ${quantite}/" /usr/share/sounds/pharmagest/facturefr
		cat /usr/share/sounds/pharmagest/facturefr >> /usr/share/sounds/pharmagest/total_end
		#Manova ny quantite anle fanafody ao anaty depotfr
		sed -i "s/NOM:${medoc};PRIX:${c};QUANTITE:${b}/NOM:${medoc};PRIX:${c};QUANTITE:${d}/g" /usr/share/sounds/pharmagest/depotfr
		#Mba ovaina ko ny quantite anle fanafody ao anaty depoteng
		cat /usr/share/sounds/pharmagest/depotfr > /usr/share/sounds/pharmagest/depoteng
		#soloina izay " X $quantite" ho lasa tsy misy n'inoninona
		sed -i "s/ X ${quantite}//" /usr/share/sounds/pharmagest/facturefr
		#alaina ilay chiffre eo amle PRIX
		echo -n " + $(cut -f 2 -d ";" /usr/share/sounds/pharmagest/facturefr | cut -f 2 -d ":") * ${quantite}" >> /usr/share/sounds/pharmagest/totalfr
		sleep 2
	else
		mpg123 -q /usr/share/sounds/pharmagest/indispfr.mp3 &
		echo "Désolée ce medicament est indisponible"
		sleep 3
	fi
done
sh /usr/share/sounds/pharmagest/plusfr.sh
