/*
 * nanf () returns a nan.
 * Added by Cygnus Support.
 */

#include "fdlibm.h"

	float nanf()
{
	float x;

	SET_FLOAT_WORD(x,0x7fc00000);
	return x;
}
