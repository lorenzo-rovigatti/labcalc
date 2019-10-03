#!/bin/bash

if [ ! -s persinfo.tex ]
then
	echo -e "Attenzione, per compilare correttamente i file è necessario che il file persinfo.tex sia presente. La riga che segue contiene un esempio di persinfo.tex valido:\n"
	echo -e "\persinfo{A-C}{Nicoletta Gnan}{lcgnXXX}\n"
	exit 0
fi

for f in $(ls -1 ex*tex)
do
	pdf_file=$(basename $f .tex).pdf
	if [ $f -nt $pdf_file ] || [ persinfo.tex -nt $pdf_file ]
	then
		lualatex $f
	fi
done

rm -f *aux *log
