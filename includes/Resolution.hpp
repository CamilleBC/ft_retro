/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Resolution.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:56:02 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 09:03:43 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLUTION_HPP
#define RESOLUTION_HPP

typedef struct SResolution {
    unsigned int width;
    unsigned int height;
    SResolution() : width(0), height(0) {}
    SResolution(SResolution const &a) : width(a.width), height(a.height) {}
    SResolution(unsigned int width, unsigned int height)
        : width(width), height(height) {}
} Resolution;

#endif /* RESOLUTION_HPP */
