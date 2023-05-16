/*je met toute les bibliotheque au meme endroit
pour simplifer le code et eviter qu'une bibli apparaisse 2 fois
===== > est ce que la problematique des constructeur ne se resume pas dans le 
 que si j'ai deja utilise par exemple le construc Vector(int) pour une 
fonction type je ne pourais pas lutilise pour une autre chose ? 
alors qu'avec les fonction je le peux
*/
#pragma once 
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

class Vector
{
private:
	int* data ;
	int capacity;
	int size;
public:
	Vector(int requested_size = 2); // constructor ok 
	Vector strnewcat(Vector a); // connexion ok 
	Vector(const Vector& V); // copy constructor ok
	void assign(const Vector& V); 
	~Vector(); // destructeur ok 
	int getCapacity(){return capacity;} //ok 
	int getSize(); // ok 
	void print() const; //ok  
	bool isEqual(Vector a); // ok 
	int& at(int index); // at ok 
	int scalmul(Vector); // scalmul ok  
	void delLast(); //dellast ok  
	void insert(int b); //insert 
	void clear(); 


}; 


