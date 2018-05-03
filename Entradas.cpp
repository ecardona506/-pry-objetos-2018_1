#include "Nodo.cpp"

#ifndef __ENTRADAS_H__
#define __ENTRADAS_H__

using namespace std;

  
Nodo n;
class Entradas
{
	private:
		string codigo;
	public:
		void crearNodo(double idp){
			/*release = release;
			nivel = nivel;*/
			n.id = idp;
			ofstream archivo;
			archivo.open("archivo.txt",ios::out); //abriendo el archivo original
			if(archivo.fail())
			{
				cout<<"error al abrir el archivo";
				exit(-1);  
			}
	
			cout<<"Digite lo que se le pegue la gana: "<<endl;
			getline(cin,codigo);
			archivo<<codigo;  
			archivo.close();
		}
};	
#endif
