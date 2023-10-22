
#include "DataHandler.h"


DataHandler::DataHandler()
{
    //dynamically allocate memory to each dataset
    dataArray =  new std::vector<Data *>;
    testData = new std::vector<Data *>;
    trainingData = new std::vector<Data *>;
    validationData = new std::vector<Data *>;
}

// free dynamically allocated memory
DataHandler::~DataHandler() = default;


//reads image data from a binary file specified by the path
void DataHandler::readFeatureData(const std::string &path)
{
    // to store header
    uint32_t header[4];  //32 bit unsigned integer array : Magic, num of images, row size, col size
    // to keep binary data
    unsigned char bytes[4];
    //opens the file specified by the path
    FILE *f = fopen(path.c_str(), "r");
    if (f)
    {
        //reading the first 4 bytes of data (header)
        for (int i =0; i<4 ; i++)
        {
            if (fread(bytes,sizeof(bytes), 1, f))
            {
                //handle potential endianness differences between the data in the file and the system's native endianness
                header[i] = convertToLittleEndian(bytes);
            }
        }
        printf ("done getting file header.\n");
        int imageSize = header[2] * header[3];

        // for number of images in binary file
        for (int i =0; i < header[1]; i++)
        {
            Data * d = new Data();
            uint8_t element[1];
            for (int j = o; j < imageSize; j++)
            {
                //reading image data and store in element[0]
                if(fread(element, sizeof(element), 1, f))
                {
                    d->appendToFeatureVector(element[0]);
                }
                else
                {
                    printf("Error reading from file. \n");
                    exit(1);
                }
            }
            dataArray ->push_back(d);
        }
        printf("Successfully read data and store to feature vector  \n");
    }
    else
    {
        printf("File not found. \n");
        exit(1);
    }
}

void DataHandler::readFeatureLabels(const std::string &path) {

}

void DataHandler::splitData()
{

}

void DataHandler::countClasses() {

}

uint32_t DataHandler::convertToLittleEndian(const unsigned char *bytes) {
    return 0;
}

const std::vector<Data *> &DataHandler::getTrainingData() const {
    return <#initializer#>;
}

const std::vector<Data *> &DataHandler::getTestData() const {
    return <#initializer#>;
}

const std::vector<Data *> &DataHandler::getValidationData() const {
    return <#initializer#>;
}

