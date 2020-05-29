//
// Created by Lorenzo Massa on 25/05/2020.
//

#ifndef ALIENATOR_MAINMENU_H
#define ALIENATOR_MAINMENU_H


#include <SFML/Graphics.hpp>
#include <memory>

class MainMenu {
public:
    class MenuItem : public sf::Text {
    public:
        enum TYPE {
            START,
            EXIT,
            RESUME,
            QUIT,
        };
        explicit MenuItem(MenuItem::TYPE type);
        const TYPE& getType() const;

    private:
        TYPE type;
    };

    enum STYLE {
        CENTERED,
        MAIN
    };
    explicit MainMenu(STYLE style);
    ~MainMenu();
    void draw(const std::shared_ptr<sf::RenderWindow>& window);
    void forward();
    void backward();
    const MenuItem::TYPE& getAction() const;


private:
    int active {0};
    int count {0};
    sf::Font font;
    std::vector<std::shared_ptr<MenuItem>> itemList;
    STYLE style;


};
#endif //ALIENATOR_MAINMENU_H
