
#ifndef GAME_OBJECT_H
#define GAME_OBJETC_H

namespace g3
{

/*******************************************************************************
 * Base class that all game object can inherit from.
 ******************************************************************************/
class GameObject
{
	virtual ~GameObject() {}

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
	virtual ~Updatable() {}

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
	virtual ~Drawable() {}

}; // class Drawable


/*******************************************************************************
 * Update-only game object.
 ******************************************************************************/
class UGameObject: public GameObject, public Updatable
{
	virtual ~UGameObject() {}

}; // class UGameObject


/*******************************************************************************
 * Draw-only game object.
 ******************************************************************************/
class DGameObject: public GameObject, public Drawable
{
	virtual ~DGameObject() {}

}; // class DGameObject


/*******************************************************************************
 * Update and draw game object.
 ******************************************************************************/
class DUGameObject: public UGameObject, public Drawable
{
	virtual ~DUGameObject() {}

}; // class DUGameObject


} // namespace g3

#endif //GAME_OBJETC_H
