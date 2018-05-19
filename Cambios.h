#ifndef __CAMBIOS_H__
#define __CAMBIOS_H__
#include <isotream>
#include <string>
#include <vector>

using namespace std;
class Cambios
{
private:
	vector <string> notas;
	string fecha;  
public:
	Cambios();
	void add(string linea,string texto);
	void del(string linea);
	void insert(string linea);
};

#endif