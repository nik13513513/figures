using namespace std;

enum figureType {
    line,
    triangle,
    square,
    rectangle,
    circle,
};

class figure
{
public:
    figure(figureType type) { m_type = type; }
    figure();

    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    void setA(int a) { m_a = a; }
    void setB(int b) { m_b = b; }
    void setC(int c) { m_c = c; }
    void setR(int r) { m_r = r; }

    int perimeter()
    {
        int p = 0;
        switch (m_type) {
        case line:
            p = m_y - m_x;
            break;
        case triangle:
            p = m_a + m_b + m_c;
            break;
        case square:
            p = m_a * 4;
            break;
        case rectangle:
            p = (m_a + m_b) * 2;
            break;
        case circle:
            p = 2 * 3.14 * m_r;
            break;
        }
        return p;
    }

private:
    figureType m_type;
    int m_x;
    int m_y;
    int m_a;
    int m_b;
    int m_c;
    int m_r;
};

class AbstractFigure
{
public:
    AbstractFigure() = default;
    virtual int perimeter() = 0;
};

class Circle: public AbstractFigure
{
public:
    Circle(int radius):
        m_r(radius)
    {

    };

    int perimeter()override final
    {
        int p = 0;
        p = 2 * 3.14 * m_r;
        return p;
    }

private:
    int m_r{0};
};

struct lineStruct
{
    int m_x{0};
    int m_y{0};
};

struct triangleStruct
{
    int m_a{0};
    int m_b{0};
    int m_c{0};
};

struct squareStruct
{
    int m_a{0};
};

struct rectangleStruct
{
    int m_a{0};
    int m_b{0};
};

struct circleStruct
{
    int m_r{0};
};

class figureOverloadedConstructors
{
public:
    figureOverloadedConstructors(const lineStruct& l)
    {
        m_type = line;
        m_line = l;
    }

    figureOverloadedConstructors(const circleStruct& c)
    {
        m_type = circle;
        m_circle = c;
    }

    figureOverloadedConstructors(const triangleStruct& t)
    {
        m_type = triangle;
        m_triangle = t;
    }

    figureOverloadedConstructors(const squareStruct& s)
    {
        m_type = square;
        m_square = s;
    }

    figureOverloadedConstructors(const rectangleStruct& r)
    {
        m_type = rectangle;
        m_rectangle = r;
    }


    int perimeter()
    {
        int p = 0;
        switch (m_type) {
        case line:
            p = m_line.m_y - m_line.m_x;
            break;
        case triangle:
            p = m_triangle.m_a + m_triangle.m_b + m_triangle.m_c;
            break;
        case square:
            p = m_square.m_a * 4;
            break;
        case rectangle:
            p = (m_rectangle.m_a + m_rectangle.m_b) * 2;
            break;
        case circle:
            p = 2 * 3.14 * m_circle.m_r;
            break;
        }
        return p;
    }

private:
    figureType m_type;

    lineStruct m_line;
    squareStruct m_square;
    rectangleStruct m_rectangle;
    triangleStruct m_triangle;
    circleStruct m_circle;
};
