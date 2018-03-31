#ifndef __PORTAL2D_CONFIG_H__
#define __PORTAL2D_CONFIG_H__

#define UNIT_WIDTH 16			// level unit's width
#define UNIT_HEIGHT 16			// level unit's height

#define SEGMENT_COUNT 3			// number of ray segments - how many times can the ray bounce off of obstacles
#define SEGMENT_TRAVEL 200		// max distance of a single ray segment
#ifndef M_PI
	#define M_PI (3.141592f)	// define PI if it already isnt defined
#endif

#endif //__PORTAL2D_CONFIG_H__