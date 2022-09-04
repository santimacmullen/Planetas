
#include "funciones.h"

/* Función que mapea las posiciones de los planetas segun su velocidad angular (w) y su radio (r). */
void map_planet_motion(struct Coordinates *planet, int w, int radio, int orientation) {
    int i = 0;

    while(i != LEN_FORECAST){
        planet->x[i] = radio * cos((double) i * w * M_PI / 180);
        planet->y[i++] = radio * sin((double) i * w * M_PI / 180) * orientation;
    }
}

/* Funcion que calcula el alineamiento de los planetas según la distancia entre ellos.
 * En caso de estar alineados, verifica si el sol está en la linea sobre la que se ubican 
 * Se toma un factor de tolerancia de 0.5km de desviación de los planetas a la linea */
int check_planets_alignment(struct Coordinates *planets) {
    double d01, d12, d20, m, b;

    d01 = sqrt(pow(planets[1].x[day] - planets[0].x[day], 2) + pow(planets[1].y[day] - planets[0].y[day], 2));
    d12 = sqrt(pow(planets[2].x[day] - planets[1].x[day], 2) + pow(planets[2].y[day] - planets[1].y[day], 2));
    d20 = sqrt(pow(planets[0].x[day] - planets[2].x[day], 2) + pow(planets[0].y[day] - planets[2].y[day], 2));

    if( d01+d12-d20 < 0.5 || d01+d20-d12 < 0.5 || d12+d20-d01 < 0.5) {
        m = (planets[1].y[day] - planets[0].y[day]) / (planets[1].x[day] - planets[0].x[day]);
        b = (planets[2].y[day] - m * planets[2].x[day]);

        if( abs(b) == 0 ) {
            return ALIGNED_SUN;
        }
        return ALIGNED_NO_SUN;
    }
    return NOT_ALIGNED;
}

double check_points_distance(struct Coordinates point0, struct Coordinates point1){
    double distance;

    distance = sqrt(pow(point1.x[day] - point0.x[day], 2) + pow(point1.y[day] - point0.y[day], 2));

    return distance;
}

/* Funcion que retorna el perimetro de un triangulo dados los 3 puntos que definen sus vértices. */
double check_triangle_perimeter(struct Coordinates *points) {
    double d01, d12, d20;

    d01 = check_points_distance(points[0], points[1]);
    d12 = check_points_distance(points[1], points[2]);
    d20 = check_points_distance(points[2], points[0]);

    return (d01 + d12 + d20);
}

/* Función que calcula el producto vectorial de dos vectores y retorna el signo del vector resultante. */
int cross_product_sign(struct Coordinates point1, struct Coordinates point2) {
    double z;

    z = (point1.x[day] - 0) * (point2.y[day] - 0) - (point1.y[day] - 0) * (point2.x[day] - 0);

    return (z > 0) ? 1 : -1;
    
}

/* Funcion que verifica si el origen de coordenadas esta dentro del triangulo. Retorna 1 por true, 0 por false. */
int check_sun_inside(struct Coordinates *planet) {
    int sign0, sign1, sign2;

    sign0 = cross_product_sign(planet[0], planet[1]);
    sign1 = cross_product_sign(planet[1], planet[2]);
    sign2 = cross_product_sign(planet[2], planet[0]);

    return (sign0 == sign1 && sign1 == sign2);
}