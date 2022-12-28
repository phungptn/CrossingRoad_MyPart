#include "animal.hpp"

void Cat::innitTexture()
{
    if (catTexture.loadFromFile("assets/images/truck1.png"))
    {
        std::cout << "Fail texture";
    }
    this->cat.setTexture(catTexture);
    this->cat.scale(0.5, 0.5);
}
void Dog::innitTexture()
{
    if (dogTexture.loadFromFile("assets/images/truck1.png"))
    {
        std::cout << "Fail texture";
    }
    this->dog.setTexture(dogTexture);
    this->dog.scale(0.5, 0.5);
}

void Animal::spawn(float y, const OBJECT_TYPE type)
{
    if (type == OBJECT_TYPE::CAT)
    {
        int k = 0;
        for (int i = 0; i < 5; i++)
        {

            int dis = rand() % 300;
            this->animals.push_back(new Cat(k, y));
            k = this->animals.back()->getPos();
            k -= (dis + 50);
        }
    }

    else if (type == OBJECT_TYPE::DOG)
    {
        int k = 0;
        for (int i = 0; i < 5; i++)
        {

            int dis = rand() % 300;
            this->animals.push_back(new Dog(k, y));
            k = this->animals.back()->getPos();
            k -= (dis + 50);
        }
    }
}

int Animal::getPos()
{
    return 0;
}
int Cat::getPos()
{
    return this->cat.getPosition().x;
}

void Animal::Render(Engine::Context::pointer_type &context)
{
    for (auto *ani : this->animals)
    {
        ani->Render(context);
    }
}
void Cat::Render(Engine::Context::pointer_type &context)
{
    context->window->draw(this->cat);
}
void Dog::Render(Engine::Context::pointer_type &context)
{
    context->window->draw(this->dog);
}

void Animal::update(float velocity)
{
    for (auto *ani : this->animals)
    {
        ani->update(velocity);
    }
}
void Cat::update(float velocity)
{
    this->cat.move(velocity, 0);
}

void Dog::update()
{
    this->dog.move(5.f, 0);
}
