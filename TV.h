#pragma once
#include "Audio.h"
#include "Visual.h"
class TV :
    public Audio,
    public Visual
{
    private:
        int screenSize;
    protected:
        double screenRatio;
    public:
        TV();
        TV(int size, double ratio);
        int getNumberOfColors();
        double getScreenRatio();
        bool setScreenRatio(double ratio);
        int getScreenSize();
        bool setScreenSize(int size);
        virtual std::string about();
        void importData(std::vector<std::string> v);
        std::vector<std::string> exportData();
};

