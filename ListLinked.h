#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first;
        int n;
    public:
        ListLinked(){
            this->first = nullptr;
            this->n = 0;
        }
        ~ListLinked(){
            while(first != nullptr){
                Node<T>* aux = first;
                first = first->next;
                delete aux;
            }
        }
		// Devolvemos el elemento de la posición "pos"
		T operator[](int pos){
			if(pos < 0 || pos >= size()){
				throw std::out_of_range("Error, fuera de rango(operador()).");
			}
			Node<T>* c = first;
			for(int i = 0; i < pos; i++){ // Avanzamos hasta "pos"
				c = c->next;
			}
			return c->data;
		}
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
            out << "Lista -> [\n";
			Node<T>* c = list.first;
			while(c != nullptr){
				out << c->data << "\n";
				c = c->next;
			}
			out << "]";
			return out;
        }

        // Insertamos "e" en la posicion "pos" del vector
		void insert(int pos, T e) override{
			Node<T>* c = new Node<T>(e);
			if(pos < 0 || pos > size()){
				throw std::out_of_range("Error, fuera de rango(insert()).");
			}
			if(pos == 0){
				c ->next = first;
				first = c;
			}else{
				Node<T>* anterior = first;
				for(int i = 0; i < pos-1; i++){
					anterior = anterior->next; // Avanza hasta encontrar pos-1
				}
				c->next = anterior->next;
				anterior->next = c;
			}
			this->n++; // Actualizamos el nº de elementos
		}
        // Insertamos "e" al final del vector 
		void append(T e) override{
			Node<T>* c = new Node<T>(e);
			if(first == nullptr){ // No hay ningun elemento y lo inserta el primero.
				first = c;
				c->next = nullptr;
			}else{
				Node<T>* aux = first;
				while (aux->next != nullptr) { // Avanza hasta el ultimo nodo
					aux = aux->next;
				}
				aux->next = c;
				c->next = nullptr;
			}
			this->n++; // Aumentamos n
		}

		//Insertamos "e" al principio del vector
		void prepend(T e) override{
			Node<T>* c = new Node<T>(e);
			if(first == nullptr){ // No hay ningun elemento y lo inserta el primero.
				first = c;
				c->next = nullptr;
			}else{ // Hay elementos y se inserta en primera posicion
				c->next = first;
				first = c;
			}
			this->n++; // Aumentamos n
		}

		// Elimina el elemento de la posicion "pos"
		T remove(int pos) override{
			if(pos < 0 || pos > size()-1){
				throw std::out_of_range("Error, fuera de rango(remove()).");
			}
			Node<T>* eliminarNodo = first;
			T valor;
			if(pos == 0){
				eliminarNodo = first;
				valor = eliminarNodo->data;
				first = first->next;
			}else{
				Node<T>* anterior = first;
				for(int i = 0; i < pos-1; i++){
					anterior = anterior->next;
				}
				eliminarNodo = anterior->next;
				valor = eliminarNodo->data;
				anterior->next = eliminarNodo->next;
			}
			delete eliminarNodo;
			n--;
			return valor;
		}

		// Devuelve el elemento de la posicion "pos"
		T get(int pos) override{
			if(pos < 0 || pos > size()-1){
				throw std::out_of_range("Error, fuera de rango(get()).");
			}else{
				if(pos == 0){
					return first->data;
				}else{
					Node<T>* aux = first;
					for(int i = 0; i < pos; i++){
						aux = aux->next;
					}
					return aux->data;
				}
			}
		}

		// Devuelve la posicion en la que se encuentra primer elemento "e"
		int search(T e) override{
			Node<T>* aux = first;
			int pos = 0;
			while(aux != nullptr){
				if(aux->data == e){
					return pos;
				}else{
					pos++;
					aux = aux->next;
				}
			}return -1; // No se ha encontrado e
		}

		// Devuelve "true" si está vacía y "false" si no está vacía
		bool empty() override{
			if(n == 0){
				return true; // Lista vacía
			}else{
				return false; // Lista no vacia
			}
		}

		// Devuelve el nº elementos de la lista
		int size() override{
			return n;
		}
};