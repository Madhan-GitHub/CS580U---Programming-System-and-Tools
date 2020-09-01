#!/bin/bash

#Deleting the files in TRASH directory if it  exists more than 60 minutes.
#Checks for TRASH directory if not creates one.
if [ -d TRASH ]
then
	find ./TRASH -mmin +60 -type f -delete
elif [ ! -d TRASH ] 
then
	mkdir -p TRASH;
	echo "TRASH folder is created"
fi

#Checks for the files(object file and executables)and moves it to TRASH.
#Displays mssage if not exists.
for i in $@
do
	if [ -f $i ]
	then
		mv $i TRASH/
		echo "File $i is moved to TRASH"
	elif [ ! -f $i ]
	then
		echo "File $i does not exist"
	fi
done
