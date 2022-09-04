#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "planetas.h"

void    map_planet_motion(struct Coordinates *planet, int w, int radio, int orientation);
int     check_planets_alignment(struct Coordinates *planets);
int     cross_product_sign(struct Coordinates point1, struct Coordinates point2);
int     check_sun_inside(struct Coordinates *planet);
double  check_triangle_perimeter(struct Coordinates *points);
double  check_points_distance(struct Coordinates point0, struct Coordinates point1);