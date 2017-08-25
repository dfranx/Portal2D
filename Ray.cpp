#include "Ray.h"
#include "Player.h"

#include <SFML/Graphics/RectangleShape.hpp>


#define TRAVEL 200
#define RAY_COUNT 3

void Ray::Init() 
{
    Visible = false;
}

void Ray::Update(Player pl, int mx, int my, const std::vector<Obstacle>& obs)
{
    sf::Vector2f ret = pl.GetPosition();

    bool isVert;
    float angle = M_PI-atan2(mx-ret.x, my-ret.y);
    float destX;
    float destY;

    m_ln.clear();

    for (int i = 0; i < RAY_COUNT; i++) {
        destX = sin(angle)*TRAVEL+ret.x;
        destY = -cos(angle)*TRAVEL+ret.y;

        if (!line(ret.x, ret.y, destX, destY, obs, ret, isVert))
            break;

        if (isVert)
            angle = M_PI-angle;
        else 
            angle = -angle; 

    }
}

void Ray::Render(sf::RenderTarget& tgt)
{ 
    if (Visible)
        tgt.draw(&m_ln[0], m_ln.size(), sf::LinesStrip);
}

bool Ray::line(int x0, int y0, int x1, int y1, const std::vector<Obstacle>& obs, sf::Vector2f& pos, bool& vert)
{
    int delX = std::abs(x1 - x0) * 2;
    int dirX = (x1 - x0 < 0) ? -1 : ((x1 - x0 > 0) ? 1 : 0);

    int delY = std::abs(y1 - y0) * 2;
    int dirY = (y1 - y0 < 0) ? -1 : ((y1 - y0 > 0) ? 1 : 0);
 
    int error;
    int x = x0+dirX;
    int y = y0+dirY;

    m_ln.push_back(sf::Vertex(sf::Vector2f(x, y), sf::Color::Blue));
    
    if (delX >= delY) {
        error = delY - (delX / 2);
 
        for (; x != x1;) {
            if ((error > 0) || (!error && (dirX > 0))) {
                error -= delX;
                y += dirY;
            }
            
            x += dirX;
            error += delY;  

            for (auto ob : obs) {
                if (ob.GetBounds().contains(x, y)) {
                    m_ln.push_back(sf::Vertex(pos = sf::Vector2f(x, y), sf::Color::Blue));
                    vert = vertical(x,y, ob);
                    return true;
                }
            }          
        }
    } else {
        error = delX - (delY / 2);
 
        for (; y != y1;) {
            if (error > 0 || (!error && dirY > 0)) {
                error -= delY;
                x += dirX;
            }
            
            y += dirY;
            error += delX;
            
            for (auto ob : obs) {
                if (ob.GetBounds().contains(x, y)) {
                    m_ln.push_back(sf::Vertex(pos = sf::Vector2f(x, y), sf::Color::Blue));
                    vert = vertical(x,y, ob);
                    return true;
                }
            }
        }
    }

    m_ln.push_back(sf::Vertex(pos = sf::Vector2f(x, y), sf::Color::Blue));
    return false;
}

bool Ray::vertical(int x, int y, Obstacle ob)
{
    sf::IntRect bnd = ob.GetBounds();

    if (x <= bnd.left+1 || x >= bnd.left+bnd.width-1)
        return false;

    return true;
}