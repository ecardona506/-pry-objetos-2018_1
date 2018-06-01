#ifndef __ARCHIVO_H__
#define __ARCHIVO_H__
#include <iostream>
#include <string>
using namespace std;

class Archivo
{
private:
	vector <string> archivo;
	string nombre;
public:
	Archivo(string nombre);
	string getNombre();
	void setNombre(string nombre);
	string getNombre();
};

#endif
