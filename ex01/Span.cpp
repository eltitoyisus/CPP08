/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:12:56 by jramos-a          #+#    #+#             */
/*   Updated: 2025/08/27 09:12:56 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _array(NULL), _current(0) {}

Span::Span(unsigned int N) : _N(N), _current(0) {
	_array = new int[N];
}

Span::Span(const Span &other) : _N(other._N), _current(other._current) {
	_array = new int[_N];
	for (unsigned int i = 0; i < _current; ++i) {
		_array[i] = other._array[i];
	}
}

Span& Span::operator=(const Span &other) {
	if (this != &other) {
		delete[] _array;
		_N = other._N;
		_current = other._current;
		_array = new int[_N];
		for (unsigned int i = 0; i < _current; ++i) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

Span::~Span() {
	delete[] _array;
}

void Span::addNumber(int number) {
	if (_current >= _N)
		throw SpanFullException();
	_array[_current] = number;
	_current++;
}

int Span::shortestSpan() {
	if (_current <= 1)
		throw NoSpanFoundException();
	int minSpan = INT_MAX;
	for (unsigned int i = 0; i < _current - 1; i++) {
		for (unsigned int j = i + 1; j < _current; j++) {
			int span = abs(_array[i] - _array[j]);
			if (span < minSpan)
				minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan() {
	if (_current <= 1)
		throw NoSpanFoundException();
	int min = _array[0];
	int max = _array[0];
	for (unsigned int i = 1; i < _current; i++) {
		if (_array[i] < min)
			min = _array[i];
		if (_array[i] > max)
			max = _array[i];
	}
	return max - min;
}
