#pragma once

#include <list>
#include <memory>
#include <stdexcept>

#include "IEventHandler.hpp"
#include "SnakeInterface.hpp"

class Event;
class IPort;

namespace Snake
{
struct ConfigurationError : std::logic_error
{
    ConfigurationError();
};

struct UnexpectedEventException : std::runtime_error
{
    UnexpectedEventException();
};

class Controller : public IEventHandler
{
public:
    Controller(IPort& p_displayPort, IPort& p_foodPort, IPort& p_scorePort, std::string const& p_config);

    Controller(Controller const& p_rhs) = delete;
    Controller& operator=(Controller const& p_rhs) = delete;

    void receive(std::unique_ptr<Event> e) override;

private:
    struct Segment
    {
        int x;
        int y;
        int ttl;
    };

    IPort& m_displayPort;
    IPort& m_foodPort;
    IPort& m_scorePort;

    std::pair<int, int> m_mapDimension;
    std::pair<int, int> m_foodPosition;

    Direction m_currentDirection;
    std::list<Segment> m_segments;
    bool isItLostByEatingYourself(const Segment & newHead);
    bool doWeGetPoint(const Segment& newHead);
    bool isItLostByCrossingTheBorder(const Segment & newHead);
    void updateSegments(const Segment& newHead);
    void updateBody(const Segment & newHead);
    void directionHandler(const Snake::Direction & direction);
    void updateHead(const Segment& currentHead, Segment & newHead);
    void timeoutHandler();
    void placeNewFood(Snake::FoodResp requestedFood);
    bool isFoodCollidedWithSnake(Snake::FoodInd receivedFood);
    void newFoodHandler(Snake::FoodInd receivedFood);
    void placeFoodHandler(Snake::FoodResp requestedFood);
    void placeNewFood(Snake::FoodInd receivedFood);
};

} // namespace Snake
