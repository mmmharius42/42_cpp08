/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:26:46 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/01 14:26:46 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

class NotFound : public std::exception {
    public :
        const char *what() const throw() {
            return ("Not found in containers");
        }
};

template <typename T>
typename T::iterator easyfind(T& containers, int elements) {
    typename T::iterator it = std::find(containers.begin(), containers.end(), elements);
    if (it == containers.end())
        throw NotFound();
    return it;
};

#endif