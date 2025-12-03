/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:26:46 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/01 14:26:46 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <exception>
#include <algorithm>
#include <climits>
#include <iostream>

class Span {
    private :
        std::vector<int>    _Numbers;
        unsigned int        _MaxSize;
    public :
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        
        void    addNumber(int number);
        int     shortestSpan() const;
        int     longestSpan() const;

        template <typename InputIt>
        void addNumbers(InputIt first, InputIt last);
};


class OutOfSize : public std::exception {
    public :
    virtual const char* what() const throw() {
        return "size reached !";
    }
};

class NoSpanFound : public std::exception {
    public :
    virtual const char* what() const throw() {
        return "No number or only one in this span !";
    }
};

template <typename InputIt>
void Span::addNumbers(InputIt first, InputIt last) {
    while(first != last) {
        addNumber(static_cast<int>(first));
        ++first;
    }
}

#endif