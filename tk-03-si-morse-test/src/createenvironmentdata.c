#include "selfprot.h"

/* float to fixed point representation converter */
#define toInt(x) ((int)(x*10+0.5))

/*
 * Function: CreateEnvironmentData
 * --------------------------------------------
 * converts input data into structured form
 *
 * acc_x: acceleration in the X direction
 * acc_y: acceleration in the Y direction
 * acc_z: acceleration in the Z direction
 * temp: magnitude of the temperature
 */
EnvironmentData CreateEnvironmentData(float acc_x, float acc_y, float acc_z, int temp) {
	/* Declaration of the structure */
    EnvironmentData ed;

    /* Set the value of data members of the structure */
    ed.acc_x = toInt(acc_x);
    ed.acc_y = toInt(acc_y);
    ed.acc_z = toInt(acc_z);
    ed.temp  = temp;
    ed.state = OK;

    return ed;
}
