#pragma once
#include <iostream>
#include <assert.h>
#define N 100
using namespace std;


namespace geometrie {
	template <class t >
	class Vector
	{
	private:
		t vect[N];
        int taille;
	public:
		Vector();
		//imposible d'utiliser cette methode et meme le constructeur de recopie par defaut
		Vector(const Vector&) = delete;
		Vector& operator=(const Vector) = delete;
		void print() ;
		t at(unsigned int indice) ;
		bool operator==(const Vector& v);
		bool operator!=(const Vector& v) ;
		t& operator[](unsigned int indice);
        void push(t a);
		




	};

};
template<class t>
geometrie::Vector<t>::Vector()
{
    
    this->taille = 0;
}
template<class t>
void geometrie::Vector<t>::print() 
{
    for (int i = 0; i < this->taille; i++) {
        cout << "vecteur[" << i << "]=" << this->at(i) << endl;
    }
}
template<class t>
t geometrie::Vector<t>::at(unsigned int indice)
{
    assert(indice >= 0 && indice < 3);//debug
    try//release
    {
        if (indice < 0 || indice >= 3) throw"rang error";
        return this->vect[indice];
    }
    catch (char* e) {
        cout << e << endl;
    }

}

template<class t>
bool geometrie::Vector<t>::operator==(const Vector& v)
{
    bool res = true;
    for (int i = 0; i < 3; i++)
    {
        res = res && (this->at(i) == v.at(i));
    }
    return res;
}

template<class t>
bool geometrie::Vector<t>::operator!=(const Vector& v)
{
    bool res = !(*this == v);

    return res;
}

template<class t>
t& geometrie::Vector<t>::operator[](unsigned int indice)
{
    assert(indice >= 0 && indice < 3);//debug
    try//release
    {
        if (indice < 0 || indice >= 3) throw"rang error";
        return this->vect[indice];
    }
    catch (char* e) {
        cout << e << endl;
    }
}

template<class t>
 void geometrie::Vector<t>::push(t a)
{
     this->vect[this->taille] = a;
     this->taille++;
}


