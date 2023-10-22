
#ifndef INC_8_TRAINING_MNIST_DATA_H
#define INC_8_TRAINING_MNIST_DATA_H

#include <vector>
#include <cstdint>

// Data container to hold feature vectors and labels.
class Data
{
    // Fixed-size data type for precise control over data size and memory layout.
    std::vector<uint8_t> * featureVector; // vector to store all image pixels
    uint8_t label{};
    int enumLabel{}; // An enumerated label (e.g., A: 1, B: 2, ...)

public:
    Data();
    ~Data();

    // Set the feature vector for the data.
    void setFeatureVector(std::vector<uint8_t> *featureVec);

    // Append a value to the feature vector.
    void appendToFeatureVector(uint8_t value);

    // Set the label for the data.
    void setLabel(uint8_t label);

    // Set the enumerated label (e.g., A: 1, B: 2, ...).
    void setEnumeratedLabel(int label);

    // Get the size of the feature vector.
    int getFeatureVectorSize() const;

    // Get the label.
    uint8_t getLabel() const;

    // Ge the enumerated label
    int getEnumeratedLabel() const;

    // Get a pointer to the feature vector.
    const std::vector<uint8_t>* getFeatureVector() const;
};

#endif // INC_8_TRAINING_MNIST_DATA_H

