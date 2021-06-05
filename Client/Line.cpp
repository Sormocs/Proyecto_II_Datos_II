#include "Line.h"

Line::Line(float x1, float y1, float x2, float y2, sf::Color color)
{
    m_color = color;
    sf::Vertex start = sf::Vertex(sf::Vector2f(x1, y1), m_color);
    sf::Vertex end = sf::Vertex(sf::Vector2f(x2, y2), m_color);
    m_points.setPrimitiveType(sf::LineStrip);
    m_points.append(start);
    m_points.append(end);
}

Line::~Line()
{
    m_points.clear();
}

sf::VertexArray Line::getPoints()
{
    return m_points;
}

void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_points);
}