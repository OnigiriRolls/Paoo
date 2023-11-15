#include "GameStatistics.hpp"

namespace Underworld {
    GameStatistics::GameStatistics(int zombiesKilled, int bloodDrinks)
    {
        this->zombiesKilled = zombiesKilled;
        this->bloodDrinks = bloodDrinks;
        this->score = zombiesKilled*100 - bloodDrinks*3;
        this->statistics = NULL;
    }

    GameStatistics::GameStatistics(const GameStatistics& other)
    {
        setStatistics(other.statistics);
        this->zombiesKilled = other.zombiesKilled;
        this->bloodDrinks = other.bloodDrinks;
        this->score = other.score;
    }

    GameStatistics::GameStatistics(GameStatistics&& other) noexcept
    {
        delete[] this->statistics;
        this->statistics = other.statistics;
        this->zombiesKilled = other.zombiesKilled;
        this->bloodDrinks = other.bloodDrinks;
        this->score = other.score;

        other.statistics = NULL;
        other.zombiesKilled = 0;
        other.bloodDrinks = 0;
        other.score = 0.0;
    }

    GameStatistics::~GameStatistics()
    {
        delete[] this->statistics;
    }

    GameStatistics& GameStatistics::operator=(const GameStatistics& other)
    {
        std::cout << "Underworld GameStatistics copy operator = overload was called" << std::endl;
        if (this != &other)
        {
            setStatistics(other.statistics);
            this->zombiesKilled = other.zombiesKilled;
            this->bloodDrinks = other.bloodDrinks;
            this->score = other.score;
        }
        return *this;
    }

    GameStatistics& GameStatistics::operator=(GameStatistics&& other) noexcept
    {
        std::cout << "Underworld GameStatistics move operator = overload was called" << std::endl;
        
        if (this != &other)
        {
            delete[] this->statistics;
            this->statistics = other.statistics;
            this->zombiesKilled = other.zombiesKilled;
            this->bloodDrinks = other.bloodDrinks;
            this->score = other.score;

            other.statistics = NULL;
            other.zombiesKilled = 0;
            other.bloodDrinks = 0;
            other.score = 0.0;
        }
        return *this;
    }

    void GameStatistics::setStatistics(const char* statistics) 
    {
        delete[] this->statistics;
        this->statistics = new char[strlen(statistics) + 1];
        strcpy(this->statistics, statistics);
    }

    void GameStatistics::getStatistics() const
    {
        std::cout << "Zombies killed: " << this->zombiesKilled << std::endl
            << "Blood drinks used: " << this->bloodDrinks << std::endl
            << "Score: " << this->score << std::endl;
    }

    void GameStatistics::setZomiesKilled(int zombiesKilled)
    {
        this->zombiesKilled = zombiesKilled;
    }

    int GameStatistics::getZomiesKilled() const
    {
        return this->zombiesKilled;
    }

    void GameStatistics::setBloodDrinks(int bloodDrinks)
    {
        this->bloodDrinks = bloodDrinks;
    }

    int GameStatistics::getBloodDrinks() const
    {
        return this->bloodDrinks;
    }

    void GameStatistics::setScore(double score)
    {
        this->score = score;
    }

    double GameStatistics::getScore() const
    {
        return score;
    }
}

namespace Arena {
    GameStatistics::GameStatistics(int playersKilled, int maxCombos)
    {
        this->playersKilled = playersKilled;
        this->maxCombos = maxCombos;
        this->score = playersKilled*10 + maxCombos*50;
        this->statistics = NULL;
    }

    GameStatistics::GameStatistics(const GameStatistics& other)
    {
        setStatistics(other.statistics);
        this->playersKilled = other.playersKilled;
        this->maxCombos = other.maxCombos;
        this->score = other.score;
    }

    GameStatistics::GameStatistics(GameStatistics&& other) noexcept
    {
        delete[] this->statistics;
        this->statistics = other.statistics;
        this->playersKilled = other.playersKilled;
        this->maxCombos = other.maxCombos;
        this->score = other.score;

        other.statistics = NULL;
        other.playersKilled = 0;
        other.maxCombos = 0;
        other.score = 0.0;
    }

    GameStatistics::~GameStatistics()
    {
        delete[] this->statistics;
    }

    GameStatistics& GameStatistics::operator=(const GameStatistics& other)
    {
        std::cout << "Arena GameStatistics copy operator = overload was called" << std::endl;
        if (this != &other)
        {
            setStatistics(other.statistics);
            this->playersKilled = other.playersKilled;
            this->maxCombos = other.maxCombos;
            this->score = other.score;
        }
        return *this;
    }

    GameStatistics& GameStatistics::operator=(GameStatistics&& other) noexcept
    {
        std::cout << "Arena GameStatistics move operator = overload was called" << std::endl;

        if (this != &other)
        {
            delete[] this->statistics;
            this->statistics = other.statistics;
            this->playersKilled = other.playersKilled;
            this->maxCombos = other.maxCombos;
            this->score = other.score;

            other.statistics = NULL;
            other.playersKilled = 0;
            other.maxCombos = 0;
            other.score = 0.0;
        }
        return *this;
    }

    void GameStatistics::setStatistics(const char* statistics)
    {
        delete[] this->statistics;
        this->statistics = new char[strlen(statistics) + 1];
        strcpy(this->statistics, statistics);
    }

    void GameStatistics::getStatistics() const
    {
        std::cout << "Players killed: " << this->playersKilled << std::endl
            << "Max combos achieved: " << this->maxCombos << std::endl
            << "Score: " << this->score << std::endl;
    }

    void GameStatistics::setPlayersKilled(const int playersKilled)
    {
        this->playersKilled = playersKilled;
    }

    int GameStatistics::getPlayersKilled() const
    {
        return this->playersKilled;
    }

    void GameStatistics::setMaxCombos(const int maxCombos)
    {
        this->maxCombos = maxCombos;
    }

    int GameStatistics::getMaxCombos() const
    {
        return this->maxCombos;
    }

    void GameStatistics::setScore(double score)
    {
        this->score = score;
    }

    double GameStatistics::getScore() const
    {
        return score;
    }
}
