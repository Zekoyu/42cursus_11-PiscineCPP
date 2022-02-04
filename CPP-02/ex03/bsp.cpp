/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 31-01-2022  by  `-'                        `-'                  */
/*   Updated: 04-02-2022 19:56 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
	Returns which side 'point' is compared to the segment 'ab' (depending on sign)
	See https://math.stackexchange.com/questions/274712/calculate-on-which-side-of-a-straight-line-is-a-given-point-located
	http://www.ambrsoft.com/TrigoCalc/PointsInOut/PointInOut_.htm

	This is the cross product of our segment AB and AP, BC and BP etc.
*/
static Fixed	getSide(Point const point, Point const a, Point const b)
{
	return (((point.getX() - b.getX()) * (a.getY() - b.getY())  -  (a.getX() - b.getX()) * (point.getY() - b.getY())));
}

/*
	Now just check that the point is on the same side compared to the 3 segments, if it is,
	it is in the triangle
*/
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed s1 = getSide(point, a, b), s2 = getSide(point, b, c), s3 = getSide(point, c, a);

	if ((s1 > 0 && s2 > 0 && s3 > 0) || (s1 < 0 && s2 < 0 && s3 < 0))
		return (true);
	return (false);
}