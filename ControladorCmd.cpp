#include "ControladorCmd.h"

//#include <cstring>


using namespace std;

//ControladorCmd::ControladorCmd(){}


Tronco ControladorCmd::getTronco(){
	return tronco;
}


VistaCmd ControladorCmd::getVistaCmd(){
	return v;
}


void ControladorCmd::mostrarVersiones()
{
	int longitud = tronco.getVersiones().size();
	for (int i = 0; i < longitud; i++)
	{
		cout << tronco.getVersiones().at(i).getVersion() + "/";
	}
}


void ControladorCmd::crearNodo(string nombreArch,string nombreArchControl) 
{
	if(tronco.estaVacio() == true)
	{
		
		Archivo a; 
		Archivo a1;
//		a.abrirArchivo(nombreArch);
		
//		a.setNombreArch(v.getNombreArch());
//		a1.setNombreArchControl(v.setNombreArchControl());
		
		Nodo n(a,a1);
		n.setVersion("1.1");
		tronco.addNodo(n);
//		cout<<"aquiiiiiiiiiiii"<<n.getVersion();.


	}
	
	else
	{
		v.verificarCreado();
	}
}




void ControladorCmd::obtener(Archivo nombreArchControl, string versiones){
	Archivo a;
	Archivo a1;
	Archivo a2;
	a.abrirArchivo(a.getNombreArchControl());
	a1.getContendidoArchivo() = a.getContendidoArchivo();
	a2.getContendidoArchivo() = a.getContendidoArchivo(); 
	Nodo n(a1,a2);
	
	
	
}



