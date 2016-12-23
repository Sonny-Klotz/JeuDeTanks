SRC=src
TARGET=target

all:
	qmake -makefile -o MakefileApp $(SRC)/tankApp/tankApp.pro
	make -f MakefileApp
	
run: all
	$(TARGET)/bin/tankApp
	
tests: all
	qmake -makefile -o MakefileTests $(SRC)/tests/tests.pro
	moc -o $(SRC)/$@/testtankapp.moc $(SRC)/$@/TestTankApp.cpp 
	make -f MakefileTests
	
run-tests: tests
	$(TARGET)/bin-tests/tests

.PHONY: all clean tests

clean:
# Binaires issus de la compilation des classes
	find . -name "*.o" -type f -delete

distclean: clean
# Fichiers générés à la compilation
	rm -rf $(TARGET)
	rm -f MakefileApp
	rm -f MakefileTests
	find . -name "*.moc" -type f -delete
