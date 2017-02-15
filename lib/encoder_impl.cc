/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "encoder_impl.h"

namespace gr {
  namespace fm0 {

    encoder::sptr
    encoder::make(uint8_t initial_state)
    {
      return gnuradio::get_initial_sptr
        (new encoder_impl(initial_state));
    }

    /*
     * The private constructor
     */
    encoder_impl::encoder_impl(uint8_t initial_state)
      : gr::sync_interpolator("encoder",
                              gr::io_signature::make(1, 1, sizeof(uint8_t)),
                              gr::io_signature::make(1,1, sizeof(uint8_t)), 2),
      d_state(initial_state)
    {
    }

    /*
     * Our virtual destructor.
     */
    encoder_impl::~encoder_impl()
    {
    }

    int
    encoder_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const uint8_t *in = (const uint8_t *) input_items[0];
      uint8_t *out = (uint8_t *) output_items[0];

      for(unsigned int counter = 0; counter < noutput_items; counter += 2)
        {
          out[counter]   = d_state ? 0 : 1;
          d_state = in[counter/2] ? out[counter] : !out[counter];
          out[counter+1] = d_state;
        }
      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace fm0 */
} /* namespace gr */

