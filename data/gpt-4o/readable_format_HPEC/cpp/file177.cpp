void add() {
    extern bool timeron;
    extern double u[5][grid_points[0]-2][grid_points[1]-2][grid_points[2]-2];
    extern double rhs[5][grid_points[0]-2][grid_points[1]-2][grid_points[2]-2];

    if (timeron) timer_start(t_add);
    for (int k = 0; k < grid_points[2]-2; k++) {
        for (int j = 0; j < grid_points[1]-2; j++) {
            for (int i = 0; i < grid_points[0]-2; i++) {
                for (int m = 0; m < 5; m++) {
                    u[m][i][j][k] += rhs[m][i][j][k];
                }
            }
        }
    }
    if (timeron) timer_stop(t_add);
}
