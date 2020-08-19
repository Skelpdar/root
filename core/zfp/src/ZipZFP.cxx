// Author:

/*************************************************************************
 * Copyright (C) 1995-2020, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#include "ZipZFP.h"

#include "ROOT/RConfig.hxx"

#include <cstdlib>
#include <zfp.h>


BIT_STREAM_WORD_TYPE = uint32;

float* R__zipZFP(float* array, int size, float tol){

	zfp_type type = zfp_type_float;
	zfp_field* arraymeta = zfp_field_1d(array, type, size);
	zfp_stream* zfp = zfp_stream_open(NULL);

	//Curently in fixed accuracy mode, not fixed precision
	//Bounding relative error (in fixed precision mode)
	//is in general not possible
	//Worth looking into
	//See zfp FAQ Q:20
	zfp_stream_set_accuracy(zfp, tol);

	size_t buffersize = zfp_stream_maximum_size(zfp, arraymeta);
	void* buffer = malloc(buffersize);

	bitstream* stream = stream_open(buffer, buffersize);
	zfp_stream_set_bit_stream(zfp, stream);
	zfp_stream_rewind(zfp);

	size_t compsize = zfp_compress(zfp, arraymeta);
	
	zfp_field_free(arraymeta);
	zfp_stream_close(zfp);
	stream_close(stream);
	free(buffer);
	free(array);

	//Read bitstream
	auto bstream = zfp.stream;

	void* bstreambuffer;
	size_t bstreamsize;



	//Serialize zfp_stream
	
	//Cast into float array


	float* f;


	return f;

}
