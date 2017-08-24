#include "Ray.h"

#include <SFML/Graphics/RectangleShape.hpp>


#define TRAVEL 200

int r2d(float x) {
    return x*180/M_PI;
}

void Ray::Init()
{
    m_angle = 0;
}

void Ray::Update(Player pl, int mx, int my, const std::vector<Obstacle>& obs)
{
    sf::Vector2f p = pl.GetPosition();
    sf::Vector2f ret;
    bool isVert;

    m_ln.clear();
    
    m_angle = atan2(mx-p.x, my-p.y);
    m_angle = 2*M_PI-(m_angle+M_PI);

    if (line(p.x, p.y, mx, my, obs, ret, isVert)) {
        printf("%d\n", r2d(m_angle));

        float bounceAngle = M_PI-(m_angle-M_PI);

        if (isVert)
            bounceAngle = 2*M_PI-(m_angle-M_PI);

        printf("angle:%d\nbounce: %d\n\n", r2d(m_angle), r2d(bounceAngle));

        float destX = sin(bounceAngle)*TRAVEL+ret.x;
        float destY = -cos(bounceAngle)*TRAVEL+ret.y; // invert Y for proper orientation

        line(ret.x, ret.y, destX, destY, obs, ret, isVert);
        //m_ln.push_back(sf::Vertex(sf::Vector2f(destX, destY), sf::Color::White));
    }
}

void Ray::Render(sf::RenderTarget& tgt)
{ 
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

            for (auto ob : obs) {
                if (ob.GetBounds().contains(x, y)) {
                    m_ln.push_back(sf::Vertex(pos = sf::Vector2f(x, y), sf::Color::Blue));
                    vert = vertical(x,y, ob);
                    return true;
                }
            }
            
            x += dirX, error += delY;            
        }
    } else {
        error = delX - (delY / 2);
 
        for (; y != y1;) {
            if (error > 0 || (!error && dirY > 0)) {
                error -= delY;
                x += dirX;
            }

            for (auto ob : obs) {
                if (ob.GetBounds().contains(x, y)) {
                    m_ln.push_back(sf::Vertex(pos = sf::Vector2f(x, y), sf::Color::Blue));
                    vert = vertical(x,y, ob);
                    return true;
                }
            }

            y += dirY, error += delX;
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