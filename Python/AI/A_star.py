import pygame
import math
import random
from queue import PriorityQueue, Queue

pygame.init()

WIDTH = 800
HEIGHT = 800
WINDOW = pygame.display.set_mode((WIDTH, HEIGHT))
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


def bfs_algorithm(draw, grid, start, end):
    """Breadth-First Search pathfinding."""
    queue = Queue()
    queue.put(start)
    came_from = {}
    visited = {start}

    while not queue.empty():
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()

        current = queue.get()

        if current == end:
            show_path(came_from, end, draw)
            end.changeToEnd()
            start.changeToStart()
            return True

        for neighbor in current.neighbors:
            if neighbor not in visited:
                visited.add(neighbor)
                came_from[neighbor] = current
                queue.put(neighbor)
                neighbor.changeOpened()

        draw()
        if current != start and current != end:
            current.changeClosed()

    return False


def branch_and_bound_algorithm(draw, grid, start, end):
    """Branch and Bound pathfinding with cost estimation."""
    # Calculate heuristic distance to end for all nodes
    queue = [(0, start, [start])]  # (cost, current_node, path)
    best_cost = {node: float("inf") for row in grid for node in row}
    best_cost[start] = 0
    visited = set()

    while queue:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()

        # Sort by cost to explore promising paths first
        queue.sort(key=lambda x: x[0] + heuristic(x[1].get_pos(), end.get_pos()))
        cost, current, path = queue.pop(0)

        if current in visited:
            continue

        visited.add(current)
        current.changeOpened()
        draw()

        if current == end:
            # Reconstruct path
            for node in path:
                if node != start and node != end:
                    node.genPath()
            end.changeToEnd()
            start.changeToStart()
            draw()
            return True

        for neighbor in current.neighbors:
            new_cost = cost + 1
            if neighbor not in visited and new_cost < best_cost[neighbor]:
                best_cost[neighbor] = new_cost
                new_path = path + [neighbor]
                queue.append((new_cost, neighbor, new_path))

        draw()
        if current != start and current != end:
            current.changeClosed()

    return False


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
    """Generate random maze using simple recursive backtracking."""
    import sys

    sys.setrecursionlimit(10000)

    # Mark all cells as walls first
    for row in grid:
        for node in row:
            node.changeToWall()

    visited = set()

    def carve_path(row, col):
        if (row, col) in visited:
            return
        visited.add((row, col))
        grid[row][col].erase()  # Mark as path

        directions = [(0, 2), (2, 0), (0, -2), (-2, 0)]
        random.shuffle(directions)

        for dr, dc in directions:
            new_row, new_col = row + dr, col + dc
            if 0 < new_row < rows - 1 and 0 < new_col < rows - 1:
                if (new_row, new_col) not in visited:
                    # Carve the wall between current and next cell
                    grid[row + dr // 2][col + dc // 2].erase()
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
    pygame.display.flip()


def get_clicked_pos(pos, rows, width):
    gap = width // rows
    y, x = pos

    row = y // gap
    col = x // gap

    return row, col


def program(win, width):
    ROWS = 30  # Reduced from 50 for faster generation
    grid = make_grid(ROWS, width)

    # Generate random maze
    print("Generating maze...")
    generate_maze(grid, ROWS)
    print("Maze generated!")

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

    mode = None
    run = True

    while run:
        draw(win, grid, ROWS, WIDTH)

        # Display mode selection text overlay
        if mode is None:
            font = pygame.font.Font(None, 36)
            text1 = font.render("Press 1 for Branch & Bound", True, BLACK)
            text2 = font.render("Press 2 for A*", True, BLACK)
            win.blit(text1, (WIDTH // 2 - 150, HEIGHT // 2 - 50))
            win.blit(text2, (WIDTH // 2 - 100, HEIGHT // 2 + 10))
            pygame.display.flip()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_1:
                    mode = 1  # BFS mode
                elif event.key == pygame.K_2:
                    mode = 2  # A* mode

                if event.key == pygame.K_SPACE and start and end and mode:
                    for row in grid:
                        for node in row:
                            node.update_neighbors(grid)

                    if mode == 1:
                        branch_and_bound_algorithm(
                            lambda: draw(win, grid, ROWS, WIDTH), grid, start, end
                        )
                    elif mode == 2:
                        algorithm(
                            lambda: draw(win, grid, ROWS, WIDTH), grid, start, end
                        )
                    mode = None

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
                    mode = None

    pygame.quit()


if __name__ == "__main__":
    program(WINDOW, WIDTH)
