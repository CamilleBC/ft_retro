/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:17 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 01:20:13 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

typedef struct point {
    int x;
    int y;
    point() : x(0), y(0) {}
    point(int c_x, int c_y) : x(c_x), y(c_y) {}
    point(point const &a) : x(a.x), y(a.y) {}
} Point;

#endif /* POINT_HPP */
