/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:49:12 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/01 15:49:12 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _MaxSize(n) {}

Span::Span(const Span& other) : _Numbers(other._Numbers), _MaxSize(other._MaxSize){}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _MaxSize = other._MaxSize;
        _Numbers = other._Numbers;
    }
    return *this;
}

Span::~Span() {}

void    Span::addNumber(int number) {
    if (_Numbers.size() >= _MaxSize)
        throw OutOfSize();
    _Numbers.push_back(number);
}

int     Span::shortestSpan() const{
    
    if (_Numbers.size() < 2)
        throw NoSpanFound();
    std::vector<int> tmp = _Numbers;
    std::sort(tmp.begin(), tmp.end());
    long long shortest = LLONG_MAX;
    std::size_t i = 1;
    while(i < tmp.size())
    {
        long long diff = static_cast<long long>(tmp[i]) - static_cast<long long>(tmp[i-1]);
        if (diff < shortest)
            shortest = diff;
        i++;
    }
    return static_cast<int>(shortest);
}

int Span::longestSpan() const {
    if (_Numbers.size() < 2)
        throw NoSpanFound();

    std::vector<int> tmp = _Numbers;
    std::sort(tmp.begin(), tmp.end());

    long long diff = static_cast<long long>(tmp.back()) - static_cast<long long>(tmp.front());
    return static_cast<int>(diff);
}

