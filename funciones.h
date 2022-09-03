#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "planetas.h"

void    map_planet_motion(struct Coordinates *planet, int w, int radio, int orientation);
int     check_planets_alignment(struct Coordinates *planets);
int     check_sun_alignment(struct Coordinates *planets);
int     cross_product_sign(struct Coordinates point1, struct Coordinates point2);
int     check_sun_inside(struct Coordinates *planet);
int     check_status(struct Coordinates *planet);
double  check_triangle_area(struct Coordinates *point);
double  check_triangle_perimeter(struct Coordinates *point);
double  calculate_linear_coefficient(struct Coordinates *planets);
double  calculate_sun_linear_coefficient(struct Coordinates *planets);