/* ========================================================================= */
/* === AMD_defaults ======================================================== */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/* AMD, Copyright (c) Timothy A. Davis,					     */
/* Patrick R. Amestoy, and Iain S. Duff.  See ../README.txt for License.     */
/* email: DrTimothyAldenDavis@gmail.com                                      */
/* ------------------------------------------------------------------------- */

/* User-callable.  Sets default control parameters for AMD.  See amd.h
 * for details.
 */

#include "amd_internal.h"

/* ========================================================================= */
/* === AMD defaults ======================================================== */
/* ========================================================================= */

GLOBAL void AMD_defaults
(
    pfloat Control [ ]
)
{
    Int i ;

    if (Control != (pfloat *) NULL)
    {
	for (i = 0 ; i < AMD_CONTROL ; i++)
	{
	    Control [i] = 0 ;
	}
	Control [AMD_DENSE] = AMD_DEFAULT_DENSE ;
	Control [AMD_AGGRESSIVE] = AMD_DEFAULT_AGGRESSIVE ;
    }
}