SRC=/home/user/Bureau/JeuDeTanks/src
TARGET=/home/user/Bureau/JeuDeTanks/target
NAVIGATEUR=firefox

all:

rapport:
	pdflatex -output-directory $(TARGET)/rapport $(SRC)/rapport/rapport.tex
	evince $(TARGET)/rapport/$@.pdf &
	clear

documentation:
	doxygen $(SRC)/Doxyfile
	$(NAVIGATEUR) $(TARGET)/$@/index.html &
	sleep 1
	clear

.PHONY: clean

clean:
	rm $(TARGET)/rapport/rapport.log
	rm $(TARGET)/rapport/rapport.aux

distclean: clean
	rm $(TARGET)/rapport/rapport.pdf
