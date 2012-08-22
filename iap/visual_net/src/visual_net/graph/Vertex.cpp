/* * IAP - Interactive Perception System - Segment visually observable environment
 * into rigid bodies and estimate type and properties of joints between them by
 * means of interaction.
 * Copyright (C) 2012 Technische Universitaet Berlin - RBO
 * <robotics@robotics.tu-berlin.de>
 * 
 * This file is part of IAP.
 * 
 * IAP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * IAP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with IAP.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "Vertex.h"
#include "feature.h"
using namespace std;
using namespace vision;

namespace VisualGraph
{

  static int vertexIndex = 0;

  Vertex::Vertex(void)
  {
    ID = vertexIndex++;
    clusterID = 0;
  }

  Vertex::Vertex(vector<FeaturePtr> &featureData)
  {
    ID = vertexIndex++;
    this->featureData = featureData;
  }

  Vertex::~Vertex(void)
  {
  }

  FeaturePtr
  Vertex::getFeatureData(int frame)
  {
    return featureData[frame];
  }

  vector<FeaturePtr>
  Vertex::getFeatureHistory()
  {
    return featureData;
  }

  void
  Vertex::changeFeatureHistory(std::vector<vision::FeaturePtr> &new_feature_data)
  {
    featureData.clear();
    featureData = new_feature_data;
  }

  void
  Vertex::setClusterID(int id)
  {
    clusterID = id;
  }

  int
  Vertex::getClusterID()
  {
    return clusterID;
  }

  int
  Vertex::getID()
  {
    return ID;
  }

}
;
