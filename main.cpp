
#include "Data.h"
#include "DataHandler.h"



int main(){

    std::string pathToTrainImageData = R"(C:\Users\pooya\Desktop\C++ projects\8 - ETL - c++\datasets\train-images.idx3-ubyte)";
    std::string pathToTrainLabelData = R"(C:\Users\pooya\Desktop\C++ projects\8 - ETL - c++\datasets\train-labels.idx1-ubyte)";
    auto* Handler = new DataHandler();
    Handler->readFeatureVector(pathToTrainImageData);
    Handler->readFeatureLabels(pathToTrainLabelData);
    Handler->splitData();
    Handler->countClasses();
}
