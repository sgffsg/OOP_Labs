//
// Created by Sakata on 05.06.2025.
//

#include "../include/FillGrid.h"
#include <fstream>
#include <string>
#include <vector>
#include <queue>

const int MAX_WIDTH = 100;
const int MAX_HEIGHT = 100;

const char FILL_SYMBOL = '.';
const char WALL_SYMBOL = '#';
const char POINT_SYMBOL = 'O';
const char EMPTY_SYMBOL = ' ';

enum class SymbolCode
{
    EMPTY_CELL = 0,
    POINT = 1,
    WALL = 2,
    FILL = 3
};

struct Position
{
    int x;
    int y;
};

std::vector<std::vector<SymbolCode>> ReadInput(std::istream& input)
{
    int lineIndex = 0;
    std::string inputLine;
    std::vector<std::vector<SymbolCode>> grid;

    while (std::getline(input, inputLine) && lineIndex < MAX_HEIGHT)
    {
        std::vector<SymbolCode> horizontalVector;

        for (int i = 0; i < inputLine.length() && i < MAX_WIDTH; ++i)
        {
            SymbolCode symbolCode = SymbolCode::EMPTY_CELL;
            if (inputLine[i] == POINT_SYMBOL)
            {
                symbolCode = SymbolCode::POINT;
            }
            else if (inputLine[i] == WALL_SYMBOL)
            {
                symbolCode = SymbolCode::WALL;
            }

            horizontalVector.push_back(symbolCode);
        }
        grid.push_back(horizontalVector);

        ++lineIndex;
    }

    return grid;
}

void WriteGrid(std::ostream& output, const std::vector<std::vector<SymbolCode>>& grid)
{

    for (const auto& horizontalVector : grid)
    {
        for (const auto& symbolCode : horizontalVector)
        {
            char symbol = EMPTY_SYMBOL;
            switch (symbolCode)
            {
            case SymbolCode::WALL:
                symbol = WALL_SYMBOL;
                break;
            case SymbolCode::FILL:
                symbol = FILL_SYMBOL;
                break;
            case SymbolCode::POINT:
                symbol = POINT_SYMBOL;
                break;
            default:
                break;
            }
            output << symbol;
        }
        output << std::endl;
    }
}

std::vector<Position> GetPointPositions(const std::vector<std::vector<SymbolCode>>& grid)
{
    std::vector<Position> positions;

    for (auto row = 0; row < grid.size(); ++row)
    {
        for (auto column = 0; column < grid[row].size(); ++column)
        {
            if (grid[row][column] == SymbolCode::POINT)
            {
                positions.emplace_back(column, row);
            }
        }
    }

    return positions;
}

bool IsEdge(const Position& pos, const std::vector<std::vector<SymbolCode>>& grid)
{
    if (pos.x < 0 || pos.y < 0 || pos.y >= grid.size() || pos.x >= grid[pos.y].size())
    {
        return true;
    }

    return false;
}

void FillArea(std::vector<std::vector<SymbolCode>>& map, const Position& point)
{
    if (IsEdge(point, map))
    {
        return;
    }

    if (map[point.y][point.x] != SymbolCode::POINT)
    {
        return;
    }

    const std::vector<Position> fillDirections = {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 }
    };

    std::vector<Position> visited;
    std::queue<Position> pointQueue;
    pointQueue.push(point);
    bool isStartPosition = true;

    while (!pointQueue.empty())
    {
        auto front = pointQueue.front();
        pointQueue.pop();

        if (!isStartPosition && map[front.y][front.x] != SymbolCode::EMPTY_CELL)
        {
            continue;
        }

        visited.push_back(front);
        map[front.y][front.x] = isStartPosition ? SymbolCode::POINT : SymbolCode::FILL;
        isStartPosition = false;

        for (const auto& dir : fillDirections)
        {
            Position nextPos(front.x + dir.x, front.y + dir.y);
            if (!IsEdge(nextPos, map)
                && map[nextPos.y][nextPos.x] == SymbolCode::EMPTY_CELL)
            {
                pointQueue.push(nextPos);
            }
        }
    }
}

void FillGrid(std::istream& input, std::ostream& output)
{
    std::vector<std::vector<SymbolCode>> grid = ReadInput(input);
    std::vector<Position> positions = GetPointPositions(grid);

    for (const auto& position : positions)
    {
        FillArea(grid, position);
    }

    WriteGrid(output, grid);
}
