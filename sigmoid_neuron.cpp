#include "sigmoid_neuron.h"

namespace mp {

  template <class B>
  double SigmoidNeuron<B>::refresh() {
    double result = this->bias();
    shared_ptr<vector<B>> layer = this->before_layer();

    for(int i = 0; i < layer->size(); i++) {
      double neuron_output;

      if(is_fundamental<B>::value) {
        neuron_output = layer->at(i);
      }
      else if ((is_pointer<B>::value) && (is_fundamental<typename remove_pointer<B>::type>::value)) {
        neuron_output = *(layer->at(i));
      }
      else if(is_pointer<B>::value) {
        neuron_output = layer->at(i)->output();
      }
      else {
        neuron_output = layer->at(i).output();
      }

      result += neuron_output * this->factor(i);
    }

    result = 1/(1 + exp(-result));

    return result;
  }

}
