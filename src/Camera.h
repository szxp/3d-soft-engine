
#ifndef CAMERA_H
#define CAMERA_H

#include "Vec.h"

namespace g3
{

/*******************************************************************************
 * Describes a camera object.
 ******************************************************************************/
struct Camera
{
	/**
	 * The postition of the camera.
	 */
	Vec3 eye;

	/**
	 * The point that the camera is looking at.
	 */
	Vec3 target;

	/**
	 * Zoom factor 
	 */
	float zoomFactor;


}; // class Camera


} // namespace g3


#endif // CAMERA_H
