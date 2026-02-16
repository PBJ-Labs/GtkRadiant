
#ifndef LAYER_H
#define LAYER_H

#include <string>

class Layer {
public:
  Layer();
  virtual ~Layer() = default;

  // get layer
  const Layer& getLayer() const {
    return *this;
  }

  // get layer name
  const std::string& getLayerName() const {
    return layerName;
  }

  int getLayerCount() const {
    return layersInMap;
  }

  virtual void incrementLayers() {
    layersInMap++;
  }

  virtual void decrementLayers() {
    layersInMap--;
  }

  // create layer
  virtual void createMapLayer(const Layer& layer, const std::string& name) = 0;

protected:
std::string layerName = "LAYER-NAME";
static int layersInMap;
};

#endif
