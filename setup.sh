TARGET=NNPuppiTauModel_v1/NN
mkdir -p $TARGET
SRC=NNPuppiTauModel

cp -r $SRC/defines.h ${TARGET}
sed -i "s/#include <cstdio>/#include <cstdio>\n\nnamespace hls4ml_nnpuppitaumodel_v1 {/" ${TARGET}/defines.h
echo '}' >> ${TARGET}/defines.h

cp -r $SRC/nnet_utils ${TARGET}

cp $SRC/parameters.h ${TARGET}
# cmssw's tau_parameters.h includes nnet_utils/defines.h/weights via absolute
# in-tree paths; rewrite to the local relative paths used by this package.
sed -i "s,L1Trigger/Phase2L1ParticleFlow/interface/taus/,," ${TARGET}/parameters.h
sed -i "s,// hls-fpga-machine-learning insert layer-config,namespace hls4ml_nnpuppitaumodel_v1 {\n// hls-fpga-machine-learning insert layer-config," ${TARGET}/parameters.h
sed -i "s/#endif/}\n\n#endif/" ${TARGET}/parameters.h

cp -r $SRC/weights ${TARGET}
for filename in ${TARGET}/weights/*.h; do
    echo $filename
    sed -i '8 a namespace hls4ml_nnpuppitaumodel_v1 {' $filename
    echo '}' >> $filename
done

# NNPuppiTauModel_v1.h / .cpp are NOT produced by this sed pipeline: unlike other
# cms-hls4ml exports, the upstream hls4ml-generated top-level network call sequence for
# this model was never kept as a standalone free function in CMSSW -- it was inlined
# directly into L1Trigger/Phase2L1ParticleFlow's TauNNIdHW::EvaluateNN(). They were
# produced by a one-time manual extraction of that method body (same layer calls,
# same intermediate buffers, no logic change) into the namespaced free function
# NNPuppiTauModel_v1(...), and are committed directly under NNPuppiTauModel_v1/NN/.
