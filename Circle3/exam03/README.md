# Exam 03

## Project Overview

Exam 03 is the third exam at 42 Seoul. It features graphics-related tasks where you implement programs to draw shapes using MiniLibX.

## Exam Tasks

### 1. micro_paint (rectangle)
Read rectangle information from a file and draw them.

### 2. mini_paint (circle)
Read circle information from a file and draw them.

## micro_paint Task

### Input Format

```
WIDTH HEIGHT BACKGROUND_CHAR
TYPE X Y WIDTH HEIGHT CHAR
TYPE X Y WIDTH HEIGHT CHAR
...
```

- **TYPE**: `r` (rectangle) or `R` (filled rectangle)
- **X, Y**: Top-left coordinates
- **WIDTH, HEIGHT**: Size
- **CHAR**: Character to draw

### Example Input (example.txt)

```
20 10 .
r 1 1 10 5 *
R 15 3 4 4 #
```

### Output

```
....................
.*********..........
.*       *...###....
.*       *...###....
.*       *...###....
.*********...###....
....................
....................
....................
....................
```

### Implementation Logic

```c
// Check if point is on rectangle border
int is_rectangle_border(float x, float y, float rect_x, float rect_y,
                         float width, float height)
{
    if ((x >= rect_x && x <= rect_x + width) &&
        (y >= rect_y && y <= rect_y + height))
    {
        if (x == rect_x || x == rect_x + width ||
            y == rect_y || y == rect_y + height)
            return (1);  // Border
    }
    return (0);
}
```

## mini_paint Task

### Input Format

```
WIDTH HEIGHT BACKGROUND_CHAR
TYPE X Y RADIUS CHAR
TYPE X Y RADIUS CHAR
...
```

- **TYPE**: `c` (circle) or `C` (filled circle)
- **X, Y**: Center coordinates
- **RADIUS**: Radius
- **CHAR**: Character to draw

### Example Input (circle.txt)

```
40 20 .
C 20 10 8 *
c 20 10 5 #
```

### Implementation Logic

```c
// Check if point is inside circle
int is_in_circle(float x, float y, float center_x, float center_y, float radius)
{
    float distance = sqrtf((x - center_x) * (x - center_x) +
                           (y - center_y) * (y - center_y));
    if (distance <= radius)
        return (1);
    return (0);
}

// Check if point is on circle border
int is_circle_border(float x, float y, float center_x, float center_y, float radius)
{
    float distance = sqrtf((x - center_x) * (x - center_x) +
                           (y - center_y) * (y - center_y));
    if (distance <= radius && distance >= radius - 1.0)
        return (1);
    return (0);
}
```

## Folder Structure

```
exam03/
├── micro_paint(rectangle)/  # Rectangle task practice
└── mini_paint(circle)/      # Circle task practice
```

## Compile

```bash
gcc -Wall -Wextra -Werror mini_paint.c -lm -o mini_paint
gcc -Wall -Wextra -Werror micro_paint.c -o micro_paint
```

## Run

```bash
./mini_paint circle.txt
./micro_paint rectangle.txt
```

## Exam Tips

1. **Parsing Caution**: Parse input format accurately
2. **Coordinate Calculation**: Be careful with floating-point precision
3. **Drawing Order**: Later shapes appear on top
4. **Error Handling**: Output "Error: Operation file corrupted\n" for invalid input

## Error Cases

- Argument count is not 1
- Cannot open file
- First line format is incorrect
- Shape information format is incorrect
