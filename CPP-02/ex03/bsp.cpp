/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 31-01-2022  by  `-'                        `-'                  */
/*   Updated: 31-01-2022 20:56 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
	Returns which side 'point' is compared to the segment 'ab' (depending on sign)
	See https://math.stackexchange.com/questions/274712/calculate-on-which-side-of-a-straight-line-is-a-given-point-located
	http://www.ambrsoft.com/TrigoCalc/PointsInOut/PointInOut_.htm

	This is the cross product of our segment AB and AP, BC and BP etc.
*/
static float	getSide(Point const point, Point const a, Point const b)
{
	return (((point.getfX() - b.getfX()) * (a.getfY() - b.getfY())  -  (a.getfX() - b.getfX()) * (point.getfY() - b.getfY())));
}

/*
	Now just check that the point is on the same side compared to the 3 segments, if it is,
	it is in the triangle
*/
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float s1 = getSide(point, a, b), s2 = getSide(point, b, c), s3 = getSide(point, c, a);

	if ((s1 > 0 && s2 > 0 && s3 > 0) || (s1 < 0 && s2 < 0 && s3 < 0))
		return (true);
	return (false);
}