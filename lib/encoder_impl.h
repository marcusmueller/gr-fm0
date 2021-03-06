/* -*- c++ -*- */
/* 
 * Copyright 2017 Marcus Müller.
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

#ifndef INCLUDED_FM0_ENCODER_IMPL_H
#define INCLUDED_FM0_ENCODER_IMPL_H

#include <fm0/encoder.h>

namespace gr {
  namespace fm0 {

    class encoder_impl : public encoder
    {
     private:
      uint8_t d_state;
     public:
      encoder_impl(uint8_t initial_state);
      ~encoder_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace fm0
} // namespace gr

#endif /* INCLUDED_FM0_ENCODER_IMPL_H */

