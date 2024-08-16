subroutine rep_nrm(u,n1,n2,n3,title,kk)



use mg_data
implicit none

integer n1, n2, n3, kk
double precision u(n1,n2,n3)
character*8 title

double precision rnm2, rnmu


call norm2u3(u,n1,n2,n3,rnm2,rnmu,nx(kk),ny(kk),nz(kk))
write(*,7)kk,title,rnm2,rnmu
7    format(' Level',i2,' in ',a8,': norms =',D21.14,D21.14)

return
end
