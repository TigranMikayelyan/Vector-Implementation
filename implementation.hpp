#include "vector.h"

template <typename T>
Vector<T>::Vector()
{
	v_capacity = 5;
	v_size = 0;
	v_arr = new T[v_capacity];
}

template <typename T>
Vector<T>::~Vector()
{
	v_capacity = 0;
	v_size = 0;
	delete[] v_arr;
	v_arr = nullptr;
}

template <typename T>
Vector<T>::Vector(T* arr, int arr_size)
{
	v_size = arr_size;
	delete[] v_arr;
	v_arr = new T[v_size + 1];
	for (int i = 0; i < arr_size; ++i)
	{
		v_arr[i] = arr[i];
	}
}

template <typename T>
Vector<T>::Vector(int size, int capacity)
{
	this->v_size = size;
	this->v_capacity = capacity;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) 
{ 
	this->v_size = other.v_size;	
	this->v_capacity = other.v_capacity; 
	delete[] this->v_arr;
	this->v_arr = new T[this->v_capacity];
	for (int i = 0; i < v_size; ++i)
	{
		this->v_arr[i] = other.v_arr[i];
	}
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other)
{
	this->v_size = other.v_size;	
	this->v_capacity = other.v_capacity; 
	this->v_arr = other.v_arr;
	other.v_size = 0;
	other.v_capacity = 0;
	other.v_arr = nullptr;
}

template <typename T>
const T& Vector<T>::operator[](int index) const
{
	if (index >= v_size && index < 0)
	{
		std::out_of_range("Invalid index!!!");
	}
	return v_arr[index];
}

template <typename T>
T& Vector<T>::operator[](int index)
{
	if (index >= v_size && index < 0)
	{
		std::out_of_range("Invalid index!!!");
	}
	return v_arr[index];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	delete[] v_arr;
	v_size = rhs.v_size;
	v_capacity = rhs.v_capacity;
	v_arr = new T[v_capacity];
	for (int i = 0; i < v_size; ++i)
	{
		v_arr[i] = rhs.v_arr[i];
	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	v_size = rhs.v_size;
	v_capacity = rhs.v_capacity;
	v_arr = rhs.v_arr;
	rhs.v_size = 0;
	rhs.v_capacity = 0;
	rhs.v_arr = nullptr;
	return *this;
}

template <typename T>
bool Vector<T>::operator==(Vector<T>& rhs)
{
	if (v_size != rhs.v_size)
	{
		return false;
	}
	for (int i = 0; i < v_size; ++i)
	{
		if (v_arr[i] != rhs.v_arr[i])
		{
			return false;
		}
	}
	return true;
}

template <typename T>
bool Vector<T>::operator!=(Vector<T>& rhs)
{
	if (v_size != rhs.v_size)
	{
		return true;
	}
	for (int i = 0; i < v_size; ++i)
	{
		if (v_arr[i] != rhs.v_arr[i])
		{
			return true;
		}
	}
	return false;
}

template <typename T>
bool Vector<T>::operator>(const Vector<T>& rhs)
{
	if (v_size > rhs.v_size)
	{
		return true;
	}
	for (int i = 0; i < v_size; ++i)
	{
		if (v_arr[i] > rhs.v_arr[i])
		{
			return true;
		}
	}
	return false;

}

template <typename T>
bool Vector<T>::operator<(const Vector<T>& rhs)
{
	if (v_size < rhs.v_size)
	{
		return true;
	}
	for (int i = 0; i < v_size; ++i)
	{
		if (v_arr[i] < rhs.v_arr[i])
		{
			return true;
		}
	}
	return false;
}

template <typename T>
bool Vector<T>::operator>=(const Vector<T>& rhs)
{
	if (v_size < rhs.v_size)
	{
		return false;
	}
	for (int i = 0; i < v_size; ++i)
	{
		if (v_arr[i] < rhs.v_arr[i])
		{
			return false;
		}
	}
	return true;

}

template <typename T>
bool Vector<T>::operator<=(const Vector<T>& rhs)
{
	if (v_size > rhs.v_size)
	{
		return false;
	}
	for (int i = 0; i < v_size; ++i)
	{
		if (v_arr[i] > rhs.v_arr[i])
		{
			return false;
		}
	}
	return true;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& arr)
{
	for (int i = 0; i < arr.v_size; ++i)
	{
		os << arr[i] << " ";
	}
	return os;
}

template <typename T>
void Vector<T>::push_back(T elem)
{
	if (v_size == v_capacity)
	{
		resize();
	}
	v_arr[v_size++] = elem;
}

template <typename T>
void Vector<T>::pop_back()
{
	if (empty())
	{
		return;
	}
	else
	{
		v_arr[v_size--] = 0;
	}
}

template <typename T>
void Vector<T>::resize()
{
	v_capacity *= 2;
	T* tmp = new T[v_capacity];
	for (int i = 0; i < v_size; ++i)
	{
		tmp[i] = v_arr[i];
	}
	delete[] v_arr;
	v_arr = tmp;
}

template <typename T>
bool Vector<T>::empty()
{
	return !(v_size);
}

template <typename T>
int Vector<T>::length() const
{
	return v_size;
}

template <typename T>
T& Vector<T>::at(int index)
{
	if (empty())
	{
		delete[] v_arr;
		v_arr = nullptr;
	}
	for (int i = 0; i < v_size; ++i)
	{
		if (i == index)
		{
			return v_arr[i];
		}
	}
	throw std::out_of_range("Invalid index!!!");
}	

template <typename T>
void Vector<T>::clear()
{
	if (!v_size)
	{
		return;
	}
	else
	{
		v_size = 0;
		v_arr[v_size] = 0;
	}
}

template <typename T>
void Vector<T>::insert(int index, T element)
{
	if (v_size <= v_capacity)
	{
		for (int i = v_size; i > index; --i)
		{
			v_arr[i] = v_arr[i - 1];
		}
		v_arr[index] = element;
	}
	else
	{
		v_capacity *= 2;
		T* tmp = new T[v_capacity];
		for (int i = 0; i < index; ++i)
		{
			tmp[i] = v_arr[i];
		}
		tmp[index] = element;
		for (int i = 0; i < v_size; ++i)
		{
			tmp[i + 1] = v_arr[i];
		}
		delete[] v_arr;
		v_arr = tmp;
		tmp = nullptr;
	}
	++v_size;
}

template <typename T>
void Vector<T>::erase(int index)
{
	if (empty())
	{
		delete[] v_arr;
		v_arr = nullptr;
	}
	else
	{
		T* new_v_arr = new T[v_size - 1];
		for (int i = 0; i < v_size; ++i)
		{
			if (i < index)
			{
				new_v_arr[i] = v_arr[i];
			}
			if (i >= index)
			{
				new_v_arr[i] = v_arr[i + 1];
			}
		}
		delete[] v_arr;
		v_arr = new T[v_size - 1];
		for (int i = 0; i < v_size - 1; ++i)
		{
			v_arr[i] = new_v_arr[i];
		}
		v_size -= 1;
		delete[] new_v_arr;
		new_v_arr = nullptr;
	}
}

template <typename T>
void Vector<T>::swap(Vector& oth)
{
	if (empty())
	{
		delete[] v_arr;
		v_arr = nullptr;
		return;
	}
	else
	{
		T* tmp_arr = oth.v_arr;
		int tmp_size = oth.v_size;
		int tmp_capacity = oth.v_capacity;
		oth.v_arr = v_arr;
		oth.v_size = v_size;
		oth.v_capacity = v_capacity;
		v_arr = tmp_arr;
		v_size = tmp_size;
		v_capacity = tmp_capacity;
	}
}

template <typename T>
T* Vector<T>::data() const
{
	return v_arr;
}

template <typename T>
T Vector<T>::begin() const
{
	return v_arr[0];
}

template <typename T>
T Vector<T>::end() const
{
    return v_arr[--v_size];
}

template <typename T>
int Vector<T>::capacity() const
{
	return v_capacity;
}

template <typename T>
void Vector<T>::set_size(int size)
{
	this->v_size = size;
}

template <typename T>
int Vector<T>::get_size() const
{
	return v_size;
}

template <typename T>
void Vector<T>::set_capacity(int capacity)
{
	this->v_capacity = capacity;
}

template <typename T>
int Vector<T>::get_capacity() const
{
	return v_capacity;
}

template <typename T>
void Vector<T>::set_arr(T* arr, int arr_size)
{
	delete[] v_arr;
	v_arr = new T[arr_size + 1];
	for (int i = 0; i < v_size; ++i)
	{
		v_arr[i] = arr[i];
	}
}

template <typename T>
T* Vector<T>::get_arr() const
{
	return v_arr;
}

template <typename T>
void Vector<T>::print()
{
	for (int i = 0; i < v_size; ++i)
	{
		std::cout << v_arr[i] << std::endl;
	}
}
