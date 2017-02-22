#include "selfprot.h"

/* Convert the fixed point number to float */
#define itf(x) ((float)(x/10.0))
/* Square the parameter */
#define multi(x) x*x
/* Square of cuboid diagonal */
#define sqCubDiag(a, b, c) (multi(itf(a))+multi(itf(b))+multi(itf(c)))

/*
 * Function: CalculateSystemState
 * --------------------------------------------
 * calculate the system state based on environment data and
 * stores the calculated state in the caught data structure
 *
 * env: contains environment data and calculated state will be stored in it
 */
void CalculateSystemState(EnvironmentData *env) {
    /* Store different problems existence in different bit of this variable */
	char problems = 0;

	/* If acceleration in direction x is too high*/
    if(itf(env->acc_x) > 2.0) {
    	/* then we sign it with the first bit of the problems variable */
        problems |= (1<<0);
    }

    if(itf(env->acc_y) > 2.0) {
    	/* If acceleration in direction y is too high*/
    	/* then we sign it with the second bit of the problems variable */
        problems |= (1<<1);
    }

    if(itf(env->acc_z) > 2.0) {
    	/* If acceleration in direction z is too high*/
    	/* then we sign it with the third bit of the problems variable */
        problems |= (1<<2);
    }

    if(sqCubDiag(env->acc_x, env->acc_x, env->acc_x) > multi(3)) {
    	/* If resultant acceleration is too high*/
    	/* then we sign it with the fourth bit of the problems variable */
        problems |= (1<<3);
    }

    if(env->temp>34) {
    	/* If temperature is too high (>34°C)*/
    	/* then we sign it with the fifth bit of the problems variable */
        problems |= (1<<4); /*0001 0000*/
    }

    /* 16 = 0001 0000 */
    if(problems>16) {
    	/* If the temperature and at least one acceleration value is problematic */
    	/* then we set the state to HIGH_ACCELERATION_AND_LIGHT */
        env->state = HIGH_ACCELERATION_AND_TEMP;
    } else if(problems==16) {
    	/* If only the temperature is problematic */
    	/* then we set the state to HIGH_LIGHT */
        env->state = HIGH_TEMP;
    } else if(problems>0) {
    	/* If just accelerations' value is problematic */
    	/* then we set the state to HIGH_ACCELERATION */
        env->state = HIGH_ACCELERATION;
    } else {
    	/* If no problems has been detected */
    	/* then we set the state to OK */
    	env->state = OK;
    }
}
