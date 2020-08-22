// Author:

/*************************************************************************
 * Copyright (C) 1995-2020, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_ZipZFP
#define ROOT_ZipZFP

#include <zfp.h>

#ifdef __cplusplus
extern "C" {
#endif
void R__zipZFP(float* array, int size, float tol, void* buffer, size_t& complength);
#ifdef __cplusplus
}
#endif
#endif
