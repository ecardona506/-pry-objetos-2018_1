#include <iostream>
#include "Archivo.h"
#include "Nodo.h"
#include "Tronco.h"
#include "ControladorCmd.h"
#include <string>
#include <cstring>

using namespace std;

//--------------------------------//

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
//---------------------------------//
ControladorCmd::ControladorCmd(){}

ControladorCmd::ControladorCmd(Tronco tronco)
{
	this -> tronco = tronco;
}

Tronco ControladorCmd::getTronco()
{
	return tronco;
}

void ControladorCmd::crear(string nombreArch)
{
	
	if(tronco.estaVacio())
	{
		string nombre_copia = "s_" + nombreArch;
		Archivo original(nombreArch);
		Archivo copia(nombre_copia);
		Nodo n(original,copia);
		n.setVersion("1.1");
		tronco.addNodo(n);
	}
	else
	{
		cout << "Ya se ha creado la primera version.";
	}
}

//sirve para ----> 1.2/1.2/1.3

Nodo ControladorCmd::filtro1(vector <Nodo> versiones, string version)
{
	Nodo n;
	if(versiones.empty())
	{
		return n;
	}
	else
	{
		vector <Nodo> res;
		char *versionArg = new char[version.size() + 1];
		strcpy(versionArg, version.c_str());
		for (int i = 0; i < versiones.size(); i++)
		{
			if(versiones.at(i).getVersion().size() == 3)
				char *versionFiltro = new char[4];
				char *versionFiltro = new char[4];
				strcpy(versionFiltro, versiones.at(i).getVersion().c_str());
				if(versionFiltro[0] <= versionArg[0])
				{
					res.push_back(versiones.at(i));
				}
		}
		if(res.empty())
		{
			return n;
		}
		else
		{
			return res.back();
		}
	}
}

//sirve para ----> 1.1.1.2/1.1.2/1.1.2.1

Nodo ControladorCmd::filtro2(vector <Nodo> versiones, string version)
{
	Nodo n;
	if(versiones.empty())
	{
		return n;
	}
	else
	{
		vector <Nodo> res;
		char *versionArg = new char[version.size() + 1];
		strcpy(versionArg, version.c_str());
		for (int i = 0; i < versiones.size(); i++)
		{
			if(versiones.at(i).getVersion().size() == 7)
				char *versionFiltro = new char[8];
				char *versionFiltro = new char[8];
				strcpy(versionFiltro, versiones.at(i).getVersion().c_str());
				if(versionFiltro[0] == versionArg[0] && versionFiltro[2] == versionArg[2] && versionFiltro[4] < versionArg[4])
				{
					res.push_back(versiones.at(i));
				}
		}
		if(res.empty())
		{
			return n;
		}
		else
		{
			return res.back();
		}
	}
}

//sirve para ----> 1.3/2/2.1

Nodo ControladorCmd::filtro3(vector <Nodo> versiones, string version)
{
	Nodo n;
	if(versiones.empty())
	{
		return n;
	}
	else
	{
		vector <Nodo> res;
		char *versionArg = new char[version.size() + 1];
		strcpy(versionArg, version.c_str());
		for (int i = 0; i < versiones.size(); i++)
		{
			if(versiones.at(i).getVersion().size() == 3)
				char *versionFiltro = new char[4];
				char *versionFiltro = new char[4];
				strcpy(versionFiltro, versiones.at(i).getVersion().c_str());
				if((int)versionArg[0] > (int)versionFiltro[0])
				{
					res.push_back(versiones.at(i));
				}
		}
		if(res.empty())
		{
			return n;
		}
		else
		{
			return res.back();
		}
	}
}


//sirve para 1.3/1.2/1.2.1.1

Nodo ControladorCmd::filtro4(vector <Nodo> versiones, string version)
{
	Nodo n;
	if(versiones.empty())
	{
		return n;
	}
	else
	{
		vector <Nodo> res;
		char *versionArg = new char[version.size() + 1];
		strcpy(versionArg, version.c_str());
		for (int i = 0; i < versiones.size(); i++)
		{
			if(versiones.at(i).getVersion().size() == 3)
				char *versionFiltro = new char[4];
				char *versionFiltro = new char[4];
				strcpy(versionFiltro, versiones.at(i).getVersion().c_str());
				if(versionFiltro[0] == versionArg[0] && versionFiltro[2] > versionArg[2])
				{
					res.push_back(versiones.at(i));
				}
		}
		if(res.empty())
		{
			return n;
		}
		else
		{
			return res.front();
		}
	}
}


//sirve para 1.1.1.3/1.1.1.3/1.1.1.4

Nodo ControladorCmd::filtro5(vector <Nodo> versiones, string version)
{
	Nodo n;
	if(versiones.empty())
	{
		return n;
	}
	else
	{
		vector <Nodo> res;
		char *versionArg = new char[version.size() + 1];
		strcpy(versionArg, version.c_str());
		for (int i = 0; i < versiones.size(); i++)
		{
			if(versiones.at(i).getVersion().size() == 7)
				char *versionFiltro = new char[8];
				char *versionFiltro = new char[8];
				strcpy(versionFiltro, versiones.at(i).getVersion().c_str());
				if(versionFiltro[0] == versionArg[0] && versionFiltro[2] == versionArg[2] && versionFiltro[4] == versionArg[4] && versionFiltro[6] == versionArg[6])
				{
					res.push_back(versiones.at(i));
				}
		}
		if(res.empty())
		{
			return n;
		}
		else
		{
			return res.front();
		}
	}
}


void ControladorCmd::mostrarVersiones()
{
	int longitud = tronco.getVersiones().size();
	for (int i = 0; i < longitud; i++)
	{
		cout << tronco.getVersiones().at(i).getVersion() + "/";
	}
}

void ControladorCmd::obtener(Archivo nombreArchControl, string versiones)
{
	char *versionArg = new char[versiones.size() + 1];
	strcpy(versionArg, versiones.c_str());
	if(versiones.size() == 3 || versiones.size() == 4)
	{
		Nodo n1 = filtro1(tronco.getVersiones(),versiones);
		Nodo n2 = filtro4(tronco.getVersiones(),versiones);
		if(n1.getVersion() != "")
		{
			//--------1.2/1.2/1.3----------//
			//probado
			int num = (int)versionArg[2] - 48 + 1;
			string init = "." + to_string(num);
			Nodo n(nombreArchControl,nombreArchControl);
			n.setVersion(versionArg[0] + init);
			int pos = tronco.posicion(tronco.getVersiones(),n1.getVersion());
			if(tronco.checkNodo(tronco.getVersiones(),n))
			{
				//--------1.3/1.2/1.2.1.1----------//
				//probado
				init = ".1.1";
				n.setVersion(versiones + init);
				int pos = tronco.posicion(tronco.getVersiones(),n1.getVersion());
				if(tronco.checkNodo(tronco.getVersiones(),n) == false)
					tronco.insertNodo(n,pos);
			}
			else
			{
				tronco.insertNodo(n,pos + 1);
			}
		}
		else if(n1.getVersion() == "")
		{
			if(n2.getVersion() != "")
			{
				//--------1.3/1.2/1.2.1.1----------//
				//probado
				string init = ".1.1";
				Nodo n(nombreArchControl,nombreArchControl);
				n.setVersion(versiones + init);
				int pos = tronco.posicion(tronco.getVersiones(),n1.getVersion());
				if(tronco.checkNodo(tronco.getVersiones(),n) == false)
					tronco.insertNodo(n,pos);
			}
			else if(n2.getVersion() == "")
			{
				cout << "No se ha obtenido ningun archivo." << endl;
			}
		}
	}
	else if(versiones.size() == 5)
	{
		Nodo n1 = filtro2(tronco.getVersiones(),versiones);
		if(n1.getVersion() != "")
		{
			//----------1.1.1.2/1.1.2/1.1.2.1---------//
			//probado
			string init = ".1";
			Nodo n(nombreArchControl,nombreArchControl);
			n.setVersion(versiones + init);
			int pos = tronco.posicion(tronco.getVersiones(),n1.getVersion());
			if(tronco.checkNodo(tronco.getVersiones(),n) == false)
				tronco.insertNodo(n,pos + 1);
		}
		else
		{

			cout << "No se ha obtenido ningun archivo." << endl;	
		}
	}
	else if(versiones.size() == 1)
	{
		Nodo n1 = filtro3(tronco.getVersiones(),versiones);
		if(n1.getVersion() != "")
		{
			//---------1.3/2/2.1------------//
			//probado
			string init = ".1";
			Nodo n(nombreArchControl,nombreArchControl);
			n.setVersion(versiones + init);
			int pos = tronco.posicion(tronco.getVersiones(),n1.getVersion());
			if(tronco.checkNodo(tronco.getVersiones(),n) == false)	
				tronco.insertNodo(n,pos + 1);
		}
		else
		{
			cout << "No se ha obtenido ningun archivo." << endl;
		}
	}
	else if(versiones.size() == 7)
	{		
		Nodo n1 = filtro5(tronco.getVersiones(),versiones);
		if(n1.getVersion() != "")
		{
			//-----------1.1.1.3/1.1.1.3/1.1.1.4-------------//
			
			int num = (int)versionArg[6] - 48 + 1;
			string init = "." + to_string(num);
			Nodo n(nombreArchControl,nombreArchControl);
			char *pre_init = new char[5];
			for (int i = 0; i < 5; i++)
			{
				pre_init[i] = versionArg[i];
			}
			n.setVersion(pre_init + init);
			//n.setVersion(versionArg[0] + versionArg[1] +versionArg[2] + versionArg[3] + versionArg[4] + init);
			int pos = tronco.posicion(tronco.getVersiones(),n1.getVersion());
			if(tronco.checkNodo(tronco.getVersiones(),n) == false)
				tronco.insertNodo(n,pos + 1);
		}
		else
		{
			cout << "No se ha obtenido ningun archivo." << endl;
		}
	}
	else
	{
		cout << "No se ha obtenido ningun archivo." << endl;
	}
}
