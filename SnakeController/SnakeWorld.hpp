#pragma once

#include <utility>
#include "SnakePosition.hpp"
#include "WorldDimension.hpp"

namespace Snake
{

class World
{
public:
    World(std::pair<int, int> dimension, std::pair<int, int> food);

    void setFoodPosition(std::pair<int, int> position);
    std::pair<int, int> getFoodPosition() const;

    bool contains(int x, int y) const;

private:
    Position m_foodPosition;
    Dimension m_dimension;
};

} // namespace Snake
