
# Makefile de la Parte 1 - Interfaz List<T> y ListArray<T>
bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h
clean:
	rm -r *.o *.gch bin

# Makefile de la Parte 1 - Clase Node<T>
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

