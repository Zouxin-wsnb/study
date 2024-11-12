#include "minidb.hpp"

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input.sql> <output.csv>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    MiniDB db;
    executeSQL(inputFile, outputFile, db);

    return 0;
}