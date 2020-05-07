#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <unordered_map>
using namespace std;

template <typename T>
struct Node {
    T data;
    int frecuencia;//agregamos un nuevo elemento a nuestro nodo
    Node *left;
    Node *right;
    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    ~Node(){
    }
    Node(const T &val) {
        data = val;
        left = NULL;
        right = NULL;
    }
    //creamos nuevo constructor con  frecuencia
    Node(const T &val,const int &_frecuencia) {
        data = val;
        frecuencia = _frecuencia;
        left = NULL;
        right = NULL;
    }
};

// Funcion para crear un nodo
template <typename T>
Node<T>* GetNode(T _data, int _frecuencia, Node<T>* left, Node<T>* right){
	Node<T>* node = new Node<T>(_data, _frecuencia);
	node->left = left;
	node->right = right;
	return node;
}

// Sobrecarga de operador comparacion para ordenar el heap
struct comp{
	bool operator()(Node<char>* l, Node<char>* r){
		return (l->frecuencia > r->frecuencia);
	}
};


// recorrido del arbol mientras guardamos los codigos huffman en un unordered_map
void Encode(Node<char>* root, string str, unordered_map<char, string> &huffmanCode){
	if (root == NULL){
        return;
    }
	if (root->left == NULL && root->right == NULL) {// checamos si se trata de un nodo hoja
		huffmanCode[root->data] = str;
	}
	Encode(root->left, str + "0", huffmanCode);
	Encode(root->right, str + "1", huffmanCode);
}

// recorrido del arbol y decodificacion de la cadena de caracteres
void Decode(Node<char>* root, int &index, string str){
	if (root == NULL) {
		return;
	}
	if (root->left == NULL && root->right == NULL) {// checando si es un nodo hoja
		std::cout << root->data;
		return;
	}
	index++;// avanzamos un lugar
	if (str[index] == '0'){
		Decode(root->left, index, str);
    }else{
		Decode(root->right, index, str);
    }
}

// creamos el arbol y decodificamos un texto
int BuildHuffmanTree(string text, bool bprint=false){
    // contamos el numero de veces que aparece cada caracter y lon guardamos en un unordered_map
	unordered_map<char, int> um_freq;
    int n = text.size();
    for ( int i = 0; i < n; ++i ){
        um_freq[text[i]]++;
    }
    // creamos priority queue para guardar los nodos
	priority_queue<Node<char>*, vector<Node<char>*>, comp> pq;
    // creamos un nodo hoja por cada caracter y lo agregamos al priority queue
	for (auto pair: um_freq) {
		pq.push(GetNode<char>(pair.first, pair.second, NULL, NULL));
	}
	// Repetimos el proceso de crear nodos internos hasta que quede un solo nodo
	while (pq.size() > 1){
        // Quitamos los dos nodos con mayor prioridad(menor frecuencia) del priority queue
		Node<char> *left = pq.top();
        pq.pop();
		Node<char> *right = pq.top();
        pq.pop();
        // Creamos un nuevo nodo interno que contiene la suma de las dos frecuencias y lo agregamos al priority queue
		int suma = left->frecuencia + right->frecuencia;
		pq.push(GetNode<char>('\0', suma, left, right));
	}
    // Ya quye solo queda uno creamos el nodo root con este ultimo valor del priority queue
	Node<char>* root = pq.top();
    // recorrido del arbol huffman y guardado de los codigos huffman
	unordered_map<char, string> huffmanCode;
	Encode(root, "", huffmanCode);
    // Ya llenamos la lista de relaciones entre letras y cadena de bits que le tocan
    if(bprint){
        std::cout << "Lista de codigos Huffman:" << std::endl;
        for (auto pair: huffmanCode) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
        std::cout << "Texto original :" << text << std::endl;
    }
	// Creamos cadena de caracteres con el texto codificado
    // como se veria en memoria(bits) nuestro texto comprimido/codificado
	string strCodificado = "";
    for ( int i = 0; i < n; ++i ){
        strCodificado += huffmanCode[text[i]];
    }
    if(bprint){
        std::cout << "Texto codificado :" << strCodificado << std::endl;
    }
	
    // recorrido del arbol y texto codificado y decodificado
	int index = -1;
	std::cout << "Texto decodificado: ";
	while (index < (int)strCodificado.size() - 2) {
		Decode(root, index, strCodificado);
	}
    std::cout << std::endl;
    return strCodificado.size();
    return 0;
}

unordered_map<char, string> crea_huffman_code(string text, Node<char>* &root){
    // contamos el numero de veces que aparece cada caracter y lon guardamos en un unordered_map
	unordered_map<char, int> um_freq;
    int n = text.size();
    for ( int i = 0; i < n; ++i ){
        um_freq[text[i]]++;
    }
    // creamos priority queue para guardar los nodos
	priority_queue<Node<char>*, vector<Node<char>*>, comp> pq;
    // creamos un nodo hoja por cada caracter y lo agregamos al priority queue
	for (auto pair: um_freq) {
		pq.push(GetNode<char>(pair.first, pair.second, NULL, NULL));
	}
	// Repetimos el proceso de crear nodos internos hasta que quede un solo nodo
	while (pq.size() > 1){
        // Quitamos los dos nodos con mayor prioridad(menor frecuencia) del priority queue
		Node<char> *left = pq.top();
        pq.pop();
		Node<char> *right = pq.top();
        pq.pop();
        // Creamos un nuevo nodo interno que contiene la suma de las dos frecuencias y lo agregamos al priority queue
		int suma = left->frecuencia + right->frecuencia;
		pq.push(GetNode<char>('\0', suma, left, right));
	}
    // Ya quye solo queda uno creamos el nodo root con este ultimo valor del priority queue
	root = pq.top();
    // recorrido del arbol huffman y guardado de los codigos huffman
	unordered_map<char, string> huffmanCode;
	Encode(root, "", huffmanCode);
    return huffmanCode;
}

vector<string> segmenta_cadena(char *buffer, int length){
    vector <string> myvector;
    string buffer2="";
    for(int i = 0; i < length-1 ;++i){
        if(i > 0 && i%8 == 0){
            myvector.push_back(buffer2);
            buffer2="";
        }
        buffer2 += buffer[i];
    }
    if(buffer2.size()>0){
        for(int i = buffer2.size(); i < 8;i++){
            buffer2 += '0';
        }
        myvector.push_back(buffer2);
    }
    return myvector;
}

char convierte_cadena_8bits_to_char(char *buffer){
    int n = 0;
    int potencia = 1;
    for(int i = 0; i < 8;++i){
        if(buffer[i] == '1'){
            n += potencia;
        }
        potencia *= 2;
    }
    return char(n);
}

char convierte_cadena_8bits_to_char_le(char *buffer){
    int n = 0;
    int potencia = 1;
    for(int i = 7; i >= 0;--i){
        if(buffer[i] == '1'){
            n += potencia;
        }
        potencia *= 2;
    }
    return char(n);
}

// basicamente convertiremos de decimal a binario
string convierte_char_to_8bits(char c){// recuerden que un char es un short int
    int val = (unsigned char)c;
    //std::cout << char(val);
    char bloque[9];
    int counter = 0;
    while(val>0 || counter < 8){
        bloque[counter]= (val%2)+'0';
        val /= 2;
        counter++;
    }
    bloque[8] = '\0';
    return string(bloque);
}

string decodifica(string strCodificado,unordered_map<char, string> &huffmanCode, Node<char>* root){
    string strDecodificado = "";
    int index = -1;
	std::cout << "Texto decodificado: " <<std::endl;
	while (index < (int)strCodificado.size() - 2) {
		Decode(root, index, strCodificado);
	}
    std::cout << std::endl;
    return strDecodificado;
}

int main(int argc, char *argv[]){
    unordered_map<char, string> huffmanCode;
    Node<char>* root;
    std::ifstream in_file;
    in_file.open("clase_15_practica_01.cpp", ios::binary | ios::in);
    if (in_file) {
        std::cout << "Leyendo archivo" << std::endl;
        in_file.seekg (0, in_file.end);
        int length = in_file.tellg();
        in_file.seekg (0, in_file.beg);
        char *buffer = new char[length];
        std::cout << "Leyendo " << length << " caracteres... "<< std::endl;
        in_file.read(buffer, length);
        //std::cout << buffer << std::endl;
        huffmanCode = crea_huffman_code(buffer, root);
        string strCodificado = "";
        for ( int i = 0; i < length; ++i ){
            strCodificado += huffmanCode[buffer[i]];
        }
        //std::cout << "Texto codificado :" << strCodificado << std::endl;
        FILE *write_ptr;
        write_ptr = fopen("clase_17_practica_01/clase_15_practica_01.huf","wb");  // w para escribir, b para binario
        if(write_ptr != NULL){
            std::cout << "Segementando archivo codificado" << std::endl;
            char *buffer2 = new char[strCodificado.size()];
            strcpy(buffer2, strCodificado.c_str());
            vector<string> vectorCadenas = segmenta_cadena(buffer2, strCodificado.size());
            // for(int i = 0; i < vectorCadenas.size();++i){
            //     std::cout << vectorCadenas[i] << std::endl;
            // }
            string cadena_BE = "";
            for(int i = 0; i < vectorCadenas.size();++i){
                cadena_BE.push_back(convierte_cadena_8bits_to_char((char*)vectorCadenas[i].c_str()));
            }
            //std::cout << cadena_BE << std::endl;
            std::cout << "Escribiendo archivo comprimido" << std::endl;
            fwrite (cadena_BE.c_str() , sizeof(char), cadena_BE.size(), write_ptr);
            fclose(write_ptr);
            delete[] buffer2;
        }
        delete[] buffer;
        in_file.close();
    }  
    // Ahora leamos el archivo comprimido
    in_file.open("clase_17_practica_01/clase_15_practica_01.huf", ios::binary | ios::in); 
     if (in_file) {
        std::cout << "Leyendo archivo comprimido" << std::endl;
        in_file.seekg (0, in_file.end);
        int length = in_file.tellg();
        in_file.seekg (0, in_file.beg);
        char *buffer = new char[length];
        std::cout << "Leyendo " << length << " caracteres codificados y convertidos a representacion big endian"<< std::endl;
        in_file.read(buffer, length);
        string strCodificado = "";
        string bloque;
        for(int i = 0;i < length;++i){
            //std::cout << buffer[i];
            bloque = convierte_char_to_8bits(buffer[i]);
            //std::cout << bloque << " " << buffer[i] << std::endl;
            strCodificado = strCodificado + bloque;
        }
        std::cout << std::endl;
        std::cout << "String codificado en binario listo para decodificar con arbol" << std::endl;
        //std::cout << strCodificado << std::endl;
        decodifica(strCodificado, huffmanCode, root);
        in_file.close();
     }
	return 0;
}
