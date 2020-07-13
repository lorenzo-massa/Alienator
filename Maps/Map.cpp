//
// Created by Lorenzo Massa on 30/05/2020.
//

#include <fstream>
#include "Map.h"
#include "../Engine/Game.h"

Map::Map() {
    enemies = std::vector<std::shared_ptr<Enemy>>();
    collectables = std::vector<std::shared_ptr<Collectable>>();
    mapMatrix = std::vector<std::shared_ptr<Tile>>();
    bullets = std::vector<std::shared_ptr<Bullet>>();
    portal = std::make_shared<sf::Sprite>();
}

void Map::addToMatrix(const std::shared_ptr<Tile>& x) {
    mapMatrix.push_back(x);
}

void Map::removeFromMatrix(int i) {
    mapMatrix.erase(mapMatrix.begin() + i);
}

std::shared_ptr<sf::Sprite> Map::getFromMatrix(int i) {
    return mapMatrix[i];
}

void Map::addEnemy(const std::shared_ptr<Enemy>& e) {
    enemies.push_back(e);
}

void Map::removeEnemy(int i) {
    enemies.erase(enemies.begin() + i);
}

std::shared_ptr<Enemy> Map::getEnemy(int i) {
    return enemies[i];
}


std::vector<std::shared_ptr<Tile>> Map::getMatrix() {
    return mapMatrix;
}

std::vector<std::shared_ptr<Enemy>> Map::getEnemies() {
    return enemies;
}

void Map::addCollectable(const std::shared_ptr<Collectable>& c) {
    collectables.push_back(c);
}

void Map::removeCollectable(int i) {
    collectables.erase(collectables.begin() + i);
}

std::shared_ptr<Collectable> Map::getCollectable(int i) {
    return collectables[i];
}

std::vector<std::shared_ptr<Collectable>> Map::getCollectables() {
    return collectables;
}

void Map::addBullet(const std::shared_ptr<Bullet>& b) {
    bullets.push_back(b);
}

void Map::removeBullet(int i) {
    bullets.erase(bullets.begin() + i);
}

std::shared_ptr<Bullet> Map::getBullet(int i) {
    return bullets[i];
}

std::vector<std::shared_ptr<Bullet>> Map::getBullets() {
    return bullets;
}

const std::shared_ptr<sf::Sprite> &Map::getPortal() const {
    return portal;
}

void Map::setPortal(const std::shared_ptr<sf::Sprite> &portal) {
    Map::portal = portal;
}

int Map::getN() const {
    return n;
}

void Map::setN(int n) {
    Map::n = n;
}

int Map::getM() const {
    return m;
}

void Map::setM(int m) {
    Map::m = m;
}

void Map::loadLevel(int x) {
    std::string filename = "Maps/Files/level" + std::to_string(x) + ".txt";
    std::basic_ifstream<char> file = std::ifstream(filename);
    if (!(file.is_open())) {
        std::cerr << "File not found!" << std::endl;
    } else {
        std::cout << filename << " is opened!" << std::endl;

        char c;

        file >> n;
        file >> m;

        mapMatrix.reserve(n * m);

        int i = 0;
        int j = 0;

        while (i < n) {
            j = 0;
            while (j < m) {

                file.get(c);

                if (c != '\n') {

                    std::shared_ptr<Tile> b;
                    std::shared_ptr<Collectable> coll;
                    std::shared_ptr<Enemy> enemy;
                    std::shared_ptr<sf::Sprite> p;


                    switch (c) {
                        case '1':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("1"));
                            addToMatrix(b);
                            break;
                        case '2':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("2"));
                            addToMatrix(b);
                            break;
                        case '3':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("3"));
                            addToMatrix(b);
                            break;
                        case '4':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("4"));
                            addToMatrix(b);
                            break;
                        case '5':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("5"));
                            addToMatrix(b);
                            break;
                        case '6':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("6"));
                            addToMatrix(b);
                            break;
                        case '7':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("7"));
                            addToMatrix(b);
                            break;
                        case '8':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("8"));
                            addToMatrix(b);
                            break;
                        case '9':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("9"));
                            addToMatrix(b);
                            break;
                        case 'A':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("10"));
                            addToMatrix(b);
                            break;
                        case 'B':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("11"));
                            addToMatrix(b);
                            break;
                        case 'C':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);

                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("12"));
                            addToMatrix(b);
                            break;
                        case 'D':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("13"));
                            addToMatrix(b);
                            break;
                        case 'E':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("14"));
                            addToMatrix(b);
                            break;
                        case 'F':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("15"));
                            addToMatrix(b);
                            break;
                        case 'G':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Full);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("16"));
                            addToMatrix(b);
                            break;
                        case 'M':
                            enemy = std::make_shared<Enemy>("Guard", sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), 1000, 1,
                                                            sf::Vector2f(8.0f * BLOCK_SIZE, 0), 7.0f,
                                                            sf::Vector2f(BLOCK_SIZE * 5.0f, BLOCK_SIZE * 4.0f), "patrol");
                            addEnemy(enemy);
                            break;
                        case 'N':
                            enemy = std::make_shared<Enemy>("Sentinel", sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), 600, 1,
                                                            sf::Vector2f(5.0f * BLOCK_SIZE, 0), 3.0f,
                                                            sf::Vector2f(BLOCK_SIZE * 8.0f, BLOCK_SIZE * 5.0f), "patrol");
                            addEnemy(enemy);
                            break;
                        case 'O':
                            enemy = std::make_shared<Enemy>("Wizard", sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), 800, 1,
                                                            sf::Vector2f(6.5f * BLOCK_SIZE, 0), 5.0f,
                                                            sf::Vector2f(BLOCK_SIZE * 6.0f, BLOCK_SIZE * 3.0f), "patrol");
                            addEnemy(enemy);
                            break;
                        case 'Q':
                            p = std::make_shared<sf::Sprite>();
                            p->setPosition(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE));
                            p->setTexture(AssetManager::getAssetManager()->getTextures().at("PORTAL"));
                            p->setTextureRect(sf::IntRect(0, 0, 464, 742));
                            p->setScale(sf::Vector2f(0.15, 0.17));
                            setPortal(p);
                            break;
                        case 'X':
                            coll = std::make_shared<Collectable>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), PowerUp::TYPE::COINS);
                            coll->setTexture(AssetManager::getAssetManager()->getTextures().at("COINS"));
                            coll->registerObserver(Game::getGame());
                            Game::getGame()->addSubject(coll);
                            addCollectable(coll);
                            break;
                        case 'Y':
                            coll = std::make_shared<Collectable>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), PowerUp::TYPE::MUNITIONS);
                            coll->setTexture(AssetManager::getAssetManager()->getTextures().at("MUNITIONS"));
                            coll->registerObserver(Game::getGame());
                            Game::getGame()->addSubject(coll);
                            addCollectable(coll);
                            break;
                        case 'Z':
                            coll = std::make_shared<Collectable>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE));
                            coll->setTexture(AssetManager::getAssetManager()->getTextures().at("MYSTERY"));
                            coll->registerObserver(Game::getGame());
                            Game::getGame()->addSubject(coll);
                            addCollectable(coll);
                            break;
                        case 'P':
                            Game::getGame()->createHero(j * BLOCK_SIZE, i * BLOCK_SIZE);
                            break;
                        default:
                            break;
                        case 'T':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Invisible);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("5"));
                            addToMatrix(b);
                            break;
                        case 'R':
                            b = std::make_shared<Tile>(sf::Vector2f(j * BLOCK_SIZE, i * BLOCK_SIZE), sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), typeTile::Breakable);
                            b->setTexture(AssetManager::getAssetManager()->getTextures().at("5"));
                            addToMatrix(b);
                            break;
                    }
                    j++;
                }
            }
            i++;
        }
        std::cout<<"Map loaded!"<<std::endl;
    }
}

void Map::reset(){
    enemies.clear();
    collectables.clear();
    mapMatrix.clear();
    bullets.clear();
    portal = nullptr;
}

Map::~Map() {
    enemies.clear();
    collectables.clear();
    mapMatrix.clear();
    bullets.clear();
}


