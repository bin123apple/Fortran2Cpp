void print_array(int cz, int cxm, int cym, float bza[], float ex[], float ey[], float hz[]){
 for (int i = 0; i < cz+1; i++){
 for (int j = 0; j < cym+1; j++){
 for (int k = 0; k < cxm+1; k++){
 printf("%f", bza[k + (j * cxm) + (i * cym*cxm)]);
 printf("%f", ex[k + (j * cxm) + (i * cym*cxm)]);
 printf("%f", ey[k + (j * cxm) + (i * cym*cxm)]);
 printf("%f", hz[k + (j * cxm) + (i * cym*cxm)]);
 if ((((i * cxm) + j) % 20) == 0){
 printf("\n");
 }
 }
 }
 printf("\n");
 }
}
