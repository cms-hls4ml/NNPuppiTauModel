#ifndef NNPUPPITAUMODEL_v1_H_
#define NNPUPPITAUMODEL_v1_H_

#include "ap_fixed.h"
#include "ap_int.h"

#include "defines.h"

// Prototype of top level function for C-synthesis
namespace hls4ml_nnpuppitaumodel_v1 {
void NNPuppiTauModel_v1(
    input_t model_input[N_INPUT_1_1],
    result_t layer19_out[N_LAYER_17], result_t layer20_out[N_LAYER_20]
);

}

#endif
