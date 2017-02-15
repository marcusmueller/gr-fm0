/* -*- c++ -*- */

#define FM0_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "fm0_swig_doc.i"

%{
#include "fm0/encoder.h"
%}


%include "fm0/encoder.h"
GR_SWIG_BLOCK_MAGIC2(fm0, encoder);
