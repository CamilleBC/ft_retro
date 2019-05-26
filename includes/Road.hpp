#ifndef ROAD_HPP
#define ROAD_HPP

#include "BluePrint.hpp"
#include "Constants.hpp"
#include "Enemy.hpp"
#include "IGameEntity.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "Projectile.hpp"
#include <iostream>

class Road : public IGameEntity {
  private:
    static const int colour;
    static const BluePrint blueprint;
    static const EntityType type;
    Point direction;
    int max_speed;
    mutable int speed;
    Road();

  public:
    Road(Point, int);
    ~Road();
    Road(Road const &);
    Road &operator=(Road const &);

    // getters
    BluePrint const &get_blueprint() const;
    virtual Point get_direction() const;
    Point get_move() const;
    EntityType get_type() const;
    // setters
    void set_direction(Point dir);
    // collision
    IGameEntity *collide(IGameEntity *);
    IGameEntity *get_collided(Obstacle *);
    IGameEntity *get_collided(Projectile *);
    IGameEntity *get_collided(Enemy *);
    IGameEntity *get_collided(Player *);
    IGameEntity *get_collided(Road *e);
};

#endif /* Road_HPP */
