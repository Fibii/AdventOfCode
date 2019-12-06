#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

std::map<std::string, std::vector<std::string>> getTree(std::string title);
int getOrbitCount(std::map<std::string, std::vector<std::string>> tree, std::string node, int depth);
std::vector<std::string> getPath(std::map<std::string, std::vector<std::string>> tree, std::string ofNode);

int main() {
    std::map<std::string, std::vector<std::string>> tree = getTree("day6.txt");
    int count = getOrbitCount(tree, "COM", 0) ;

    std::cout << "ans1=" << count << std::endl;

    auto you = getPath(tree, "YOU");
    auto santa = getPath(tree, "SAN");
    while(you[0] == santa[0]) {
        you.erase(you.begin());
        santa.erase(santa.begin());
    }

    std::cout << "ans2=" << you.size() + santa.size() - 2 << std::endl;

}

std::map<std::string, std::vector<std::string>> getTree(std::string title) {
    std::map<std::string, std::vector<std::string>> tree;
    std::ifstream is(title);

    while (is.good()) {
        std::string line;
        getline(is, line, '\n');
        std::string key = line.substr(0, 3);
        std::string value = line.substr(4, 6);
        tree[key].push_back(value);
    }

    is.close();

    return tree;

}

int getOrbitCount(std::map<std::string, std::vector<std::string>> tree, std::string node, int depth) {
    int sum = depth;
    for (const auto neighbor : tree[node]) {
        sum += getOrbitCount(tree, neighbor, depth + 1);
    }
    return sum;
}


std::vector<std::string> getPath(std::map<std::string, std::vector<std::string>> tree, std::string ofNode) {
    std::vector<std::string> path;
    if(ofNode == "COM") {
        path.push_back("COM");
    } else {
        // iterate over all nodes and if some node contains ofNode then add ofNode to path recursively
        for(const auto t: tree) {
            std::vector<std::string> nodes = tree[t.first];
            if (std::find(nodes.begin(), nodes.end(), ofNode) != nodes.cend()) {
                path = getPath(tree, t.first);
                path.push_back(ofNode);
            }
        }
    }
    return path;
}