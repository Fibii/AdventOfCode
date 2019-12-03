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
    return other.x < x && other.y < y;
}

bool Point::operator==(const Point &other) const {
    return other.x == x && other.y == y;
}



struct Wire {
    std::vector<Point> points;
    int i;
    int j;
};


std::vector<Path> getPaths(const std::string filename);
std::vector<std::string> getLines(const std::string filename);
std::vector<Point> getPoints(std::vector<Path> paths);

int manhattanDistance(int x1, int x2, int y1, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    std::vector<std::string> lines = getLines("day3.txt");

    std::vector<Point> pointsOne = getPoints(getPaths(lines[0]));
    std::vector<Point> pointsTwo = getPoints(getPaths(lines[1]));
    std::vector<int> distances;
    std::vector<int> steps;

    for(auto p1 :  pointsOne){
        for(auto p2 :  pointsTwo){
            if (p1.x == p2.x && p1.y == p2.y) {
                //std::cout << "crossed at " << "(" << p1.x << ", " << p1.y << ")" << " distance="<< manhattanDistance(0, p1.x, 0, p1.y)<< std::endl;
                distances.push_back(manhattanDistance(0, p1.x, 0, p1.y));
                steps.push_back(pointsOne.size() + pointsTwo.size());
            }
        }
    }

    for(int i = 0; i < pointsOne.size(); i++) {
        for(int j = 0; j < pointsTwo.size(); j++){
            if (pointsOne[i].x == pointsTwo[j].x && pointsOne[i].y == pointsTwo[j].y) {
                std::cout << "crossed at " << "(" << pointsOne[i].x << ", " << pointsOne[i].y << ")" << " distance="<< manhattanDistance(0, pointsOne[i].x, 0, pointsOne[i].y)<< std::endl;
                distances.push_back(manhattanDistance(0, pointsOne[i].x, 0, pointsOne[i].y));
                steps.push_back(i + j + 2); // because i,j starts from 0 and they're supposed to start from 1 for distance purposes
            }
        }
    }

//    std::set<Point> wireOne;
//    std::set<Point> wireTwo;
//    std::vector<Point> intersectionPoints;

//
//    for (const auto p : pointsOne) {
//        wireOne.insert(p);
//    }
//
//    for (const auto p : pointsTwo) {
//        wireTwo.insert(p);
//    }
//
//    std::sort(wireOne.begin(), wireOne.end());
//    std::sort(wireTwo.begin(), wireTwo.end());
//
//    std::set_intersection(wireOne.begin(), wireOne.end(),
//                          wireTwo.begin(), wireTwo.end(),
//                          std::back_inserter(intersectionPoints));
//
//    for (const auto p: intersectionPoints) {
//        distances.push_back(manhattanDistance(0, p.x, 0, p.y));
//        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
//        std::cout << "dist= " << manhattanDistance(0, p.x, 0, p.y) << std::endl;
//    }

    std::sort(distances.begin(), distances.end());
   std::cout << "ans1= " << *min_element(distances.begin(), distances.end()) << std::endl;
   std::cout << "ans2= " << *min_element(steps.begin(), steps.end()) << std::endl;

}

std::vector<std::string> getLines(const std::string filename) {
    std::ifstream is(filename);
    std::vector<std::string> lines;
    std::string line;
    while(is.good()){
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
                for (int i = 1;i <=  p.value; i++){
                    points.push_back(Point{x - i, y});
                }
                x -= p.value;

                break;
            case 'R':
                for (int i = 1;i <=  p.value; i++){
                    points.push_back(Point{x + i, y});
                }
                x += p.value;
                break;

            case 'U':
                for (int i = 1;i <=  p.value; i++){
                    points.push_back(Point{x, y + i});
                }
                y += p.value;
                break;

            case 'D':
                for (int i = 1;i <=  p.value; i++){
                    points.push_back(Point{x, y - i});
                }
                y -= p.value;
                break;
        }
    }
    return points;
}
