
#ifndef LAYER_H
#define LAYER_H

#include <string>

class Layer {
public:
  Layer();
  virtual ~Layer() = default;

protected:
std::string layerName;
};

#endif
