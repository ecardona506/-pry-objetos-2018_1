#include <iostream>


#define __TRONCO_H__
#ifndef __TRONCO_H__

using namespace std;


class Tronco{
private:
	vector<Nodo> versiones;
public:
	void obtener(Archivo nombreArchControl,string versiones);
	void obtener(Archivo nombreArchControl);
	void crarNodo(Archivo nombreArchActual,Archivo nombreArchControl);
	void crarRama(Archivo nombreArchActual,Archivo nombreArchControl);
	void modificar(nombreArchControl);



};


#endif
