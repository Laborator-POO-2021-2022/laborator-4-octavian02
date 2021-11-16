#include "Sticla.hpp"

int main()
{
    Sticla *v;

    v = new Sticla[10];

    for (int i = 0; i < 2; i++)
        cin >> v[i];

    cout << endl;

    cout << "Afisare sticle: " << endl;
    for (int i = 0; i < 2; i++)
        cout << v[i];

    for (int i = 0; i < 2; i++)
        cout << v[i].getPret() << " ";

    cout << endl;

    for (int i = 0; i < 1; i++)
        for (int j = i + 1; j < 3; j++)
            if (v[i].getPret() < v[j].getPret())
                v[i].interschimbare(v[j]);

    for (int i = 0; i < 2; i++)
        cout << v[i];

    cout << endl;

    for (int i = 0; i < 2; i++)
        cout << v[i].getPret() << " ";

    cout << endl;


	int d = 5;	
	for( int i = 0; i < 2; i++)
		if( v[i].getDiametru() > d)
			cout << v[i].getMarca() << endl;
	
	delete []v;
	
	return 0;	
}