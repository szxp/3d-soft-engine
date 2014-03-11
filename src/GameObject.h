
#ifndef GAME_OBJECT_H
#define GAME_OBJETC_H

namespace g3
{

/*******************************************************************************
 * Base class that all game object can inherit from.
 ******************************************************************************/
class GameObject
{


}; // class GameObject


/*******************************************************************************
 * Interface for updatable game objects.
 ******************************************************************************/
class Updatable
{
	/**
	 * Called when an object need to be updated.
	 *
	 * @param deltaTime The elapsed delta time since the last update.
	 */
	virtual void update(float deltaTime) = 0;

}; // class Updatable


/*******************************************************************************
 * Interface for drawable game objects.
 ******************************************************************************/
class Drawable
{
	/**
	 * Called when an object need to be drawn.
	 */
	virtual void draw() = 0;

}; // class Drawable


/*******************************************************************************
 * Update-only game object.
 ******************************************************************************/
class UGameObject: public GameObject, public Updatable
{

}; // class UGameObject


/*******************************************************************************
 * Draw-only game object.
 ******************************************************************************/
class DGameObject: public GameObject, public Drawable
{

}; // class DGameObject


/*******************************************************************************
 * Update and draw game object.
 ******************************************************************************/
class DUGameObject: public UGameObject, public Drawable
{

}; // class DUGameObject


} // namespace g3

#endif //GAME_OBJETC_H
