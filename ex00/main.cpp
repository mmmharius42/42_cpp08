/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:25:58 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/01 14:25:58 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    //vector test
    std::vector<int> test1;
    test1.push_back(1);
    test1.push_back(2);
    try {
        std::vector<int>::iterator it = easyfind(test1, 4);
        std::cout << "Find : " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    //list test
    std::list<int> test2;
    test2.push_back(1);
    test2.push_back(2);
    try {
        std::list<int>::iterator it = easyfind(test2, 1);
        std::cout << "Find : " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    //deque
    std::deque<int> test3;
    test3.push_back(1);
    test3.push_back(42);
    try {
        std::deque<int>::iterator it = easyfind(test3, 42);
        std::cout << "Find : " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}