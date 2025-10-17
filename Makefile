
# Makefile de la Parte 1 - Interfaz List<T> y ListArray<T>
bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

# Makefile de la Parte 1 - Clase Node<T>
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

# Makefile de la Parte 1 - Interfaz List<T> y ListLinked<T>
bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h

clean:
	rm -r *.o *.gch bin