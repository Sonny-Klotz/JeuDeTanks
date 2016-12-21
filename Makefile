SRC=src
TARGET=target
NAVIGATEUR=google-chrome

all:
	qmake -makefile -o MakefileApp $(SRC)/tankApp/tankApp.pro
	make -f MakefileApp
	
run: all
	tankApp
	
tests:

run-tests:

.PHONY: all clean tests

clean:
# Binaires issus de la compilation des classes
	find . -name "*.o" -type f -delete

distclean: clean
# Fichiers générés à la compilation
	rm -rf $(TARGET)
	rm -f MakefileApp
	find . -name "*.moc" -type f -delete
