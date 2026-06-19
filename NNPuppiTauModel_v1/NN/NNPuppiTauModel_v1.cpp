#include <iostream>

#include "NNPuppiTauModel_v1.h"
#include "parameters.h"

namespace hls4ml_nnpuppitaumodel_v1 {
void NNPuppiTauModel_v1(
    input_t model_input[N_INPUT_1_1],
    result_t layer19_out[N_LAYER_17], result_t layer20_out[N_LAYER_20]
) {

    layer2_t layer2_out[N_LAYER_2];
    nnet::dense<input_t, layer2_t, config2>(model_input, layer2_out, w2, b2);  // Dense_1

    layer4_t layer4_out[N_LAYER_2];
    nnet::relu<layer2_t, layer4_t, relu_config4>(layer2_out, layer4_out);  // relu_1

    layer5_t layer5_out[N_LAYER_5];
    nnet::dense<layer4_t, layer5_t, config5>(layer4_out, layer5_out, w5, b5);  // Dense_2

    layer7_t layer7_out[N_LAYER_5];
    nnet::relu<layer5_t, layer7_t, relu_config7>(layer5_out, layer7_out);  // relu_2

    layer8_t layer8_out[N_LAYER_8];
    nnet::dense<layer7_t, layer8_t, config8>(layer7_out, layer8_out, w8, b8);  // Dense_3

    layer10_t layer10_out[N_LAYER_8];
    nnet::relu<layer8_t, layer10_t, relu_config10>(layer8_out, layer10_out);  // relu_3

    layer11_t layer11_out[N_LAYER_11];
    nnet::dense<layer10_t, layer11_t, config11>(layer10_out, layer11_out, w11, b11);  // Dense_4

    layer13_t layer13_out[N_LAYER_11];
    nnet::relu<layer11_t, layer13_t, relu_config13>(layer11_out, layer13_out);  // relu_4

    layer14_t layer14_out[N_LAYER_14];
    nnet::dense<layer13_t, layer14_t, config14>(layer13_out, layer14_out, w14, b14);  // Dense_5

    layer16_t layer16_out[N_LAYER_14];
    nnet::relu<layer14_t, layer16_t, relu_config16>(layer14_out, layer16_out);  // relu_5

    layer17_t layer17_out[N_LAYER_17];
    nnet::dense<layer16_t, layer17_t, config17>(layer16_out, layer17_out, w17, b17);  // Dense_6

    nnet::sigmoid<layer17_t, result_t, sigmoid_config19>(layer17_out, layer19_out);  // jetID_output

    nnet::dense<layer16_t, result_t, config20>(layer16_out, layer20_out, w20, b20);  // pT_output
}

}
