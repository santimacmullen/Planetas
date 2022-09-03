
/***************   Datos de entrada  **************/

/* Velocidades angulares en [grados/s]. */
#define W_FERENGI           1
#define W_BETASOIDES        3
#define W_VULCANOS          5

/* Radios en [km]. */
#define R_FERENGI           500
#define R_BETASOIDES        2000
#define R_VULCANOS          1000

/* Sentido del giro. */
#define CLOCKWISE           -1
#define COUNTER_CLOCKWISE   1

/* Cantidad de dias a futuro para realizar el pronostico. */
#define LEN_FORECAST      3600

/*************  Tipos de datos  ****************/

struct Prediction{
    int drought;            /* Sequia */
    int rain;               /* Lluvia */
    int peak_day;           /* Pico de lluvia */
    int peak_value;         /* Pico previo de lluvia */
    int optimum;            /* Condiciones óptimas */
    int error;              /* Checkeo de error en prediccion */
};

struct Coordinates{
    double x[LEN_FORECAST];
    double y[LEN_FORECAST];
};

int day;      /* Variable Global */

/************  Defines internos  **************/

#define NOT_ALIGNED     0
#define ALIGNED_NO_SUN  1
#define ALIGNED_SUN     2

#define COEF_PRECISION  1