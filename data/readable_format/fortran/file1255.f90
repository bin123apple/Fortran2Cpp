program test_xersor
  implicit none

  call xersor('ABC1234', 1) ! Valid input
  call xersor('ABCDEFG', -1) ! Invalid input (represented here by negative info)
end program test_xersor

subroutine xersor(srname, info)
  implicit none
  integer            info
  character*(*)      srname

  write(*,10) srname, info
10 format(' ** On entry to ', A, ' parameter number ', I2, ' had an illegal value')

end subroutine xersor