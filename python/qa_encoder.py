#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2017 Marcus Müller.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import fm0_swig as fm0

class qa_encoder (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        # set up fg
        self.dut = fm0.encoder()
        length = 2**12
        outlist = [(i+1) % 2 for i in range(length*2)]
        self.src = blocks.vector_source_b( [0]*(length) )
        self.sink = blocks.vector_sink_b()
        self.tb.connect(self.src,self.dut,self.sink)
        self.tb.run ()
        # check data
        data = self.sink.data()
        self.assertEqual(len(data), len(outlist))
        for d, out in zip(data,outlist):
            self.assertEqual(d, out)

    def test_002_t (self):
        # set up fg
        self.dut = fm0.encoder()
        length = 2**12
        outlist = [(i/2+1) % 2 for i in range(length*2)]
        self.src = blocks.vector_source_b( [1]*(length) )
        self.sink = blocks.vector_sink_b()
        self.tb.connect(self.src,self.dut,self.sink)
        self.tb.run ()
        # check data
        data = self.sink.data()
        self.assertEqual(len(data), len(outlist))
        for d, out in zip(data,outlist):
            self.assertEqual(d, out)

if __name__ == '__main__':
    gr_unittest.run(qa_encoder, "qa_encoder.xml")
