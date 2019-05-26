#include "RandomGenerator.hpp"

RandomGenerator::RandomGenerator() {}

RandomGenerator::~RandomGenerator() {}

RandomGenerator::RandomGenerator(RandomGenerator const &a) { *this = a; }

RandomGenerator &RandomGenerator::operator=(RandomGenerator const &rhs) {
	(void)rhs;
	return *this;
}

int RandomGenerator::get_rand_int(int n) { return ((int)((rand() / (double)RAND_MAX) * n)); }

Point RandomGenerator::get_rand_dir(){
	int sign1 = (get_rand_int(2)) * 2 - 1;
	//   int sign2 = ((int)((rand() / (double)RAND_MAX) * 2)) * 2 - 1;
	int value1 = sign1 * get_rand_int(3);
	int value2 = get_rand_int(2) + 1;

	return (Point(value1, value2));
}

int RandomGenerator::get_rand_speed() { return (get_rand_int(20)); }

void RandomGenerator::spawn_nrandom_entity(EntityType type, IGameEntity *grid[GRID_HEIGHT][GRID_WIDTH], int nb_spawn)
{
	int speed;

	speed = 1;
	switch (type) {
	case enemy :
		for (int i = 0; i < nb_spawn; ++i) 
		{
			grid[get_rand_int(GRID_HEIGHT / 20)][get_rand_int(GRID_WIDTH)] = new Enemy(get_rand_dir());
		}
		break;
	case player :
		break;
	case projectile :
		break;
	case obstacle :
		for (int i = 0; i < nb_spawn; ++i) 
		{
			grid[get_rand_int(GRID_HEIGHT / 20)][get_rand_int(GRID_WIDTH)] = new Obstacle(get_rand_dir(), get_rand_speed());
		}
		break;
	default:
		break;
    }
}

void RandomGenerator::spawn_square(EntityType type, IGameEntity *grid[GRID_HEIGHT][GRID_WIDTH])
{
	int speed;
	int rand;

	rand = get_rand_int(GRID_WIDTH - 3);
	speed = 1;
	switch (type) {
	case enemy :
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                grid[i][rand + j] = new Enemy(Point(0, 1));
            }
        }
		break;
	case player :
		break;
	case projectile :
		break;
	case obstacle :
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                grid[i][rand + j] = new Obstacle(Point(0, 1), get_rand_speed());
            }
        }
		break;
	default:
		break;
    }
}

void RandomGenerator::spawn_line(EntityType type, IGameEntity *grid[GRID_HEIGHT][GRID_WIDTH])
{
	int speed;

	speed = 1;
	switch (type) {
	case enemy :
       	for (size_t i = 0; i < GRID_WIDTH; ++i) {
            grid[0][i] = new Enemy(Point(0, 1));
        }
		break;
	case player :
		break;
	case projectile :
		break;
	case obstacle :
 		for (size_t i = 0; i < GRID_WIDTH; ++i) {
            grid[0][i] = new Obstacle(Point(0, 1), get_rand_speed());
        }
		break;
	default:
		break;
    }
}

void RandomGenerator::spawn(IGameEntity *grid[GRID_HEIGHT][GRID_WIDTH], size_t frames)
{
	int rand;
	static int diff = 1;

	rand = get_rand_int(frames / 6);
	if (frames % 1000 == 0)
	{
		if (diff < 100)
			diff++;
		if (rand % (1 + diff))
			spawn_line(enemy, grid);
		else
			spawn_line(obstacle, grid);
	}
	if ((frames % (100 / diff)))
		return ;
	if (rand > 10)
	{
		if (rand % (1 + diff))
			spawn_nrandom_entity(enemy, grid, rand / 10);
		else
			spawn_nrandom_entity(obstacle, grid, rand / 10);
	
	}

	if (rand > 20 && !(rand % 3) && !(frames % 3))
	{
		if (rand % (1 + diff))
			spawn_square(enemy, grid);
		else
			spawn_square(obstacle, grid);
	}
}
