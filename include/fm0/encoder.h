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


#ifndef INCLUDED_FM0_ENCODER_H
#define INCLUDED_FM0_ENCODER_H

#include <fm0/api.h>
#include <gnuradio/sync_interpolator.h>

namespace gr {
  namespace fm0 {

    /*!
     * \brief Simple FM0 encoder. Unpacked (ie. one bit per) byte in, twice as many unpacked out.
     * \ingroup fm0
     *
     */
    class FM0_API encoder : virtual public gr::sync_interpolator
    {
     public:
      typedef boost::shared_ptr<encoder> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of fm0::encoder.
       *
       * To avoid accidental use of raw pointers, fm0::encoder's
       * constructor is in a private implementation
       * class. fm0::encoder::make is the public interface for
       * creating new instances.
       * \par initial_state The initial state. The first resulting half-period will be the inverse of this!
       */
      static sptr make(uint8_t initial_state=0);
    };

  } // namespace fm0
} // namespace gr

#endif /* INCLUDED_FM0_ENCODER_H */

