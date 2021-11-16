#include "Dop.hpp"

Dop::Dop() : diametru(0), tip(NULL)
{
    std::cout << "Dop: Constructor fara parametri\n";
}

Dop::Dop(int diametru, const char *tip) : diametru(diametru)
{
    this->tip = new char[strlen(tip) + 1];
    strcpy(this->tip, tip);
}

Dop::Dop(const Dop &obj)
{
    tip = NULL;
    *this = obj;
}

Dop::~Dop()
{
    delete[] tip;
}

Dop &Dop::operator=(const Dop &obj)
{
    if (this != &obj)
    {
        if (tip != NULL)
            delete[] tip;

        if (obj.tip == NULL)
            tip = NULL;
        else
        {
            this->tip = new char[strlen(obj.tip) + 1];
            strcpy(this->tip, obj.tip);
        }
        diametru = obj.diametru;
    }

    return *this;
}

ostream& operator<<(ostream& out, const Dop& obj)
{
	out << "Tip: ";
	if(obj.tip != NULL)
		out << obj.tip;
	out << endl << "Diametru: " << obj.diametru << endl;
	
	return out;
}

istream& operator>>(istream& in, Dop& obj)
{
	cout << "Date dop: " << endl;
	cout << "Diametrul: ";
	in >> obj.diametru;
	char buffer[100];
	cout << "Tip : ";
	in >> buffer;
	if ( obj.tip != NULL)
		delete []obj.tip;
	obj.tip = new char[strlen(buffer) + 1];
	strcpy(obj.tip,buffer);
	
	return in;
}

int Dop::getDiametru()
{
    return diametru;
}

char *Dop::getTip()
{
    return tip;
}

void Dop::interschimbare(Dop& v)
{
	Dop aux(*this);
	*this = v;
	v = aux;
}