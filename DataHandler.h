// File: DataHandler.h
// Description: A class for handling and processing data:
// - allocation memory
// - Reading data
// - Splitting data: training, test, validation
// - Counting the number of classes in the dataset
// Convert to little endian

#ifndef INC_8_TRAINING_MNIST_DATAHANDLER_H
#define INC_8_TRAINING_MNIST_DATAHANDLER_H

#include <fstream>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include "Data.h"


class DataHandler {
    // Vectors containing data
    // Array of Data (each Data keeps featureVector for one image)
    std::vector<Data*> *dataArray;
    std::vector<Data*> *trainingData;
    std::vector<Data*> *testData;
    std::vector<Data*> *validationData;

    // Number of classes in the dataset
    int numClasses{};
    // Size of the data
    int featureVectorSize{};
    // Mapping class labels to integers
    std::map<uint8_t, int> classMap;

    // Splitting data portion
    const double TRAIN_SET_PERCENT = 0.75;
    const double TEST_SET_PERCENT = 0.20;
    const double VALIDATION_PERCENT = 0.05;

public:
    //allocate and deallocate memory
    DataHandler();
    ~DataHandler();

    // Read data file
    void readFeatureData(const std::string& path);
    // Read label file
    void readFeatureLabels(const std::string& path);

    // Split data into training, test, and validation sets
    void splitData();
    // Count the number of classes
    void countClasses();

    // Convert bytes to little-endian
    uint32_t convertToLittleEndian(const unsigned char* bytes);

    const std::vector<Data*>& getTrainingData() const;
    const std::vector<Data*>& getTestData() const;
    const std::vector<Data*>& getValidationData() const;
};



#endif