import pygame
import math
from queue import Queue

WIDTH = 800
WINDOW = pygame.display.set_mode((WIDTH, WIDTH))
pygame.display.set_caption("A* Pathfinding Algorithm Visualization")

# define colors
WHITE = (255, 255, 255)
GRAY = (200, 200, 200)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
RED = (255, 0, 0)
PASTEL_BLUE = (173, 216, 230)
PASTEL_PINK = (255, 182, 193)
PURPLE = (128, 0, 128)


class Node:
    def __init__(self, row, col, width, total_rows):
        self.row = row
        self.col = col
        self.x = row * width
        self.y = col * width
        self.color = WHITE
        self.neighbors = []
        self.width = width
        self.total_rows = total_rows

    def get_pos(self):
        return self.row, self.col

    def is_closed(self):
        return self.color == RED

    def is_open(self):
        return self.color == GREEN

    def is_wall(self):
        return self.color == BLACK

    def is_start(self):
        return self.color == PASTEL_BLUE

    def is_end(self):
        return self.color == PASTEL_PINK

    def erase(self):
        self.color = WHITE

    def changeClosed(self):
        self.color = RED

    def changeOpened(self):
        self.color = GREEN

    def changeToWall(self):
        self.color = BLACK

    def changeToStart(self):
        self.color = PASTEL_BLUE

    def changeToEnd(self):
        self.color = PASTEL_PINK

    def genPath(self):
        self.color = PURPLE

    def draw(self, win):
        pygame.draw.rect(win, self.color, (self.x, self.y, self.width, self.width))

    def update_neighbors(self, grid):
        self.neighbors = []
        # DOWN
        if (
            self.row < self.total_rows - 1
            and not grid[self.row + 1][self.col].is_wall()
        ):
            self.neighbors.append(grid[self.row + 1][self.col])

        # UP
        if self.row > 0 and not grid[self.row - 1][self.col].is_wall():
            self.neighbors.append(grid[self.row - 1][self.col])

        # RIGHT
        if (
            self.col < self.total_rows - 1
            and not grid[self.row][self.col + 1].is_wall()
        ):
            self.neighbors.append(grid[self.row][self.col + 1])

        # LEFT
        if self.col > 0 and not grid[self.row][self.col - 1].is_wall():
            self.neighbors.append(grid[self.row][self.col - 1])


def heuristic(curNode, other):
    x1, y1 = curNode
    x2, y2 = other
    return abs(x1 - x2) + abs(y1 - y2)


def show_path(addressed, current, draw):
    while current in addressed:
        current = addressed[current]
        current.genPath()


def algorithm(draw, grid, start, end):
    # branch and bound algorithm
    count = 0
    open_set = Queue()
    open_set.put((0, count, start))
    addressed = {}
    g_score = {node: float("inf") for row in grid for node in row}
    g_score[start] = 0
    f_score = {node: float("inf") for row in grid for node in row}
    f_score[start] = heuristic(start.get_pos(), end.get_pos())

    open_set_hash = {start}
    while not open_set.empty():
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()


def make_grid(rows, width):
    grid = []
    gap = width // rows
    for i in range(rows):
        grid.append([])
        for j in range(rows):
            node = Node(i, j, gap, rows)
            grid[i].append(node)
    return grid


def draw_grid(win, rows, width):
    gap = width // rows
    for y in range(rows):
        pygame.draw.line(win, GRAY, (0, y * gap), (width, y * gap))
        for x in range(rows):
            pygame.draw.line(win, GRAY, (x * gap, 0), (x * gap, width))


def draw(win, grid, rows, width):
    win.fill(WHITE)

    for row in grid:
        for node in row:
            node.draw(win)
    draw_grid(win, rows, width)
    pygame.display.update()


def get_clicked_pos(pos, rows, width):
    gap = width // rows
    y, x = pos

    row = y // gap
    col = x // gap

    return row, col


def draw_outer_barrier(win, grid, rows, width):
    for i in range(rows):
        for j in range(rows):
            if i == 0 or i == rows - 1 or j == 0 or j == rows - 1:
                node = grid[i][j]
                node.changeToWall()
                node.draw(win)
    pygame.display.update()


def program(win, width):
    ROWS = 50
    grid = make_grid(ROWS, width)
    start = None
    end = None

    run = True
    started = False

    draw_outer_barrier(win, grid, ROWS, width)
    while run:
        draw(win, grid, ROWS, WIDTH)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
            if started:
                continue
            if pygame.mouse.get_pressed()[0]:  # LEFT
                pos = pygame.mouse.get_pos()
                row, col = get_clicked_pos(pos, ROWS, WIDTH)
                node = grid[row][col]
                if not start and node != end:
                    start = node
                    start.changeToStart()

                elif not end and node != start:
                    end = node
                    end.changeToEnd()

                elif node != end and node != start:
                    node.changeToWall()

            elif pygame.mouse.get_pressed()[2]:  # RIGHT
                pos = pygame.mouse.get_pos()
                row, col = get_clicked_pos(pos, ROWS, WIDTH)
                node = grid[row][col]
                node.erase()

                if node == start:
                    start = None
                elif node == end:
                    end = None
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and not started:
                    for row in grid:
                        for node in row:
                            node.update_neighbors(grid)

                    algorithm(lambda: draw(win, grid, ROWS, WIDTH), grid, start, end)

                elif event.key == pygame.K_r:
                    started = False
                    start = None
                    end = None
                    grid = make_grid(ROWS, width)
                    draw_outer_barrier(win, grid, ROWS, width)

    pygame.quit()


if __name__ == "__main__":
    program(WINDOW, WIDTH)
