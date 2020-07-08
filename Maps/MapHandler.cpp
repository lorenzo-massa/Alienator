//
// Created by Lorenzo Massa on 27/05/2020.
//
#include "MapHandler.h"
#include "../Engine/Game.h"


MapHandler::MapHandler(){}

void MapHandler::loadLevel(int x) {
    std::string filename = "Maps/Files/level"+std::to_string(x)+".txt";
    std::basic_ifstream<char> file = std::ifstream(filename);
    if(!(file.is_open())) {
        std::cerr<<"File not found!"<<std::endl;
    }else {
        std::cout << filename << " is opened!" << std::endl;

        int n, m;
        char c;

        file >> n;
        file >> m;

        map = std::make_shared<Map>(n, m);

        int i = 0;
        int j = 0;

        while (i < n) {
            j = 0;
            while (j < m) {

                file.get(c);

                if (c != '\n') {

                    std::shared_ptr<Block> b;
                    std::shared_ptr<Collectable> coll;
                    std::shared_ptr<Enemy> enemy;
                    std::shared_ptr<sf::Sprite> p;


                    switch (c) {
                        case '1':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("1"));
                            map->addToMatrix(b);
                            break;
                        case '2':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("2"));
                            map->addToMatrix(b);
                            break;
                        case '3':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("3"));
                            map->addToMatrix(b);
                            break;
                        case '4':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("4"));
                            map->addToMatrix(b);
                            break;
                        case '5':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("5"));
                            map->addToMatrix(b);
                            break;
                        case '6':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("6"));
                            map->addToMatrix(b);
                            break;
                        case '7':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("7"));
                            map->addToMatrix(b);
                            break;
                        case '8':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("8"));
                            map->addToMatrix(b);
                            break;
                        case '9':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("9"));
                            map->addToMatrix(b);
                            break;
                        case 'A':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("10"));
                            map->addToMatrix(b);
                            break;
                        case 'B':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("11"));
                            map->addToMatrix(b);
                            break;
                        case 'C':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64, i * 64));
                            b->setTexture(AssetManager::textures.at("12"));
                            map->addToMatrix(b);
                            break;
                        case 'D':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("13"));
                            map->addToMatrix(b);
                            break;
                        case 'E':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("14"));
                            map->addToMatrix(b);
                            break;
                        case 'F':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("15"));
                            map->addToMatrix(b);
                            break;
                        case 'G':
                            b = std::make_shared<Block>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            b->setTexture(AssetManager::textures.at("16"));
                            map->addToMatrix(b);
                            break;
                        case 'M':
                            enemy = std::make_shared<Enemy>("Guard",sf::Vector2f(j * 64.0f, i * 64.0f), 50,5,sf::Vector2f(8.0f*64.0f,0),7.0f,sf::Vector2f(128.0f,32.0f),"patrol");
                            map->addEnemy(enemy);
                            break;
                        case 'N':
                            enemy = std::make_shared<Enemy>("Sentinel",sf::Vector2f(j * 64.0f, i * 64.0f), 10,2,sf::Vector2f(5.0f*64.0f,0),3.0f,sf::Vector2f(192.0f,32.0f),"patrol");
                            map->addEnemy(enemy);
                            break;
                        case 'O':
                            enemy = std::make_shared<Enemy>("Wizard",sf::Vector2f(j * 64.0f, i * 64.0f), 20,3,sf::Vector2f(6.5f*64.0f,0),5.0f,sf::Vector2f(128.0f,32.0f),"patrol");
                            map->addEnemy(enemy);
                            break;
                        case 'Q':
                            p = std::make_shared<sf::Sprite>();
                            p->setPosition(sf::Vector2f(j * 64.0f, i * 64.0f));
                            p->setTexture(AssetManager::textures.at("PORTAL"));
                            p->setTextureRect(sf::IntRect(0,0,464,742));
                            p->setScale(sf::Vector2f(0.15,0.17));
                            map->setPortal(p);
                            break;
                        case 'X':
                            coll = std::make_shared<Collectable>(sf::Vector2f(j * 64.0f, i * 64.0f), "COINS");
                            coll->setTexture(AssetManager::textures.at("COINS"));
                            coll->registerObserver(Game::getGame());
                            Game::getGame()->addSubject(coll);
                            map->addCollectable(coll);
                            break;
                        case 'Y':
                            coll = std::make_shared<Collectable>(sf::Vector2f(j * 64.0f, i * 64.0f), "MUNITIONS");
                            coll->setTexture(AssetManager::textures.at("MUNITIONS"));
                            coll->registerObserver(Game::getGame());
                            Game::getGame()->addSubject(coll);
                            map->addCollectable(coll);
                            break;
                        case 'Z':
                            coll = std::make_shared<Collectable>(sf::Vector2f(j * 64.0f, i * 64.0f));
                            coll->setTexture(AssetManager::textures.at("MYSTERY"));
                            coll->registerObserver(Game::getGame());
                            Game::getGame()->addSubject(coll);
                            map->addCollectable(coll);
                            break;
                        case 'P':
                            Game::getGame()->createHero(j * 64.0f, i * 64.0f);
                            break;
                        default:
                            break;
                    }
                    j++;
                }
            }
            i++;
        }
    }
}

std::shared_ptr<Map> MapHandler::getMap() {
    return map;
}

MapHandler::~MapHandler() {}

