#include <iostream>
#include "Tronco.h"
#include "Nodo.h"

bool Tronco::estaVacio()
{
	if(this -> getVersiones().lenght() == 0)
		return true;
	else
		return false;
}

