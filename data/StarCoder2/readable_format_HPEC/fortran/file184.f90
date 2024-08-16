subroutine bubble( ten, j1, j2, j3, m, ind )


implicit none


integer m, ind, j1( m, 0:1 ), j2( m, 0:1 ), j3( m, 0:1 )
double precision ten( m, 0:1 )
double precision temp
integer i, j_temp

if( ind .eq. 1 )then

do  i=1,m-1
if( ten(i,ind) .gt. ten(i+1,ind) )then

temp = ten( i+1, ind )
ten( i+1, ind ) = ten( i, ind )
ten( i, ind ) = temp

j_temp           = j1( i+1, ind )
j1( i+1, ind ) = j1( i,   ind )
j1( i,   ind ) = j_temp

j_temp           = j2( i+1, ind )
j2( i+1, ind ) = j2( i,   ind )
j2( i,   ind ) = j_temp

j_temp           = j3( i+1, ind )
j3( i+1, ind ) = j3( i,   ind )
j3( i,   ind ) = j_temp

else
return
endif
enddo

else

do  i=1,m-1
if( ten(i,ind) .lt. ten(i+1,ind) )then

temp = ten( i+1, ind )
ten( i+1, ind ) = ten( i, ind )
ten( i, ind ) = temp

j_temp           = j1( i+1, ind )
j1( i+1, ind ) = j1( i,   ind )
j1( i,   ind ) = j_temp

j_temp           = j2( i+1, ind )
j2( i+1, ind ) = j2( i,   ind )
j2( i,   ind ) = j_temp

j_temp           = j3( i+1, ind )
j3( i+1, ind ) = j3( i,   ind )
j3( i,   ind ) = j_temp

else
return
endif
enddo

endif

return
end
