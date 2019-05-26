#ifndef ROAD_HPP
#define ROAD_HPP

#include "IGameEntity.hpp"
#include "Point.hpp"
#include <iostream>

class Road : public IGameEntity {
  private:
    static const BluePrint blueprint;
    static const EntityType type;
    Point direction;
    mutable bool has_moved;
    Road();

  public:
    Road(Point);
    ~Road();
    Road(Road const &);
    Road &operator=(Road const &);

    void end_turn();
    // getters
    BluePrint const &get_blueprint() const;
    virtual Point get_direction() const;
    Point get_move() const;
    EntityType get_type() const;
    //setters
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
