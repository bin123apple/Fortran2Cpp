float PA_FROM_MB(float MB, float BADDATA) {
    if (MB != BADDATA) {
        return MB * 100.0f;
    } else {
        return BADDATA;
    }
}