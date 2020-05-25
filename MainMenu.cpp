//
// Created by Lorenzo Massa on 25/05/2020.
//

#include <iostream>
#include "MainMenu.h"

MainMenu::MenuItem::MenuItem(MainMenu::MenuItem::TYPE type) : type(type){
    std::string btnText;
    switch (type) {
        case MenuItem::TYPE::START:
            btnText = "Play";
            break;
        case MenuItem::TYPE::EXIT:
            btnText = "Exit the game";
            break;
        case MenuItem::TYPE::QUIT:
            btnText = "Quit";
            break;
        case MenuItem::TYPE::RESUME:
            btnText = "Resume";
            break;
        default:
            std::cerr << "Object error!";
    }
    setString(btnText);
}

const MainMenu::MenuItem::TYPE& MainMenu::MenuItem::getType() const {
    return type;
}

MainMenu::MainMenu(MainMenu::STYLE style) : style(style){
    if(!font.loadFromFile("./Assets/Font/mainFont.otf"))
        std::cerr << "Font not found" << std::endl;
    if(style == MainMenu::STYLE::MAIN) {
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::START));
        itemList[1]->setFont(font);
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::EXIT));
        itemList[2]->setFont(font);
        itemList[active]->setFont(font);
        itemList[active]->setFillColor(sf::Color::Red);
        count = itemList.size();
    } else if (style == MainMenu::STYLE::CENTERED) {
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::RESUME));
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::QUIT));
        itemList[active]->setFillColor(sf::Color::Red);
        count = itemList.size();
    } else std::cerr << "Error: Menu not found";

}

MainMenu::~MainMenu() {
    itemList.clear();
}

void MainMenu::draw(const std::shared_ptr<sf::RenderWindow>& window) {
    sf::View actualView = window->getView();
    sf::Vector2f origin, dim, pos;
    dim = actualView.getSize();
    origin = actualView.getCenter();
    origin.x -= dim.x / 2;
    origin.y -= dim.y / 2;

    if (style == STYLE::MAIN) {
        int height = count * (64 + 8);
        pos = actualView.getCenter();
        pos.y -= height / 2;
        for (auto i : itemList) {
            i->setCharacterSize(64);
            sf::FloatRect s = i->getGlobalBounds();
            i->setPosition(pos.x, pos.y);
            i->setOrigin(s.width / 2 , s.height / 2);
            pos.y += 72;
            window->draw(*i);
        }
    } else if (style == STYLE::CENTERED) {
        int height = count * (64 + 8);
        pos = actualView.getCenter();
        pos.y -= height / 2;
        for (auto i : itemList) {
            i->setCharacterSize(64);
            i->setFont(font);
            sf::FloatRect s = i->getGlobalBounds();
            i->setPosition(pos.x, pos.y);
            i->setOrigin(s.width / 2 , s.height / 2);
            pos.y += 72;
            window->draw(*i);
        }
    }
}

void MainMenu::forward() {
    itemList[active]->setFillColor(sf::Color::White);
    if (active >= count - 1)
        active = 0;
    else active++;
    itemList[active]->setFillColor(sf::Color::Red);
}
void MainMenu::backward() {
    itemList[active]->setFillColor(sf::Color::White);
    if (active == 0)
        active = count - 1;
    else active--;
    itemList[active]->setFillColor(sf::Color::Red);
}

const MainMenu::MenuItem::TYPE& MainMenu::getAction() const {
    return itemList[active]->getType();
}
