#include <iostream>
#include <cmath> // for std::round
#include <cstring> // for std::memset

void edtoir(const short int* in, int* out, int npix, int nlin, int inval, int blank, float bscale, float bzero) {
    float factor;
    int offset;
    
    if (bscale != 0.0f) {
        offset = std::round(bzero / bscale);
        factor = 1.0f;
    } else {
        offset = 1;
        factor = 0.0f;
    }
    
    for (int lin = 0; lin < nlin; ++lin) {
        for (int pix = 0; pix < npix; ++pix) {
            int index = lin * npix + pix;
            if (in[index] != inval) {
                out[index] = static_cast<int>(factor * in[index] + offset);
            } else {
                out[index] = blank;
            }
        }
    }
}

int main() {
    const int npix = 3, nlin = 3;
    short int in[npix * nlin];
    int out[npix * nlin];
    const int inval = -999, blank = -1;
    float bscale = 1.0f, bzero = 0.0f;

    // Initialize the input array
    std::fill_n(in, npix*nlin, inval);

    edtoir(in, out, npix, nlin, inval, blank, bscale, bzero);
    std::cout << "Test Case 1: bscale=1.0, bzero=0.0" << std::endl;
    for (int lin = 0; lin < nlin; ++lin) {
        for (int pix = 0; pix < npix; ++pix) {
            std::cout << "arr[" << lin << "][" << pix << "] = " << out[lin * npix + pix] << std::endl;
        }
    }

    return 0;
}