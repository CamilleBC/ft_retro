#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include "IGameEntity.hpp"
#include "Constants.hpp"
#include "Road.hpp"
#include "Enemy.hpp"
#include "Obstacle.hpp"
#include "Projectile.hpp"
#include "Player.hpp"
#include "Point.hpp"

class RandomGenerator {
  private:
    void spawn_nrandom_entity(EntityType type, IGameEntity ***grid, int nb_spawn);
    void spawn_square(EntityType type, IGameEntity ***grid);
    void spawn_line(EntityType type, IGameEntity ***grid);
    void spawn_road(IGameEntity ***grid, size_t frames);


  public:
    RandomGenerator();
    ~RandomGenerator();
    RandomGenerator(RandomGenerator const &);
    RandomGenerator &operator=(RandomGenerator const &);
    // getters
    int get_rand_int(int n);
    int get_rand_speed();
    Point get_rand_dir();

    //spawners

    void spawn(IGameEntity ***grid, size_t frames);
};

#endif
