#include "Ray.h"
#include "Player.h"
#include "Config.h"
#include <math.h>

#include <SFML/Graphics/RectangleShape.hpp>

sf::Vector2f normalize(sf::Vector2f x)
{
	float length = sqrt(x.x*x.x + x.y*x.y);
	return { x.x / length, x.y / length };
}
float cross(sf::Vector2f a, sf::Vector2f b)
{
	return a.x*b.y - a.y*b.x;
}
float dot(sf::Vector2f a, sf::Vector2f b)
{
	return a.x * b.x + a.y * b.y;
}



Ray::Ray() 
{
    Visible = true;
}

void Ray::Update(Player pl, sf::Vector2i mouse, const std::vector<Obstacle>& obs)
{
	sf::Vector2f rayStart = pl.GetPosition();
	sf::Vector2f rayEnd = sf::Vector2f(mouse);

	rayEnd = normalize(rayEnd - rayStart) * SEGMENT_TRAVEL + rayStart;

    m_ln.clear();

	// for each segment check the collision
    for (int i = 0; i < SEGMENT_COUNT; i++) {

		sf::Vector2f ray = rayEnd - rayStart, normal;

		// check if we hit any obstacle
        if ((m_id = check(rayStart, rayEnd, obs, normal, rayStart)) < 0)
            break;

		rayEnd = normalize(ray - 2 * dot(ray, normal) * normal) * SEGMENT_TRAVEL + rayStart;
	}

	// save end position
	m_pos = rayStart;
}

void Ray::Render(sf::RenderTarget& tgt)
{ 
    if (Visible && m_ln.size() > 0)
        tgt.draw(&m_ln[0], m_ln.size(), sf::LinesStrip);
}

int Ray::check(const sf::Vector2f& start, const sf::Vector2f& end, const std::vector<Obstacle>& obs, sf::Vector2f& normal, sf::Vector2f& pos)
{
    m_ln.push_back(sf::Vertex(start, sf::Color::Blue));

	sf::Vector2f ray = normalize(end - start) * SEGMENT_TRAVEL;
	
	float ext = 1;
	int ret = -1;

	// go through the given list of obstacles and check for collision with each side
	// NOTE: in future we can have rotated or more complex (concave for example) shapes with more points
	for (const Obstacle& ob : obs) {
		sf::Vector2f oPos(ob.X*UNIT_WIDTH, ob.Y*UNIT_HEIGHT), oSize(ob.W*UNIT_WIDTH, ob.H*UNIT_HEIGHT);

		// left
		if (line(ext, normal, start, end, oPos, sf::Vector2f(0, oSize.y) + oPos)) ret = ob.Id;

		// right
		if (line(ext, normal, start, end, oPos + sf::Vector2f(oSize.x, 0), oSize + oPos)) ret = ob.Id;

		// top
		if (line(ext, normal, start, end, oPos, sf::Vector2f(oSize.x, 0) + oPos)) ret = ob.Id;

		// bottom
		if (line(ext, normal, start, end, oPos + sf::Vector2f(0, oSize.y), oSize + oPos)) ret = ob.Id;
	}

	// calculate the end position
	pos = ray * ext + start;

    m_ln.push_back(sf::Vertex(pos, sf::Color::Blue));

    return ret;
}

bool Ray::line(float &ext, sf::Vector2f& normal, const sf::Vector2f& rStart, const sf::Vector2f& rEnd, const sf::Vector2f& cStart, const sf::Vector2f& cEnd)
{
	sf::Vector2f ray = rEnd - rStart;
	sf::Vector2f collider = cEnd - cStart;

	float y = cross(cStart - rStart, collider) / cross(ray, collider);
	float x = cross(rStart - cStart, ray) / -cross(ray, collider);

	if (y <= 0 || y > 1 || x < 0 || x > 1) return false;

	if (y < ext) {
		ext = y;

		// calculate normal
		normal = sf::Vector2f(-collider.y, collider.x);
		float angle = dot(normalize(normal), normalize(normal));
		if (angle > 0)
			normal = -normal;
		normal = normalize(normal);

		return true;
	}

	return false;
}
