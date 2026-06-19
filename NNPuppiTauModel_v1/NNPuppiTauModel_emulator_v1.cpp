#include "NN/NNPuppiTauModel_v1.h"
#include "emulator.h"
#include "NN/nnet_utils/nnet_common.h"
#include <any>
#include <array>
#include <utility>
#include "ap_fixed.h"
#include "ap_int.h"

using namespace hls4ml_nnpuppitaumodel_v1;

class NNPuppiTauModel_emulator_v1 : public hls4mlEmulator::Model{
    private:
        input_t _input[N_INPUT_1_1];
        result_t _layer19_out[N_LAYER_17];  // nn_id (sigmoid head)
        result_t _layer20_out[N_LAYER_20];  // nn_pt_correction (regression head)
    public:
        virtual void prepare_input(std::any input)
        {
            input_t* input_p = std::any_cast<input_t*>(input);
            for(int i = 0; i < N_INPUT_1_1; ++i){
                _input[i] = std::any_cast<input_t>(input_p[i]);
            }
        }
        virtual void predict()
        {
            NNPuppiTauModel_v1(_input, _layer19_out, _layer20_out);
        }
        virtual void read_result(std::any result)
        {
            std::pair<std::array<result_t,N_LAYER_20>,std::array<result_t,N_LAYER_17>> *result_p = std::any_cast<std::pair<std::array<result_t,N_LAYER_20>,std::array<result_t,N_LAYER_17>>*>(result);
            for (int i = 0; i < N_LAYER_20; ++i ){
                result_p->first[i] = _layer20_out[i];
            }
            for (int i = 0; i < N_LAYER_17; ++i ){
                result_p->second[i] = _layer19_out[i];
            }
        }
};

extern "C" hls4mlEmulator::Model* create_model()
{
    return new NNPuppiTauModel_emulator_v1;
}
extern "C" void destroy_model(hls4mlEmulator::Model* m)
{
    delete m;
}
