void cdiv(float ar, float ai, float br, float bi, float &cr, float &ci) {
    float s, ars, ais, brs, bis;
    s = fabs(br) + fabs(bi);
    ars = ar / s;
    ais = ai / s;
    brs = br / s;
    bis = bi / s;
    s = brs*brs + bis*bis;
    cr = (ars*brs + ais*bis) / s;
    ci = (ais*brs - ars*bis) / s;
}