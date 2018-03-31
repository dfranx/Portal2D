#include "Ray.h"
#include "Player.h"
#include "Config.h"

#include <SFML/Graphics/RectangleShape.hpp>

Ray::Ray() 
{
    Visible = true;
}

void Ray::Update(Player pl, int mx, int my, const std::vector<Obstacle>& obs)
{
    sf::Vector2f ret = pl.GetPosition();

    float angle = M_PI-atan2(mx-ret.x, my-ret.y);

    m_ln.clear();

    for (int i = 0; i < SEGMENT_COUNT; i++) {
		bool isVert;
        float destX = sin(angle)*SEGMENT_TRAVEL+ret.x;	// x travel of a segment (basic trigonometry + offset by a player position)
        float destY = -cos(angle)*SEGMENT_TRAVEL+ret.y;	// y travel of a segment

		// check if we hit any obstacle, if we didnt just stop checking
        if ((m_id = line(ret.x, ret.y, destX, destY, obs, ret, isVert)) < 0)
            break;

		// adjust angle accordingly if we hit vertical or horizontal side of a obstacle
        if (isVert)
            angle = M_PI-angle;
        else 
            angle = -angle; 

		// save end position
        m_pos = ret;
    }
}

void Ray::Render(sf::RenderTarget& tgt)
{ 
    if (Visible && m_ln.size() > 0)
        tgt.draw(&m_ln[0], m_ln.size(), sf::LinesStrip);
}

int Ray::line(int x0, int y0, int x1, int y1, const std::vector<Obstacle>& obs, sf::Vector2f& pos, bool& vert)
{
	// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

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
                    return (int)ob.Id;
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
                    return (int)ob.Id;
                }
            }
        }
    }

    m_ln.push_back(sf::Vertex(pos = sf::Vector2f(x, y), sf::Color::Blue));
    return -1;
}

bool Ray::vertical(int x, int y, Obstacle ob)
{
    sf::IntRect bnd = ob.GetBounds();

    if (x <= bnd.left+1 || x >= bnd.left+bnd.width-1)
        return false; // it is not vertical if x position is same as x or x+width position of element

    return true;
}