/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BluePrint.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:56:41 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 10:18:31 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <string>

#ifndef BLUEPRINT_HPP
#define BLUEPRINT_HPP

typedef struct bluePrint {
    std::string *content;
    size_t size;
    bluePrint() : content(NULL), size(0) {}
    bluePrint(bluePrint const &other)
        : content(other.content), size(other.size) {}
    bluePrint(std::string *content, size_t size)
        : content(content), size(size) {}
    ~bluePrint() {
        delete[] content;
        content = NULL;
    }
} BluePrint;

#endif /* BLUEPRINT_HPP */
