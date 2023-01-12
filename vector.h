#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Vector
{
public:
	Vector();
	~Vector();
public:
	void set_size(int);
	int get_size() const;
	void set_capacity(int);
	int get_capacity() const;
	void set_arr(T*, int);
	T* get_arr() const;
public:	
	void push_back(T);
	void pop_back();
	void resize();
	bool empty();
	int length() const;
	T& at(int);
	void clear();
	void insert(int, T);
	void erase(int);
	void swap(Vector&);
	T* data() const;
	T begin() const;
	T end() const;
	int capacity() const; 
	void print();
public:	
	Vector(T*, int);
	Vector(int, int);
	Vector(const Vector<T>&);
	Vector(Vector<T>&&);
	const T& operator[](int);
	Vector& operator=(const Vector<T>&);
	Vector& operator=(Vector<T>&&);
	bool operator==(Vector<T>&);
	bool operator!=(Vector<T>&);
	bool operator>(const Vector<T>&);
	bool operator<(const Vector<T>&);
	bool operator>=(const Vector<T>&);
	bool operator<=(const Vector<T>&);
private:
	int v_capacity;
	int v_size;
	T* v_arr;
};
#endif // VECTOR_H
