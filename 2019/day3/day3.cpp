#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>


struct Path {
    char direction;
    int value;
};

struct Point {
    int x;
    int y;

    bool operator<(const Point &Other) const;

    bool operator==(const Point &Other) const;
};

bool Point::operator<(const Point &other) const {
    return x < other.x || (x == other.x && y < other.y);
}

bool Point::operator==(const Point &other) const {
    return other.x == x && other.y == y;
}


std::vector<Path> getPaths(const std::string filename);
std::vector<std::string> getLines(const std::string filename);
std::vector<Point> getPoints(std::vector<Path> paths);

int manhattanDistance(int x1, int x2, int y1, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    // to compute exec time
    auto start = std::chrono::steady_clock::now();

    std::vector<std::string> lines = getLines("day3.txt");

    std::vector<Point> pointsOne = getPoints(getPaths(lines[0]));
    std::vector<Point> pointsTwo = getPoints(getPaths(lines[1]));
    std::vector<int> distances;
    std::vector<int> steps;

    std::set<Point> wireOne;
    std::set<Point> wireTwo;
    std::vector<Point> intersectionPoints;

    for (const auto p : pointsOne) {
        wireOne.insert(p);
    }

    for (const auto p : pointsTwo) {
        wireTwo.insert(p);
    }

    std::set_intersection(wireOne.begin(), wireOne.end(),
                          wireTwo.begin(), wireTwo.end(),
                          std::back_inserter(intersectionPoints));

    for (const auto p: intersectionPoints) {
        distances.push_back(manhattanDistance(0, p.x, 0, p.y));
        ptrdiff_t pos1 = distance(pointsOne.begin(), find(pointsOne.begin(), pointsOne.end(), p));
        ptrdiff_t pos2 = distance(pointsTwo.begin(), find(pointsTwo.begin(), pointsTwo.end(), p));
        steps.push_back(pos1 + pos2 + 2);
    }

    std::cout << "ans1= " << *min_element(distances.begin(), distances.end()) << std::endl;
    std::cout << "ans2= " << *min_element(steps.begin(), steps.end()) << std::endl;

    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
}

std::vector<std::string> getLines(const std::string filename) {
    std::ifstream is(filename);
    std::vector<std::string> lines;
    std::string line;
    while (is.good()) {
        getline(is, line, '\n');
        lines.push_back(line);
    }
    return lines;
}

std::vector<Path> getPaths(const std::string line) {
    std::vector<Path> paths;
    std::istringstream ss(line);
    std::string path;
    while (ss.good()) {
        getline(ss, path, ',');
        Path p = {path[0], std::stoi(path.substr(1, path.size()))};
        paths.push_back(p);
    }
    return paths;
}

std::vector<Point> getPoints(std::vector<Path> paths) {
    std::vector<Point> points;
    int x = 0;
    int y = 0;

    for (const auto p : paths) {
        switch (p.direction) {
            case 'L':
                for (int i = 1; i <= p.value; i++) {
                    points.push_back(Point{x - i, y});
                }
                x -= p.value;

                break;
            case 'R':
                for (int i = 1; i <= p.value; i++) {
                    points.push_back(Point{x + i, y});
                }
                x += p.value;
                break;

            case 'U':
                for (int i = 1; i <= p.value; i++) {
                    points.push_back(Point{x, y + i});
                }
                y += p.value;
                break;

            case 'D':
                for (int i = 1; i <= p.value; i++) {
                    points.push_back(Point{x, y - i});
                }
                y -= p.value;
                break;
        }
    }
    return points;
}
