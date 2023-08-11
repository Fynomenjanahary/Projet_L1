#!/bin/bash

i=0
while [ $i -le 8 ]
do
	if [ $((i%2)) -eq 0 ]
	then
		echo  'ASSISTANCE VOCALE'
		echo '	\e[92m ~     ~\e[o'
		echo  '	\e[92m    ^    \e[o'
		echo  '	\e[92m   __  \e[o'
	sleep 0.8;clear
	else
		echo  'ASSISTANCE VOCALE'
		echo '	\e[92m¨X¨   ¨X¨\e[o'
		echo  '	\e[92m    ^    \e[o'
		echo '	\e[92m    V  \e[o'
	sleep 0.8 ; clear
	fi

	i=$((i+1))
done
