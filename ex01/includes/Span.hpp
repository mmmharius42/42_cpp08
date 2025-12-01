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
        int     shortestSpan();
        int     longestSpan();
};

class OutOfSize : public std::exception {
    public :
        virtual const char* what() const throw() {
            return "size reached !";
        }
};

class NoSpanFound : public std::exception {
    public :
        virtual const char* chat() const throw() {
            return "No number or only one in this span !";
        }
};

#endif