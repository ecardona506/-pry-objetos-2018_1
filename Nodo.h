#ifndef __NODO_H__
#define __NODO_H__
#include "Archivo.h"
#include <string>
#include <iostream>

using namespace std;

class Nodo
{
private:
	string version;
	Archivo arch;
	Archivo control;
public:
	Nodo();
};

#endif