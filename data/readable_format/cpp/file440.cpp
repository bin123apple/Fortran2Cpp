// Assuming Y, TILTC, and TILTS are appropriately defined arrays and EKK, I are defined and initialized appropriately
Y[0] = Y[0] + EKK * TILTC[I-1]; // Adjusted for 0-based indexing, assuming I is appropriately adjusted for 0-based indexing
Y[1] = Y[1] + EKK * TILTS[I-1]; // Adjusted for 0-based indexing