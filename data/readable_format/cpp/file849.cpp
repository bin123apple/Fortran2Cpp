void check(int &min, int &max, int i) {
    if (min < 1) min = 1;
    if (max > i) max = i;
    if (max < min) max = min;
}