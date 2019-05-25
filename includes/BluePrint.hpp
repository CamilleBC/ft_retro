/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BluePrint.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:56:41 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 14:07:22 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <string>

#ifndef BLUEPRINT_HPP
#define BLUEPRINT_HPP

typedef struct bluePrint {
    std::string *texture;
    size_t size;
    bluePrint() : texture(NULL), size(0) {}
    bluePrint(bluePrint const &other)
        : texture(other.texture), size(other.size) {}
    bluePrint(std::string *texture, size_t size)
        : texture(texture), size(size) {}
    ~bluePrint() {
        delete texture;
        texture = NULL;
    }
} BluePrint;

#endif /* BLUEPRINT_HPP */
