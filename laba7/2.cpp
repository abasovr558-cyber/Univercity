#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;
using namespace sf;

// конфигурация игрового поля
const int GRID_SIZE = 10;
const int CELL_SIZE = 80;
const int WINDOW_SIZE = GRID_SIZE * CELL_SIZE;

// возможные состояния каждой клетки
enum CellType {
    EMPTY,    // свободный проход
    OBSTACLE, // препятствие
    START,    // точка входа
    END,      // точка выхода
    PATH,     // итоговый маршрут
    VISITED   // просмотренные алгоритмом клетки
};

// структура ячейки с данными для навигации
struct Cell {
    int x, y;
    CellType type;

    // параметры a*: g - стоимость от старта, h - эвристика до цели, f = g + h
    int f, g, h;
    Cell* parent; // указатель на предыдущую ячейку для восстановления пути
    int weight;   // "стоимость" прохода через клетку

    Cell(int x, int y) : x(x), y(y), type(EMPTY), f(0), g(0), h(0), parent(nullptr), weight(1) {}

    bool operator==(const Cell& other) const {
        return x == other.x && y == other.y;
    }
};

// эвристическая функция: манхэттенское расстояние
int heuristic(const Cell& a, const Cell& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// проверка нахождения координат внутри границ сетки
bool isValid(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE);
}

// инициализация двумерного массива ячеек
std::vector<std::vector<Cell>> make_grid(int GRID_SIZE) {
    vector<vector<Cell>> grid;
    for (int x = 0; x < GRID_SIZE; x++) {
        std::vector<Cell> row;
        for (int y = 0; y < GRID_SIZE; y++) {
            row.emplace_back(x, y);
        }
        grid.push_back(row);
    }
    return grid;
}

// визуализация сетки в окне sfml
void draw_grid(sf::RenderWindow& win, std::vector<std::vector<Cell>>& grid) {
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) return;

    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            RectangleShape cell(Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
            cell.setPosition(i * CELL_SIZE, j * CELL_SIZE);

            // выбор цвета в зависимости от состояния клетки
            switch (grid[i][j].type) {
            case EMPTY:    cell.setFillColor(Color::White); break;
            case OBSTACLE: cell.setFillColor(Color::Black); break;
            case START:    cell.setFillColor(Color::Green); break;
            case END:      cell.setFillColor(Color::Red); break;
            case PATH:     cell.setFillColor(Color::Blue); break;
            case VISITED:  cell.setFillColor(Color::Cyan); break;
            }

            win.draw(cell);

            // отображение веса клетки
            if (grid[i][j].weight) {
                sf::Text text;
                text.setFont(font);
                text.setString(std::to_string(grid[i][j].weight));
                text.setCharacterSize(12);
                text.setFillColor(sf::Color::Black);

                // центрирование текста
                sf::FloatRect textRect = text.getLocalBounds();
                text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
                text.setPosition(i * CELL_SIZE + CELL_SIZE / 2.0f, j * CELL_SIZE + CELL_SIZE / 2.0f);
                win.draw(text);
            }
        }
    }
}

// компаратор для приоритетной очереди
struct CompareCells {
    bool operator()(Cell const* c1, Cell const* c2) {
        return c1->f > c2->f;
    }
};

// восстановление пути от финиша к старту
void reconstruct_path(Cell* current) {
    if (current && current->type == END) {
        current = current->parent;
    }
    while (current != nullptr && current->type != START) {
        current->type = PATH;
        current = current->parent;
    }
}

// очистка результатов предыдущего поиска
void reload(std::vector<std::vector<Cell>>& grid) {
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            grid[x][y].parent = nullptr;
            grid[x][y].g = 999999;
            if (grid[x][y].type == PATH || grid[x][y].type == VISITED) {
                grid[x][y].type = EMPTY;
            }
        }
    }
}

// алгоритм поиска пути a*
void a_star_algorithm(std::vector<std::vector<Cell>>& grid, Cell* start, Cell* end) {
    reload(grid);

    priority_queue<Cell*, vector<Cell*>, CompareCells> open_list;
    vector<vector<Cell*>> closed_list(GRID_SIZE, vector<Cell*>(GRID_SIZE, nullptr));

    start->g = 0;
    start->f = heuristic(*start, *end);
    open_list.push(start);

    while (!open_list.empty()) {
        Cell* n = open_list.top();
        open_list.pop();

        // если дошли до цели — строим путь
        if (*n == *end) {
            reconstruct_path(&grid[end->x][end->y]);
            return;
        }

        // пропуск уже обработанных ячеек
        if (closed_list[n->x][n->y] != nullptr) continue;
        closed_list[n->x][n->y] = n;

        if (n->type == EMPTY) n->type = VISITED;

        // направления движения
        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };

        for (int i = 0; i < 4; i++) {
            int nx = n->x + dx[i];
            int ny = n->y + dy[i];

            if (!isValid(nx, ny) || grid[nx][ny].type == OBSTACLE || closed_list[nx][ny] != nullptr) {
                continue;
            }

            Cell* m = &grid[nx][ny];
            int tentative_g = n->g + m->weight;

            // если найден более короткий путь
            if (tentative_g < m->g) {
                m->parent = n;
                m->g = tentative_g;
                m->h = heuristic(*m, *end);
                m->f = m->g + m->h;
                open_list.push(m);
            }
        }
    }
}

// установка фиксированной карты
void generate_normal_grid(vector<vector<Cell>>& grid) {
    grid[0][7].type = START;
    grid[GRID_SIZE - 1][GRID_SIZE - 1].type = END;

    vector<Vector2i> obstacles = {
        {7, 0},
        {2, 1}, {8, 1},
        {0, 2}, {1, 2}, {5, 2}, {8, 2}, {9, 2},
        {0, 3}, {7, 3}, {8, 3},
        {5, 4}, {7, 4}, {8, 4},
        {2, 5}, {4, 5},
        {1, 6}, {2, 6}, {3, 6},
        {1, 7}, {6, 7}, {7, 7}, {8, 7},
        {3, 8}, {5, 8},
        {0,9}, {3,9}, {5,9}
    };

    for (const auto& p : obstacles) {
        if (p.x < GRID_SIZE && p.y < GRID_SIZE) grid[p.x][p.y].type = OBSTACLE;
    }
}

// генерация случайной карты
void generate_random_grid(vector<vector<Cell>>& grid) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    uniform_int_distribution<> pos(0, GRID_SIZE - 1);
    uniform_int_distribution<> weight_gen(1, 100);

    grid[pos(gen)][pos(gen)].type = START;
    grid[pos(gen)][pos(gen)].type = END;

    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            if (grid[x][y].type != START && grid[x][y].type != END) {
                if (dis(gen) < 0.3) {
                    grid[x][y].type = OBSTACLE;
                }
                else {
                    grid[x][y].type = EMPTY;
                    grid[x][y].weight = weight_gen(gen);
                }
            }
        }
    }
}

int main() {
    RenderWindow window(VideoMode(WINDOW_SIZE, WINDOW_SIZE), "a* pathfinding");
    vector<vector<Cell>> grid = make_grid(GRID_SIZE);
    generate_normal_grid(grid);

    Cell* start = nullptr, * end = nullptr;
    for (auto& row : grid) {
        for (auto& cell : row) {
            if (cell.type == START) start = &grid[cell.x][cell.y];
            if (cell.type == END) end = &grid[cell.x][cell.y];
        }
    }

    // основной цикл программы
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();

            if (event.type == Event::KeyPressed) {
                // запуск алгоритма по пробелу
                if (event.key.code == Keyboard::Space) {
                    a_star_algorithm(grid, start, end);
                }
                // регенерация по клавише r
                if (event.key.code == Keyboard::R) {
                    start->type = EMPTY;
                    end->type = EMPTY;
                    generate_random_grid(grid);
                    for (auto& row : grid) {
                        for (auto& cell : row) {
                            if (cell.type == START) start = &grid[cell.x][cell.y];
                            if (cell.type == END) end = &grid[cell.x][cell.y];
                        }
                    }
                }
            }
        }

        window.clear();
        draw_grid(window, grid);
        window.display();
    }
    return 0;
}