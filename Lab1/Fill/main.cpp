#include <fstream>
#include <iostream>
#include <optional>
#include "include/FillGrid.h"

enum class WorkMode
{
    INFO,
    STDIN,
    CLI,
};

struct Args
{
    std::string inputFileName;
    std::string outputFileName;
    WorkMode workMode;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    Args args;
    if (argc == 1)
    {
        args.workMode = WorkMode::STDIN;
        return args;
    }
    else if (argc == 2 && std::string(argv[1]) == "-h")
    {
        args.workMode = WorkMode::INFO;
        return args;
    }
    else if (argc == 3)
    {
        args.workMode = WorkMode::CLI;
        args.inputFileName = argv[1];
        args.inputFileName = argv[2];
        return args;
    }
    else
        return std::nullopt;
}

void ShowInfo()
{
    std::cout << "Usage:" << std::endl;
    std::cout << "CLI MODE: Empty.exe <input File> <output File>" << std::endl;
    std::cout << "STDIN MODE: <image>" << std::endl;
}

int main(int argc, char* argv[]) {
    std::ifstream input;
    std::ofstream output;

    try
    {
        auto args = ParseArgs(argc, argv);

        switch (args->workMode)
        {
        case WorkMode::CLI:
            {
                input.open(args->inputFileName);
                output.open(args->outputFileName);
                FillGrid(input, output);
            }
            break;
        case WorkMode::STDIN:
            FillGrid(std::cin, std::cout);
            break;
        case WorkMode::INFO:
            ShowInfo();
            break;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
        return 1;
    }

    return 0;
}