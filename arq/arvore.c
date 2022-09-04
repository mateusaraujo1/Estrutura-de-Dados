void draw(int n, double len, double x, double y) {
    double x0, x1, y0, y1;
    if (n > 0)
    {
        x0 = x - len/2;
        x1 = x + len/2;
        y0 = y - len/2;
        y1 = y + len/2;

        drawLine(x0, y, x1, y);
        drawLine(x0, y0, x0, y1);
        drawLine(x1, y0, x1, y1);

        draw(n-1, len/2, x0, y0);
        draw(n-1, len/2, x0, y1);
        draw(n-1, len/2, x1, y0);
        draw(n-1, len/2, x1, y1);
    }
}