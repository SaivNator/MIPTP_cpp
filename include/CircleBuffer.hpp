//CircleBuffer.hpp
//Author: Sivert Andresen Cubedo
#pragma once
#ifndef CircleBuffer_HEADER
#define CircleBuffer_HEADER

#include <array>
#include <iterator>

template <typename T, std::size_t S>
class CircleBuffer
{
public:
	/*
	Constructor.
	*/
	CircleBuffer() :
		m_head(0),
		m_tail(0)
	{
	}

	/*
	Push element on head.
	Parameters:
		element
	Return:
		void
	*/
	void push(T element)
	{

	}

	/*
	Pop tail.
	Parameters:
	Return:
		void
	*/
	void pop();

	/*
	Get element at index.
	Parameters:
		index
	Return:
		reference to element
	*/
	T & get(std::size_t index);

	/*
	Get index of head.
	Parameters:
	Return:
		index of head
	*/
	typename std::array<T, S>::iterator getHead()
	{
		return m_data.begin() + m_head;
	}

	/*
	Get index of tail.
	Parameters:
	Return:
		index of tail
	*/
	typename std::array<T, S>::iterator getTail()
	{
		return m_data.begin() + m_tail;
	}

	/*
	Get distance between tail and head.
	Parameters:
	Return:
		number of elements
	*/
	std::size_t size()
	{
		return m_size;
	}

	/*
	Clear buffer.
	Parameters:
	Return:
		void
	*/
	void clear()
	{
		m_tail = m_head;
	}

	/*
	Check if empty.
	Parameters:
	Return:
		true if empty, else false
	*/
	bool empty() 
	{
		return m_head == m_tail;
	}
private:
	std::array<T, S> m_data;
	//std::array<bool, S> m_used;
	std::size_t m_size;
	std::size_t m_head;
	std::size_t m_tail;
};

#endif // !CircleBuffer_HEADER
