/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BluePrint.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:56:41 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 21:54:07 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Constants.hpp>
#include <cstddef>
#include <string>

#ifndef BLUEPRINT_HPP
#define BLUEPRINT_HPP

typedef struct bluePrint {
    std::string *texture;
    size_t size;
    int colour_pair;
    bluePrint() : texture(NULL), size(0), colour_pair(SPACE_PAIR) {}
    bluePrint(bluePrint const &other)
        : texture(other.texture), size(other.size),
          colour_pair(other.colour_pair) {}
    bluePrint(std::string *texture, size_t size, int colour_pair)
        : texture(texture), size(size), colour_pair(colour_pair) {}
    ~bluePrint() {
        delete texture;
        texture = NULL;
    }
} BluePrint;

#endif /* BLUEPRINT_HPP */
