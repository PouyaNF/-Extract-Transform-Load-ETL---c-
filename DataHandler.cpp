#include "DataHandler.h"


DataHandler::DataHandler()
{
    //dynamically allocating memory to each dataset on the heap
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
    uint32_t header[4];  //32 bits unsigned integer array : Magic, num of images, row size, col size
    // to keep binary data
    //Using unsigned char for raw binary data
    unsigned char bytes[4];
    //opens the file specified by the path
    FILE *f = fopen(path.c_str(), "r");
    if (f)
    {
        //reading the first 4 bytes of header
        for (int i =0; i<4 ; i++)
        {
            // if successfully reads one element of size sizeof(bytes)
            if (fread(bytes,sizeof(bytes), 1, f))
            {
                //handle potential endianness differences between the data in the file and the system's native endianness
                header[i] = convertToLittleEndian(bytes);
            }
        }
        printf ("done getting input file header.\n");

        // getting number of all images
        int imageSize = static_cast<int>(header[2] * header[3]);

        // for all number of images in binary file
        for (int i =0; i < header[1]; i++)
        {
            Data * d = new Data();
            uint8_t element[1]; // 1 byte
            for (int j = o; j < imageSize; j++)
            {
                //reading image data and store in element
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
        printf("Successfully read and stored  features. size : %zu \n" , dataArray->size());
    }
    else
    {
        printf("File not found. \n");
        exit(1);
    }
}

void DataHandler::readFeatureLabels(const std::string &path) {

    uint32_t header[2];  //Madic , num of images
    unsigned char bytes[2];
    File *f = fopen(path.c_str(), "r");
    if (f){
        for (int i=0; i<2; i++){
           if (fread(bytes, sizeof(bytes) , 1 , f)){
               header[i] = convertToLittleEndian(bytes);
           }
        }
        printf("Done getting label file header. \n");

        for (int i = 0; i < header[1]; i++ ) {
            uint8_t element[1];
            if (fread(element, sizeof(element) ,1 ,f)){
                dataArray->at(i)->setLabel(element[0]);
            }
            else{
                printf("Error reading label file. \n");
                exit(1);
            }
        }
        printf("Successfully read and stored label Data. Size: %zu\n", dataArray->size());
    }
    else {
        printf("Could not find file");
    }
}

void DataHandler::splitData()
{
    std::unordered_set<int> usedIndexes;
    int trainSize = dataArray->size() * TRAIN_SET_PERCENT;
    int testSize = dataArray->size() * TEST_SET_PERCENT;
    int validateSize = dataArray->size() * VALIDATION_SET_PERCENT;

    // creation of training data
    int count = 0;
    while (count < trainSize){
        int randIndex = rand() % dataArray->size();  // number between rand and dataArray->size()-1
        // if the index is not in usedIndexes set
        if ( (usedIndexes.find(randIndex)) == usedIndexes.end() ){
            trainingData->push_back(dataArray->at(randIndex));
            usedIndexes.insert(randIndex);
        count ++;
        }
    }

    // creation of test data
    count = 0;
    while (count < testSize){
        int randIndex = rand() % dataArray->size();  // number between rand and dataArray->size()-1
        // if the index is not in usedIndexes set
        if ( (usedIndexes.find(randIndex)) == usedIndexes.end() ){
            testData->push_back(dataArray->at(randIndex));
            usedIndexes.insert(randIndex);
            count ++;
        }
    }

    // creation of validation data
    count = 0;
    while (count < validateSize){
        int randIndex = rand() % dataArray->size();  // number between rand and dataArray->size()-1
        // if the index is not in usedIndexes set
        if ( (usedIndexes.find(randIndex)) == usedIndexes.end() ){
            validationData->push_back(dataArray->at(randIndex));
            usedIndexes.insert(randIndex);
            count ++;
        }
    }

    printf("Training Data Size: %zu  \n" , trainingData->size());
    printf("Test Data Size: %zu  \n" , testData->size());
    printf("Validation Data Size: %zu  \n" , validationData->size());
}

void DataHandler::countClasses() {
    int count =0;
    for (unsigned i = 0; i< dataArray->size(); i++){

        // std::map<uint8_t, int> classMap;
        if (classMap.find(dataArray->at(i)->getLabel()) == classMap.end()){
            dataArray->at(i)->setEnumeratedLabel(count);
            count++;
        }
    }
    numClasses = count;
    printf("Successfully Extract %d unique classes. \n", numClasses);
}

uint32_t DataHandler::convertToLittleEndian(const unsigned char *bytes) {





    return 0;
}

const std::vector<Data *> * DataHandler::getTrainingData() const {
    return trainingData;
}

const std::vector<Data *> *DataHandler::getTestData() const {
    return testData;
}

const std::vector<Data *> * DataHandler::getValidationData() const {
    return validationData ;
}

