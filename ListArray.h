#include <iostream>
#include "List.h"

template <typename T>
class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
		void resize(int new_size){
			//Creamos el nuevo array
			T* new_arr = new T[new_size];

			//Copio el contenido en el nuevo array
			for(int i = 0; i < n; i++){
				new_arr[i] = this->arr[i];
			}
			// Liberamos los recursos de memoria de arr
			delete[] this->arr;

			//Actualizo arr
			this->arr = new_arr;

			// Actualizo max
			max = new_size;
		}
	public:
		ListArray(){
			this->n = 0;
			this->max = MINSIZE;
			this->arr = new T[this->max];
		}
		~ListArray(){
			delete[] this->arr;
		}
		T operator[](int pos){
			if(pos < 0 || pos >= size()){
				throw std::out_of_range("Error, fuera de rango(insert()).");
			}
			return this->arr[pos];
		}
		friend std::ostream& operator << (std::ostream &out, const ListArray<T> & list){
			out << "Lista -> [\n";
			for(int i = 0; i < list.n; i++){
				out << list.arr[i] << "\n";
			}
			out << "]";
			return out;
		}
		
		// Insertamos "e" en la posicion "pos" del vector
		void insert(int pos, T e) override{
			if(pos < 0 || pos > size()){
				throw std::out_of_range("Error, fuera de rango(insert()).");
			}
			//Redimensionamiento
			if(n == max){
				resize(max*2);
			}
			// Movemos a la derecha para abrir espacio para "pos"
			for(int i = n; i > pos; i--){
				this->arr[i] = this->arr[i-1];
			}
			this->arr[pos] = e; // Insertamos el elemento en la pos
			this->n++; // Actualizamos el nº de elementos
		}

		// Insertamos "e" al final del vector 
		void append(T e) override{
			if(n == max){
				resize(max*2); // Si esta lleno el array, lo amplio
			}
			this->arr[n] = e; // Coloco e en la ultima posicion
			n++; // Aumento n
		}

		//Insertamos "e" al principio del vector
		void prepend(T e) override{
			if(n == max){
				resize(max*2); // Si el array esta lleno, lo amplio
			}
			//Desplazamos todo una posicion a la derecha
			for(int i = n; i > 0; i--){
				this->arr[i] = this->arr[i-1];
			}
			this->arr[0] = e; // Coloco e al principio
			n++; // Aumento n
		}

		// Elimina el elemento de la posicion "pos"
		T remove(int pos) override{
			if(pos < 0 || pos > size()-1){
				throw std::out_of_range("Error, fuera de rango(remove()).");
			}
			T removed_el = this->arr[pos];
			for(int i = pos; i < n-1; i++){
				this->arr[i] = this->arr[i+1];
			} n--; // Decrementamos
			// Si n es 1/4 o menos de la capacidad max, reducimos a la mitad el tamaño
			if (n <= max / 4 && max / 2 >= MINSIZE) {
        		resize(this->max / 2);
    		}
			return removed_el;
		}

		// Devuelve el elemento de la posicion "pos"
		T get(int pos) override{
			if(pos < 0 || pos > size()-1){
				throw std::out_of_range("Error, fuera de rango(get()).");
			}else{
				return this->arr[pos]; // Devolvemos el elemento de this->arr[pos]
			}
		}

		// Devuelve la posicion en la que se encuentra primer elemento "e"
		int search(T e) override{
			// Recorro todo el array en busca de "e"
			for(int i = 0; i < n; i++){
				if(this->arr[i] == e){
					return i;
				}
			}return -1; // No se ha encontrado el e
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



