
#include "Vector.h"

Vector::Vector(int requested_size)
{ 
	int z = pow(2, ceil(log(requested_size) / log(2)));; 
	data = new int[z]; 
	capacity = z; 
	size = 0; 
}

Vector Vector::strnewcat(Vector a)
{
	int z = capacity + a.capacity; 
	Vector v1(pow(2, ceil(log(z) / log(2))));
	v1.size = size + a.size; 
	int p = 0; 
	for (size_t i = 0; i < size; i++)
	{
		v1.data[i] = data[i];
		p++; 
	}
	int j = 0; 
	for (int i = p; j<a.size; i++)
	{
		v1.data[i] = a.data[j]; 
		j++; 
	}
	return v1; 
}

void Vector::insert(int val)
{
	if (size == capacity)
	{
		int newCapacity = 2 * capacity;
		int* newArr = new int[newCapacity];
		for (int i = 0; i < size; i++)
		{
			newArr[i] = data[i];
		}
		newArr[size] = val;
		data = newArr;
		capacity = newCapacity;
		size++;
	}
	else
	{
		data[size] = val;
		size++;
	}
}

void Vector::clear()
{
	size = 0; 
}

Vector::Vector(const Vector& V)
{
	capacity = V.capacity; 
	size = V.size;
	data = new int[capacity];
	for (int i= 0; i < size; i++)
	{
		data[i] = V.data[i];
	}
}

Vector::~Vector()
{
	if (size) delete[] data; 
}

void Vector::assign(const Vector& v)
{
	size = v.size; 
	capacity = v.capacity;
	delete[] data; // important de faire ca ; 
	data = new int[capacity]; 
	for (int i = 0; i < size; i++)
	{
		data[i] = v.data[i];
	}
}


int Vector::getSize()
{
	return size;
}

void Vector::print() const
{
	cout << "capacity: " << capacity << " size: " << size << " value: " ; 
	for (int i = 0; i < size; i++)
		cout << data[i] << ' ';
	cout << endl; 

}



bool Vector::isEqual(Vector a)
{
	if (size != a.size)
		return false; 
	for (int i = 0; i < size; i++)
	{
		if (data[i] != a.data[i])
			return false;
	}
		return true;
}

int& Vector::at(int index)
{
	if (index > size || index < 0)
	{
		cout << "ERROR" << endl;
		return data[0] ; 
	}
	return data[index]; 
}

int Vector::scalmul(Vector a)
{
	if(size != a.size)
	return -1;
	int p = 0; 
	for (int i = 0; i < size; i++)
	{
		p += (data[i] * a.data[i]); 
	}
	return p; 
}

void Vector::delLast()
{
	if (size == 0)
	{
		cout << "ERROR" << endl;
		return;
	}
	else size--; 
}





//
//Vector::Vector(Vector a, Vector b)
//{   //strnewcat does't exist in this version of c++ 
//	//strcat(a, b); 
//	int x = a.capacity + b.capacity; 
//	int z = pow(2, ceil(log(x) / log(2)));
//	Vector c();
//
//}
//


