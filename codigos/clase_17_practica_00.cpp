#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
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

int test_00(){
    ofstream wf("clase_16_practica_01/ejemplo_00.dat", ios::out | ios::binary);
    if(!wf) {
        std::cout << "No se pudo abrir el archivo!" << endl;
        return 1;
    }else{
        char cadena[] = "Hola Mundo";
        int n = sizeof(cadena)/sizeof(char);
        wf.write((char *)&cadena, sizeof(char)*n);
        wf.close();
    }
    return 0;
}

int test_01(){
    FILE * pFile;
    char cadena[] = "Hola Mundo Ejemplo 2";//ultimo caracter '\0'
    pFile = fopen("clase_16_practica_01/ejemplo_01.dat", "wb");
    if(pFile != NULL){
        //fprintf(pFile, "%s",cadena);
        fwrite(cadena , sizeof(char), sizeof(cadena), pFile);
        std::cout << sizeof(cadena) << std::endl;
        fclose (pFile);
    }
    return 0;
}

void test_02(){
    string text = "El problema de los programadores es que nunca se sabe lo que un programador esta haciendo hasta que ya es demasiado tarde.";
    int n = BuildHuffmanTree(text);
    std::cout << std::endl;
    std::cout << "Espacio en memoria de text es: " << 8*text.size() << std::endl; 
    std::cout << "Espacio en memoria de text codificado es: " << n << std::endl; 
    std::cout << "Porcentaje de compresion: " << float(n)/(8.0*text.size()) << std::endl;
}

void test_03(){
    string text = "Buddy, you're a boy, make a big noise\nPlaying in the street, gonna be a big man someday\nYou got mud on your face, you big disgrace\n";
    text += "Kicking your can all over the place, singin'\nWe will, we will rock you\nWe will, we will rock you\nBuddy, you're a young man, hard man\n";
    text += "Shouting in the street, gonna take on the world someday\nYou got blood on your face, you big disgrace\nWaving your banner all over the place\nWe will, we will rock you, sing it!\nWe will, we will rock you, yeah\nBuddy, you're an old man, poor man\nPleading with your eyes, gonna get you some peace someday\nYou got mud on your face, big disgrace\nSomebody better put you back into your place, do it!\nWe will, we will rock you, yeah, yeah, come on\nWe will, we will rock you, alright, louder!\nWe will, we will rock you, one more time\nWe will, we will rock you\nYeah";
    int n = BuildHuffmanTree(text);
    std::cout << std::endl;
    std::cout << "Espacio en memoria de text es: " << 8*text.size() << std::endl; 
    std::cout << "Espacio en memoria de text codificado es: " << n << std::endl; 
    std::cout << "Porcentaje de compresion: " << float(n)/(8.0*text.size()) << std::endl;
}

void test_04(){
    std::ifstream in_file;
    in_file.open("clase_15_practica_01.cpp", ios::binary | ios::in);
    if (in_file) {
        std::cout << "Leyendo archivo" << std::endl;
        in_file.seekg (0, in_file.end);// vamos al final del archivo
        int length = in_file.tellg();
        in_file.seekg (0, in_file.beg);// regresamos al inicio
        char *buffer = new char[length];// creamos buffer para poder guardar todos los caracteres
        std::cout << "Leyendo " << length << " caracteres... "<< std::endl;
        in_file.read(buffer, length);
        //std::cout << buffer << std::endl;
        FILE *write_ptr;
        write_ptr = fopen("clase_16_practica_01/clase_15_practica_01.dat","wb");  // w para escribir, b para binario
        //char byte;
        char cadena[] = "Hola Mundo Ejemplo 3\n";
        if(write_ptr != NULL){
            std::cout << "Escribiendo archivo" << std::endl;
            fwrite(cadena , sizeof(char), sizeof(cadena), write_ptr);
            fwrite(buffer, sizeof(char), length, write_ptr);
            fclose(write_ptr);
        }
        delete[] buffer;
        in_file.close();
    }
}

unordered_map<char, string> crea_huffman_code(string text){
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
    return huffmanCode;
}


void test_05(){
    std::ifstream in_file;
    in_file.open("clase_15_practica_01.cpp", ios::binary | ios::in);
    if (in_file) {
        std::cout << "Leyendo archivo" << std::endl;
        in_file.seekg (0, in_file.end);// vamos al final del archivo
        int length = in_file.tellg();
        in_file.seekg (0, in_file.beg);// regresamos al inicio
        char *buffer = new char[length];// creamos buffer para poder guardar todos los caracteres
        std::cout << "Leyendo " << length << " caracteres... "<< std::endl;
        in_file.read(buffer, length);
        //std::cout << buffer << std::endl;
        unordered_map<char, string> huffmanCode = crea_huffman_code(buffer);
        string strCodificado = "";
        for ( int i = 0; i < length; ++i ){
            strCodificado += huffmanCode[buffer[i]];
        }
        //std::cout << "Texto codificado :" << strCodificado << std::endl;
        FILE *write_ptr;
        write_ptr = fopen("clase_16_practica_01/clase_15_practica_01.huf","wb");  // w para escribir, b para binario
        if(write_ptr != NULL){
            std::cout << "Escribiendo archivo comprimido" << std::endl;
            //fwrite (cadena , sizeof(char), sizeof(cadena), write_ptr);
            // convertir strCodificado a una estructura de bits y guardar en archivo
            //fwrite(cadena, 1, strCodificado.size(), write_ptr);
            fclose(write_ptr);
        }
        delete[] buffer;
        in_file.close();
    }
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

// Esta funcion recibe un bloque de 8 bits y lo convierte 
// a un caracter
char convierte_cadena_8bits_to_char(char *buffer){
    int n = 0;
    int potencia = 1;
    //std::cout << "Convirtiendo Big Endian" << std::endl;
    //std::cout << buffer << std::endl;
    for(int i = 0; i < 8;++i){
        if(buffer[i] == '1'){
            n += potencia;
        }
        potencia *= 2;
    }
    //std::cout << n << std::endl;
    return char(n);
}

// little endian
char convierte_cadena_8bits_to_char_le(char *buffer){
    int n = 0;
    int potencia = 1;
    //std::cout << "Convirtiendo Little Endian" << std::endl;
    //std::cout << buffer << std::endl;
    for(int i = 7; i >= 0;--i){
        if(buffer[i] == '1'){
            n += potencia;
        }
        potencia *= 2;
    }
    //std::cout << n << std::endl;
    return char(n);
}

int main(int argc, char *argv[]){
    char cadena[] = "1010001000101001010010101001011010101010101";
    int n = sizeof(cadena);
    std::cout << cadena << std::endl;
    std::cout << n << std::endl;
    vector<string> vectorCadenas = segmenta_cadena(cadena, n);
    std::cout << "Vector con " << vectorCadenas.size() << " elementos"<< std::endl;
    std::cout << "Cadena " << "BE " << "LE" << std::endl;
    string cadena_BE = "";
    string cadena_LE = "";
    for(int i = 0; i < vectorCadenas.size();++i){
        char BE = convierte_cadena_8bits_to_char((char*)vectorCadenas[i].c_str());
        char LE = convierte_cadena_8bits_to_char_le((char*)vectorCadenas[i].c_str()); 
        std::cout << vectorCadenas[i] << " ";
        std::cout << BE << " ";
        std::cout << LE << std::endl;
        cadena_BE.push_back(BE);
        cadena_LE.push_back(LE);
    }
    std::cout << cadena_BE.c_str() << std::endl;
    std::cout << cadena_LE.c_str() << std::endl;
	return 0;
}
