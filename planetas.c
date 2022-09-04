/*
 *        Desafío pronostico climático MercadoLibre
 *        Resuelto por Santiago Mac Mullen
 *        Contacto: santi.macmullen@hotmail.com
 *        27/08/22
 *
 *        < Observaciones >
 *        1- La posicion inicial de los planetas se asume alineados hacia la derecha respecto al sol en el eje X.
 *        2- Dado que un año se determina como el tiempo transcurrido al dar una vuelta al sol, tomo la referencia de los 10 años respecto al año mas lento, de 360 dias.
 */

#include "stdlib.h"
#include "stdio.h"
#include "funciones.h"

int main() {
    struct Coordinates planets[3], *ferengi, *betasoides, *vulcanos;
    struct Prediction prediction;

    ferengi = &planets[0];
    betasoides = &planets[1];
    vulcanos = &planets[2];

    map_planet_motion(ferengi, W_FERENGI, R_FERENGI, CLOCKWISE);
    map_planet_motion(betasoides, W_BETASOIDES, R_BETASOIDES, CLOCKWISE);
    map_planet_motion(vulcanos, W_VULCANOS, R_VULCANOS, COUNTER_CLOCKWISE);

    while(day != LEN_FORECAST) {

        switch(check_planets_alignment(planets)) {
            
            case NOT_ALIGNED:
                if(check_sun_inside(planets)) {
                    prediction.rain++;

                    if(check_triangle_perimeter(planets) > prediction.peak_value) {
                        prediction.peak_day = day;
                        prediction.peak_value = check_triangle_perimeter(planets);
                    }
                }
                break;

            case ALIGNED_NO_SUN:
                prediction.optimum++;
                break;

            case ALIGNED_SUN:
                prediction.drought++;
                break;

            default:
                prediction.error++;
                break;
            }
        day++;
    }

    if( prediction.error != 0){
        printf("La prediccion tuvo errores. Disculpe las molestias.\n");
        return 0;
    }
    
    printf("\nEl resultado de la predicción es el siguiente:\n");
    printf(" - Cantidad de días de condiciones óptimas: %d\n", prediction.optimum);
    printf(" - Cantidad de días de sequía: %d\n", prediction.drought);
    printf(" - Cantidad de días de lluvia: %d\n", prediction.rain);
    printf(" - Día pico de lluvia: %d\n\n", prediction.peak_day);
    
    return 0;
}