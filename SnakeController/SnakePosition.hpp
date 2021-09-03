#pragma once

namespace Snake
{

struct Position
{
    Position(int x,int y ):
        m_x(x),m_y(y)
    {}
    int m_x;
    int m_y;

    bool operator==(Position const& rhs) const { return x == rhs.x and y == rhs.y; }
};

} // namespace Snake
