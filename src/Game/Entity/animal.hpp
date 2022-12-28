#ifndef SRC_GAME_ENTITY_ANIMAL
#define SRC_GAME_ENTITY_ANIMAL
#include "object.hpp"
#include <vector>
#include <iostream>
#include <time.h>
#include "../../Framework/pch.hpp"

class Animal
{
private:
    // sf::Vector2f aniVelocity;
    std::vector<Animal *> animals;

public:
    Animal() = default;
    void spawn(float y, const OBJECT_TYPE type);
    virtual int getPos();
    virtual void Render(Engine::Context::pointer_type &context);
    virtual void update(const float velocity);
};

class Cat : public Animal
{
public:
    int getPos();

    Cat() = default;
    Cat(float x, float y)
    {
        this->innitTexture();
        this->cat.setPosition(x, y);
    }
    void innitTexture();
    void Render(Engine::Context::pointer_type &context);
    void update(const float velocity);

private:
    sf::Sprite cat;
    sf::Texture catTexture;

private:
};
class Dog : public Animal
{
public:
    void setVelocity(float x, float y);
    void setStartPosition(float x, float y);
    sf::Vector2f getVelocity();
    Dog() = default;
    Dog(float x, float y)
    {
        this->innitTexture();
        this->dog.setPosition(x, y);
    }
    void innitTexture();
    void update();
    void Render(Engine::Context::pointer_type &context);

public:
    sf::Sprite dog;
    sf::Texture dogTexture;
    sf::Vector2f dogVelocity;
    sf::Vector2f dogPos;

private:
};
#endif // SRC_INCLUDES_ANIMAL_ANIMAL_HPP