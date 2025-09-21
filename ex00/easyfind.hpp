/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:30:56 by jramos-a          #+#    #+#             */
/*   Updated: 2025/08/12 09:30:56 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
w
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

// T is a container of integers
template <typename T>
typename T::const_iterator easyFind(const T& container, int i) {
	typename T::const_iterator it = std::find(container.being(), container.end(), i);
	// find first occurence of the second paramater in the first paramater
	if (it == container.end()) {
		throw std::exception("Value not found");
	}
	// if no occourrence is found throw exceptiion with a value
	return it;
}

#endif
