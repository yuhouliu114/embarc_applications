/*
* Copyright 2019, Synopsys, Inc.
* All rights reserved.
*
* This source code is licensed under the BSD-3-Clause license found in
* the LICENSE file in the root directory of this source tree.
*
*/

#ifndef _CIFAR10_CONSTANTS_H_
#define _CIFAR10_CONSTANTS_H_

#include "mli_config.h"
#include "cifar10_model.h"
#include "embarc_mli_sections.h"

// Defining weight data type
//===================================
#define W_EL_TYPE (MLI_EL_FX_8)
typedef int8_t w_type;

//======================================================
//
// Common data transform (Qmn) defines
//
//======================================================

#define QMN(type, fraq, val)   (type)(val * (1u << (fraq)) + ((val >= 0)? 0.5f: -0.5f))
#define FRQ_BITS(int_part, el_type) ((sizeof(el_type)*8)-int_part-1)

//======================================================
//
// Common data transform (Qmn) defines
//
//======================================================

extern const w_type  _W2  L1_conv_wt_buf[];
extern const w_type  _W  L1_conv_bias_buf[];

extern const w_type  _W  L2_conv_wt_buf[];
extern const w_type  _W  L2_conv_bias_buf[];

extern const w_type  _W  L3_conv_wt_buf[];
extern const w_type  _W  L3_conv_bias_buf[];

extern const w_type  _W  L4_fc_wt_buf[];
extern const w_type  _W  L4_fc_bias_buf[];

//======================================================
//
// Tensor's Integer bits per layer definitions
//
//======================================================
// Small Model

#define CONV1_W_INT   (-1) //整数位
#define CONV1_B_INT   (-2)
#define CONV1_OUT_INT (1)

#define CONV2_W_INT   (-2)
#define CONV2_B_INT   (-3)
#define CONV2_OUT_INT (4)

#define CONV3_W_INT   (-3)
#define CONV3_B_INT   (-3)
#define CONV3_OUT_INT (5)

#define FC4_W_INT   (-2)
#define FC4_B_INT   (-5)
#define FC4_OUT_INT (6)

//======================================================
//
// Shape and Fractional bits per layer definitions
//
//======================================================

// CONV1
//================================================
#define CONV1_W_SHAPE {32,1,5,5}
#define CONV1_W_ELEMENTS (32*1*5*5)
#define CONV1_W_RANK (4)

#define CONV1_W_FRAQ   (FRQ_BITS(CONV1_W_INT, w_type))
#define L1_WQ(val)   QMN(w_type, CONV1_W_FRAQ, val)

#define CONV1_B_ELEMENTS (32)
#define CONV1_B_SHAPE {32}
#define CONV1_B_RANK (1)

#define CONV1_B_FRAQ   (FRQ_BITS(CONV1_B_INT, w_type))
#define L1_BQ(val)   QMN(w_type, CONV1_B_FRAQ, val)

#define CONV1_OUT_FRAQ (FRQ_BITS(CONV1_OUT_INT, d_type))

// CONV2
//================================================

#define CONV2_W_SHAPE {16,32,5,5}
#define CONV2_W_ELEMENTS (16*32*5*5)
#define CONV2_B_SHAPE {16}
#define CONV2_B_ELEMENTS (16)

#define CONV2_W_RANK (4)
#define CONV2_B_RANK (1)

#define CONV2_W_FRAQ   (FRQ_BITS(CONV2_W_INT, w_type))
#define L2_WQ(val)   QMN(w_type, CONV2_W_FRAQ, val)
#define CONV2_B_FRAQ   (FRQ_BITS(CONV2_B_INT, w_type))
#define L2_BQ(val)   QMN(w_type, CONV2_B_FRAQ, val)
#define CONV2_OUT_FRAQ (FRQ_BITS(CONV2_OUT_INT, d_type))

// CONV3
//================================================

#define CONV3_W_SHAPE {8,16,5,5}
#define CONV3_W_ELEMENTS (8*16*5*5)
#define CONV3_B_SHAPE {8}
#define CONV3_B_ELEMENTS (8)

#define CONV3_W_RANK (4)
#define CONV3_B_RANK (1)

#define CONV3_W_FRAQ   (FRQ_BITS(CONV2_W_INT, w_type))
#define L3_WQ(val)   QMN(w_type, CONV2_W_FRAQ, val)
#define CONV3_B_FRAQ   (FRQ_BITS(CONV2_B_INT, w_type))
#define L3_BQ(val)   QMN(w_type, CONV2_B_FRAQ, val)
#define CONV3_OUT_FRAQ (FRQ_BITS(CONV2_OUT_INT, d_type))

// FC4
//================================================
#define FC4_W_SHAPE {36,(8*18*9)}
#define FC4_W_ELEMENTS (36*(8*18*9))
#define FC4_B_SHAPE {36}
#define FC4_B_ELEMENTS (36)

#define FC4_W_RANK (2)
#define FC4_B_RANK (1)

#define FC4_W_FRAQ   (FRQ_BITS(FC4_W_INT, w_type))
#define L4_WQ(val)   QMN(w_type, FC4_W_FRAQ, val)
#define FC4_B_FRAQ   (FRQ_BITS(FC4_B_INT, w_type))
#define L4_BQ(val)   QMN(w_type, FC4_B_FRAQ, val)
#define FC4_OUT_FRAQ (FRQ_BITS(FC4_OUT_INT, d_type))


#endif  //_CIFAR10_CONSTANTS_H_
