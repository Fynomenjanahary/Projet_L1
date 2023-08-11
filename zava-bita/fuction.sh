#!/bin/bash
 
FirstArg=$1
 
function salut
        {
if [ $FirstArg = "Bruno" ]
then
        echo "Salut Bruno !"
elif [ $FirstArg = "Michel" ]
then
        echo "Bien le bonjour Michel"
elif [ $FirstArg = "Jean" ]
then
        echo "Hé Jean, ça va ?"
else
        echo "J'te connais pas, ouste !"
fi
        }
 
salut
