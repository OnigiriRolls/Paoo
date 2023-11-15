#pragma once
#include <iostream>
#include <string.h>

namespace Underworld {
    class GameStatistics
    {
    public:
        GameStatistics(int zombiesKilled, int bloodDrinks);
        GameStatistics(const GameStatistics& other);
        GameStatistics(GameStatistics&& other) noexcept;
        ~GameStatistics();
        GameStatistics& operator=(const GameStatistics& other);
        GameStatistics& operator=(GameStatistics&& other) noexcept;
        void setStatistics(const char* statistics);
        void getStatistics() const;
        void setZomiesKilled(int zombiesKilled);
        int getZomiesKilled() const;
        void setBloodDrinks(int bloodDrinks);
        int getBloodDrinks() const;
        void setScore(double score);
        double getScore() const;

    private:
        char* statistics;
        int zombiesKilled;
        int bloodDrinks;
        double score;
    };
}

namespace Arena {
    class GameStatistics
    {
    public:
        GameStatistics(int playersKilled, int maxCombos);
        GameStatistics(const GameStatistics& other);
        GameStatistics(GameStatistics&& other) noexcept;
        ~GameStatistics();
        GameStatistics& operator=(const GameStatistics& other);
        GameStatistics& operator=(GameStatistics&& other) noexcept;
        void setStatistics(const char* statistics);
        void getStatistics() const;
        void setPlayersKilled(int playersKilled);
        int getPlayersKilled() const;
        void setMaxCombos(int maxCombos);
        int getMaxCombos() const;
        void setScore(double score);
        double getScore() const;

    private:
        char* statistics;
        int playersKilled;
        int maxCombos;
        double score;
    };
}
