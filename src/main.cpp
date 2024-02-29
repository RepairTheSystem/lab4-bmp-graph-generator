#include <iostream>
#include "graph/Graph.h"
#include "graph/algo/FruchtermanReingold.h"
#include "image/BMP.h"
#include "math/structures.h"

// function for parsing arguments from command line
// returns true if all required parameters were specified
bool parse_arguments(int argc, char* argv[], std::string& input, std::string& output,
                     size_t& iterations, size_t& width, size_t& height, bool& log) {
    // default parameters
    width = 4096;
    height = 4096;
    iterations = 1000;
    log = true;

    bool have_input = false;
    bool have_output = false;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (i + 1 < argc && arg == "-input") {
            have_input = true;
            input = argv[i + 1];
            ++i;
            continue;
        }

        if (i + 1 < argc && arg == "-output") {
            have_output = true;
            output = argv[i + 1];
            ++i;
            continue;
        }

        if (i + 1 < argc && arg == "-width") {
            width = atoi(argv[i + 1]);
            ++i;
            continue;
        }

        if (i + 1 < argc && arg == "-height") {
            height = atoi(argv[i + 1]);
            ++i;
            continue;
        }

        if (i + 1 < argc && arg == "-iter") {
            iterations = atoi(argv[i + 1]);
            ++i;
            continue;
        }

        if (i + 1 < argc && arg == "-log") {
            log = atoi(argv[i + 1]) == 1;
            ++i;
            continue;
        }
    }

    if (!have_input) {
        std::cerr << "input should be specified" << std::endl;
        return false;
    }

    if (!have_output) {
        std::cerr << "output should be specified" << std::endl;
        return false;
    }
    return true;
}

// function for drawing graph
void draw_graph(const std::string& path, const std::vector<Point2D>& positions, const Graph& g,
                size_t width, size_t height) {
    BMP image(width, height);  // create image
    for (auto i : positions) {
        image.draw_circle(static_cast<int>(i.x), static_cast<int>(i.y), 10);  // draws vertex
    }

    // draw edges
    for (int i = 0; i < g.size(); i++) {
        for (auto j : g.get_neighbours(i)) {
            if (j > i)
                continue;
            image.draw_segment(static_cast<int>(positions[i].x), static_cast<int>(positions[i].y),
                               static_cast<int>(positions[j].x), static_cast<int>(positions[j].y));
        }
    }

    // draw number of vertex width more than 1 pixel
    for (Graph::vertexT v = 0; v < g.size(); ++v) {
        auto i = positions[v];
        image.draw_number(static_cast<int>(i.x) + 15, static_cast<int>(i.y), v);
        image.draw_number(static_cast<int>(i.x) + 15, static_cast<int>(i.y) + 1, v);
        image.draw_number(static_cast<int>(i.x) + 16, static_cast<int>(i.y), v);
    }
    image.save(path);
}

int main(int argc, char* argv[]) {
    std::string input, output;
    size_t width, height, iter;
    bool log;
    if (!parse_arguments(argc, argv, input, output, iter, width, height, log)) {
        return 0;
    }

    Graph g(input);
    FruchtermanReingold f(g, width, height);

    if (log) {
        f.run(iter, [iter](int i) {
            if (i + 1 == iter || i % 10 == 0) {
                std::cout << "Выполнено " << i + 1 << " итераций из " << iter << std::endl; 
            } // [comment] Часть выводов на англе, часть на русском
        });
    } else {
        f.run(iter);
    }

    auto pos = f.get_positions();
    draw_graph(output, pos, g, width, height);
}
