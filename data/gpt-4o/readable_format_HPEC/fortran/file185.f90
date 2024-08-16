subroutine showall(z,n1,n2,n3)


implicit none


integer n1,n2,n3,i1,i2,i3
double precision z(n1,n2,n3)
integer m1, m2, m3

m1 = min(n1,18)
m2 = min(n2,14)
m3 = min(n3,18)

write(*,*)'  '
do  i3=1,m3
do  i1=1,m1
write(*,6)(z(i1,i2,i3),i2=1,m2)
enddo
write(*,*)' - - - - - - - '
enddo
write(*,*)'  '
6    format(15f6.3)

return
end
