.PHONY: clean

NNPuppiTauModel_v1.so: NNPuppiTauModel_emulator_v1.o NNPuppiTauModel_v1.o
	$(CXX) $(CXXFLAGS) $(LD_FLAGS) -shared $^ -o $@

%.o: NN/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm NNPuppiTauModel_emulator_v1.o NNPuppiTauModel_v1.o NNPuppiTauModel_v1.so
