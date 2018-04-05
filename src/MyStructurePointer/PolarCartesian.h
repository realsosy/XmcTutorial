typedef struct polar {
    float mag;
    float angle;
} polar_t;

typedef struct xy {
    float x;
    float y;
} xy_t;

void xy2polar(xy_t *param_xy, polar_t *param_polar);

void polar2xy(polar_t *param_polar, xy_t *param_xy);
