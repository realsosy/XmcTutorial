#include <math.h>
#include "PolarCartesian.h"

void xy2polar(xy_t *param_xy, polar_t *param_polar){
    param_polar->mag = sqrt(pow(param_xy->x,2.0) + pow(param_xy->y,2.0));
    param_polar->angle = atan(param_xy->y / param_xy->x);
    return;
}

void polar2xy(polar_t *param_polar, xy_t *param_xy){



}

