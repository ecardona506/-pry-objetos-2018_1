#ifndef __NODO_H__
#define __NODO_H__
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

class Nodo
{
	private:
		string version;
		Archivo archActual;
		Archivo archControl;
	public:
		Nodo();
		Nodo(Archivo archActual,Archivo archControl);
};

#endif 

