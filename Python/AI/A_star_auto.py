import pygame
import math
import random
from queue import PriorityQueue

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

        # LEFT-UP
        if (
            self.row > 0
            and self.col > 0
            and not grid[self.row - 1][self.col - 1].is_wall()
        ):
            self.neighbors.append(grid[self.row - 1][self.col - 1])

        # LEFT-DOWN
        if (
            self.row < self.total_rows - 1
            and self.col > 0
            and not grid[self.row + 1][self.col - 1].is_wall()
        ):
            self.neighbors.append(grid[self.row + 1][self.col - 1])

        # RIGHT-UP
        if (
            self.row > 0
            and self.col < self.total_rows - 1
            and not grid[self.row - 1][self.col + 1].is_wall()
        ):
            self.neighbors.append(grid[self.row - 1][self.col + 1])

        # RIGHT-DOWN
        if (
            self.row < self.total_rows - 1
            and self.col < self.total_rows - 1
            and not grid[self.row + 1][self.col + 1].is_wall()
        ):
            self.neighbors.append(grid[self.row + 1][self.col + 1])

    def compare(self, other):
        return False


def heuristic(curNode, other):
    x1, y1 = curNode
    x2, y2 = other
    return abs(x1 - x2) + abs(y1 - y2)


def show_path(addressed, current, draw):
    while current in addressed:
        current = addressed[current]
        current.genPath()
        draw()


def algorithm(draw, grid, start, end):
    count = 0
    open_set = PriorityQueue()
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

        current = open_set.get()[2]
        open_set_hash.remove(current)

        if current == end:
            show_path(addressed, end, draw)
            end.changeToEnd()
            start.changeToStart()
            return True

        for neighbor in current.neighbors:
            temp_g_score = g_score[current] + 1

            if temp_g_score < g_score[neighbor]:
                addressed[neighbor] = current
                g_score[neighbor] = temp_g_score
                f_score[neighbor] = temp_g_score + heuristic(
                    neighbor.get_pos(), end.get_pos()
                )

                if neighbor not in open_set_hash:
                    count += 1
                    open_set.put((f_score[neighbor], count, neighbor))
                    open_set_hash.add(neighbor)
                    neighbor.changeOpened()
        draw()
        if current != start:
            current.changeClosed()


def make_grid(rows, width):
    grid = []
    gap = width // rows
    for i in range(rows):
        grid.append([])
        for j in range(rows):
            node = Node(i, j, gap, rows)
            grid[i].append(node)
    return grid


def generate_maze(grid, rows):
    """Generate random maze using recursive backtracking."""
    # Mark all cells as walls first
    for row in grid:
        for node in row:
            node.changeToWall()

    # Start from (1, 1) and carve paths
    def carve_path(row, col):
        grid[row][col].erase()  # Mark as path
        directions = [(0, 2), (2, 0), (0, -2), (-2, 0)]  # Move 2 cells at a time
        random.shuffle(directions)
        for dr, dc in directions:
            new_row, new_col = row + dr, col + dc
            if 0 < new_row < rows - 1 and 0 < new_col < rows - 1:
                # Carve the wall between current and next cell
                grid[row + dr // 2][col + dc // 2].erase()
                if grid[new_row][new_col].is_wall():
                    carve_path(new_row, new_col)

    # Start maze generation from (1, 1)
    carve_path(1, 1)


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


def program(win, width):
    ROWS = 50
    grid = make_grid(ROWS, width)

    # Generate random maze
    generate_maze(grid, ROWS)

    # Find random start and end positions on non-wall cells
    start = None
    end = None
    path_cells = []
    for row in grid:
        for node in row:
            if not node.is_wall():
                path_cells.append(node)

    if len(path_cells) >= 2:
        start = random.choice(path_cells)
        path_cells.remove(start)
        end = random.choice(path_cells)
        start.changeToStart()
        end.changeToEnd()

    run = True

    while run:
        draw(win, grid, ROWS, WIDTH)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and start and end:
                    for row in grid:
                        for node in row:
                            node.update_neighbors(grid)

                    algorithm(lambda: draw(win, grid, ROWS, WIDTH), grid, start, end)

                elif event.key == pygame.K_r:
                    grid = make_grid(ROWS, width)
                    generate_maze(grid, ROWS)
                    path_cells = []
                    for row in grid:
                        for node in row:
                            if not node.is_wall():
                                path_cells.append(node)
                    if len(path_cells) >= 2:
                        start = random.choice(path_cells)
                        path_cells.remove(start)
                        end = random.choice(path_cells)
                        start.changeToStart()
                        end.changeToEnd()

    pygame.quit()


if __name__ == "__main__":
    program(WINDOW, WIDTH)
