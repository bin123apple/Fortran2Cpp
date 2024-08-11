class MathsUtils {
public:
    // Function cds1
    static int cds1(int nPoints, int dim) {
        if (dim == 1) {
            return nPoints - 1;
        } else {
            return nPoints;
        }
    }
    
    // Function cds2
    static int cds2(int nPoints, int dim) {
        if (dim == 2) {
            return nPoints - 1;
        } else {
            return nPoints;
        }
    }
};