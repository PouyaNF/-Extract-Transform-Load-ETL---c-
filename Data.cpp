#include "Data.h"

Data::Data() {
    // initializing the featureVector in Data constructor
    featureVector = new std::vector<uint8_t>;
}

Data::~Data() = default;

// Set the featureVector for the data.
void Data::setFeatureVector(std::vector<uint8_t> * vect)
{
    featureVector = vect;
}

// Append a value to the feature vector.
void Data::appendToFeatureVector(const uint8_t val)
{
    featureVector->push_back(val);
}

// Set the label for the data.
void Data::setLabel(const uint8_t labelValue)
{
    label = labelValue;
}

// Set the enumerated label (e.g., A: 1, B: 2, ...).
void Data::setEnumeratedLabel(const int val)
{
    enumLabel = val;
}

// Get the size of the feature vector.
int Data::getFeatureVectorSize() const
{
    return static_cast<int>(featureVector->size());
}

// Get the label.
uint8_t Data::getLabel() const
{
    return label;
}

// Get the enumerated label.
int Data::getEnumeratedLabel() const
{
    return enumLabel;

}

// Get a pointer to the feature vector.
const std::vector<uint8_t>* Data::getFeatureVector() const
{
    return featureVector;

}


