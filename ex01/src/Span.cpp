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

Span::Span(const Span& other) : _MaxSize(other._MaxSize), _numbers(other._numbers) {}

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