#ifndef ___SIGMOID__NEURON__CPP___
#define ___SIGMOID__NEURON__CPP___

#include <memory>
#include <type_traits>
#include <vector>
#include <cmath>
#include "neuron.h"

using namespace std;
using namespace mp;

namespace mp {
  template <class B>
  class SigmoidNeuron : Neuron<B> {
    protected:
      double refresh() override;
  };
}
#endif
